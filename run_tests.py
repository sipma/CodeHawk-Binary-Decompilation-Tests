#!/usr/bin/env python3
"""Run the test scripts of the lifting test directories in parallel.

Each subdirectory of <suite>/liftings is processed by one worker. Within a
directory the selected scripts (default: test.*.notime.pass.sh) are run
sequentially, in sorted order, with bash (not zsh: the scripts rely on IFS
word-splitting of the multi-valued variables exported by vars.sh), with the
lifting directory as working directory. A directory stops at its first
failing script (later scripts depend on the output of earlier ones), unless
--keep-going is given.

The output of each script is written to <liftingdir>/logs/<script>.log.

The scripts invoke chkx, which must be on PATH, with CodeHawk-Binary on
PYTHONPATH; alternatively, give the CodeHawk-Binary directory with --chb.

Examples:
  ./run_tests.py openssl/6f891f26
  ./run_tests.py openssl/6f891f26 -j 8 -d crypto__x509__ crypto__evp__names
  ./run_tests.py busybox/8b996feb --pattern test.10.check-errors.sh
"""

import argparse
import concurrent.futures
import fnmatch
import os
import shutil
import subprocess
import sys
import time

from pathlib import Path
from typing import List, NamedTuple, Optional, Tuple

import suiteinfo


class ScriptResult(NamedTuple):
    script: str
    returncode: int
    seconds: float


class DirResult(NamedTuple):
    name: str
    results: List[ScriptResult]
    skipped: List[str]
    analyzed: Optional[int]
    lifted: Optional[int]

    @property
    def passed(self) -> bool:
        return not self.skipped and all(r.returncode == 0 for r in self.results)


def make_env(chb: Optional[str]) -> dict:
    """Return the environment, adding CodeHawk-Binary (if given) when chkx is
    not on PATH."""
    env = dict(os.environ)
    if chb is not None and shutil.which("chkx", path=env.get("PATH")) is None:
        env["PATH"] = os.path.join(chb, "chb", "cmdline") + os.pathsep + env.get("PATH", "")
        env["PYTHONPATH"] = (
            chb + os.pathsep + env["PYTHONPATH"] if env.get("PYTHONPATH") else chb)
    return env


def dir_selected(name: str, patterns: List[str]) -> bool:
    if not patterns:
        return True
    return any(
        fnmatch.fnmatch(name, g) if any(c in g for c in "*?[")
        else name.startswith(g)
        for g in patterns)


def short(script: str) -> str:
    """Return the script name without .notime.pass.sh / .sh, for display."""
    for suffix in (".notime.pass.sh", ".sh"):
        if script.endswith(suffix):
            return script[:-len(suffix)]
    return script


def select_scripts(d: Path, pattern: str) -> List[str]:
    return sorted(
        f.name for f in d.iterdir()
        if f.is_file() and fnmatch.fnmatch(f.name, pattern))


def fn_counts(d: Path) -> Tuple[Optional[int], Optional[int]]:
    """Return the number of functions analyzed and lifted, from vars.sh."""
    try:
        fs = suiteinfo.function_sets(d)
    except suiteinfo.VarsError:
        return (None, None)
    return (len(fs.analyzed), len(fs.lifted))


def run_dir(
        d: Path, scripts: List[str], env: dict, keepgoing: bool,
        timeout: Optional[float]) -> DirResult:
    logdir = d / "logs"
    logdir.mkdir(exist_ok=True)
    results: List[ScriptResult] = []
    for (i, script) in enumerate(scripts):
        start = time.time()
        with open(logdir / (script + ".log"), "w") as log:
            try:
                rc = subprocess.run(
                    ["bash", script], cwd=d, env=env, stdout=log,
                    stderr=subprocess.STDOUT, timeout=timeout).returncode
            except subprocess.TimeoutExpired:
                log.write(f"\n*** timeout after {timeout} seconds\n")
                rc = -1
        results.append(ScriptResult(script, rc, time.time() - start))
        if rc != 0 and not keepgoing:
            return DirResult(d.name, results, scripts[i + 1:], *fn_counts(d))
    return DirResult(d.name, results, [], *fn_counts(d))


def main() -> int:
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("suite", help="suite directory, containing liftings/")
    parser.add_argument(
        "-j", "--jobs", type=int, default=os.cpu_count(),
        help="number of directories processed in parallel (default: %(default)s)")
    parser.add_argument(
        "-p", "--pattern", default="test.*.notime.pass.sh",
        help="glob selecting the scripts to run (default: %(default)s)")
    parser.add_argument(
        "-d", "--dirs", nargs="*", default=[],
        help=("restrict to these lifting directories: glob patterns, or a "
              "plain name, which is matched as a prefix"))
    parser.add_argument(
        "-k", "--keep-going", action="store_true",
        help="continue with the next script in a directory after a failure")
    parser.add_argument(
        "-t", "--timeout", type=float, default=None,
        help="timeout per script, in seconds")
    parser.add_argument(
        "--chb", default=None,
        help=("CodeHawk-Binary directory, added to PATH/PYTHONPATH if chkx is "
              "not on PATH"))
    args = parser.parse_args()

    liftings = Path(args.suite).resolve() / "liftings"
    if not liftings.is_dir():
        print(f"Directory not found: {liftings}", file=sys.stderr)
        return 2

    env = make_env(args.chb)
    if shutil.which("chkx", path=env["PATH"]) is None:
        print("chkx not found: add CodeHawk-Binary/chb/cmdline to PATH and "
              "CodeHawk-Binary to PYTHONPATH, or use --chb", file=sys.stderr)
        return 2

    dirs = [
        p for p in sorted(liftings.iterdir())
        if p.is_dir() and dir_selected(p.name, args.dirs)]
    if not dirs:
        print(f"No lifting directories matching {' '.join(args.dirs)}",
              file=sys.stderr)
        return 2

    work = []
    for d in dirs:
        scripts = select_scripts(d, args.pattern)
        if scripts:
            work.append((d, scripts))
    if not work:
        print(f"No scripts matching {args.pattern} found in the selected "
              "directories", file=sys.stderr)
        return 2

    print(f"Running {sum(len(s) for (_, s) in work)} scripts in {len(work)} "
          f"directories with {args.jobs} workers")
    start = time.time()
    dirresults: List[DirResult] = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        futures = [
            pool.submit(run_dir, d, s, env, args.keep_going, args.timeout)
            for (d, s) in work]
        for f in concurrent.futures.as_completed(futures):
            r = f.result()
            dirresults.append(r)
            failed = [short(x.script) for x in r.results if x.returncode != 0]
            status = "PASS" if r.passed else "FAIL (" + ", ".join(failed) + ")"
            print(f"  [{len(dirresults):>3}/{len(work)}] {r.name:<40} {status}",
                  flush=True)

    def fmt(n: Optional[int]) -> str:
        return "?" if n is None else str(n)

    scriptw = max(
        [len("script")]
        + [len(short(x.script)) for r in dirresults for x in r.results]
        + [len(short(x)) for r in dirresults for x in r.skipped])
    width = 57 + 2 + scriptw + 14
    print()
    print(f"{'directory':<40} {'analyzed':>8} {'lifted':>7}  "
          f"{'script':<{scriptw}} {'rc':>4} {'time':>8}")
    print("-" * width)
    for r in sorted(dirresults, key=lambda r: r.name):
        counts = f"{fmt(r.analyzed):>8} {fmt(r.lifted):>7}"
        rows = (
            [(short(x.script), f"{x.returncode:>4} {x.seconds:>7.1f}s")
             for x in r.results]
            + [(short(s), f"{'skip':>4}") for s in r.skipped])
        for (i, (script, rest)) in enumerate(rows):
            prefix = f"{r.name:<40} {counts}" if i == 0 else " " * 57
            print(f"{prefix}  {script:<{scriptw}} {rest}")
    print("-" * width)
    totanalyzed = sum(r.analyzed or 0 for r in dirresults)
    totlifted = sum(r.lifted or 0 for r in dirresults)
    print(f"{'total':<40} {totanalyzed:>8} {totlifted:>7}")
    npassed = sum(1 for r in dirresults if r.passed)
    print(f"{npassed}/{len(dirresults)} directories passed "
          f"({time.time() - start:.1f}s); logs in liftings/<dir>/logs/")
    return 0 if npassed == len(dirresults) else 1


if __name__ == "__main__":
    sys.exit(main())
