"""Access to the per-directory information of a lifting test suite.

A suite directory (e.g. openssl/6f891f26) contains liftings/<dir>, one per
source file, where <dir> is the source path with '/' replaced by '__'. Each
<dir>/vars.sh exports the function partition:

  FNS_INCLUDE          all functions analyzed
  FNS_LIFTED           successfully lifted
  FNS_PENDING_ERRORS   lifting produces errors
  FNS_PENDING_TYPING   lifts without errors, some locals untyped
  FNS_PENDING_OTHER    gcc parse failure or semantic issue

vars.sh is sourced by bash, so values are exactly the word-split values the
test scripts see (commented-out lines are ignored, etc.).
"""

import bisect
import json
import re
import subprocess

from pathlib import Path
from typing import Dict, List, NamedTuple, Optional


UNSET = "\x01unset\x01"

VARNAMES = [
    "FNS_INCLUDE", "FNS_LIFTED", "FNS_PENDING_ERRORS", "FNS_PENDING_TYPING",
    "FNS_PENDING_OTHER"]


class VarsError(Exception):
    pass


def read_vars(d: Path, names: List[str] = VARNAMES) -> Dict[str, List[str]]:
    """Return the word-split values of the given variables in d/vars.sh.

    Variables that are not set are absent from the result.
    """
    if not (d / "vars.sh").is_file():
        raise VarsError(f"{d}: vars.sh not found")
    cmd = "source ./vars.sh >/dev/null 2>&1; " + "; ".join(
        f'printf "%s\\0" "${{{n}-{UNSET}}}"' for n in names)
    try:
        proc = subprocess.run(
            ["bash", "-c", cmd], cwd=d, capture_output=True, text=True,
            timeout=10)
    except subprocess.TimeoutExpired:
        raise VarsError(f"{d}: timeout sourcing vars.sh")
    values = proc.stdout.split("\0")[:len(names)]
    if len(values) != len(names):
        raise VarsError(f"{d}: unable to source vars.sh")
    return {n: v.split() for (n, v) in zip(names, values) if v != UNSET}


class FunctionSets(NamedTuple):
    analyzed: List[str]
    lifted: List[str]
    errors: List[str]
    typing: List[str]
    other: List[str]

    def check(self) -> List[str]:
        """Return a list of inconsistencies (empty if the partition is valid).

        The four categories must be disjoint, without duplicates, and their
        union must be exactly the set of analyzed functions.
        """
        problems: List[str] = []
        cats = [
            ("lifted", self.lifted), ("errors", self.errors),
            ("typing", self.typing), ("other", self.other)]
        norm = lambda a: int(a, 16)
        for (name, fns) in [("analyzed", self.analyzed)] + cats:
            seen = set()
            for f in fns:
                try:
                    v = norm(f)
                except ValueError:
                    problems.append(f"{name}: invalid address {f}")
                    continue
                if v in seen:
                    problems.append(f"{name}: duplicate address {f}")
                seen.add(v)
        if problems:
            return problems
        owner: Dict[int, str] = {}
        for (name, fns) in cats:
            for f in fns:
                if norm(f) in owner:
                    problems.append(
                        f"{f} is in both {owner[norm(f)]} and {name}")
                owner[norm(f)] = name
        analyzed = {norm(f) for f in self.analyzed}
        for (v, name) in sorted(owner.items()):
            if v not in analyzed:
                problems.append(f"{hex(v)} ({name}) is not in FNS_INCLUDE")
        for v in sorted(analyzed - set(owner)):
            problems.append(f"{hex(v)} is analyzed but in no category")
        return problems


def function_sets(d: Path) -> FunctionSets:
    vs = read_vars(d)
    if "FNS_INCLUDE" not in vs:
        raise VarsError(f"{d}: FNS_INCLUDE not set")
    return FunctionSets(
        vs["FNS_INCLUDE"],
        vs.get("FNS_LIFTED", []),
        vs.get("FNS_PENDING_ERRORS", []),
        vs.get("FNS_PENDING_TYPING", []),
        vs.get("FNS_PENDING_OTHER", []))


def source_file(d: Path) -> str:
    """Return the source file name corresponding to a lifting directory."""
    return d.name.replace("__", "/") + ".c"


def lifting_dirs(suite: Path) -> List[Path]:
    liftings = suite / "liftings"
    return sorted(p for p in liftings.iterdir() if p.is_dir())


# ---------------------------------------------------------------------------
# Error logs (produced by the check-errors scripts via chkx --jlogfilename)
# ---------------------------------------------------------------------------

ERROR_LOG = Path("logs") / "error_log.json"

# Instruction address in a message: the last 'at [address] 0x...'; failing
# that, the address of a reaching definition ('definition address 0x...'),
# or the call site of a clobber variable ('0x..._clobber').
_AT_ADDR = re.compile(r"\bat (?:address )?(0x[0-9a-fA-F]+)")
_RDEF_ADDR = re.compile(r"\bdefinition address (0x[0-9a-fA-F]+)")
_CLOBBER_ADDR = re.compile(r"(0x[0-9a-fA-F]+)_clobber")


class ErrorRecord(NamedTuple):
    log_id: str
    msg: str
    module: str
    line: int
    address: Optional[int]       # instruction address, if found in msg
    faddr: Optional[int]         # function being lifted (chkx logs faddr)
    exception: Optional[str]     # traceback, if the record has one

    @property
    def category(self) -> str:
        return self.log_id.split("-")[0]

    @property
    def location(self) -> str:
        return f"{self.module}:{self.line}"


def instruction_address(msg: str) -> Optional[int]:
    m = (_AT_ADDR.findall(msg) or _RDEF_ADDR.findall(msg)
         or _CLOBBER_ADDR.findall(msg))
    return int(m[-1], 16) if m else None


def read_error_log(d: Path) -> Optional[List[ErrorRecord]]:
    """Return the deduplicated records of d/logs/error_log.json.

    Records that are identical apart from the timestamp are reported only
    once. Returns None if the log does not exist.
    """
    f = d / ERROR_LOG
    if not f.is_file():
        return None
    seen = set()
    result: List[ErrorRecord] = []
    with f.open(encoding="utf-8") as fp:
        for (n, line) in enumerate(fp, 1):
            if not line.strip():
                continue
            try:
                r = json.loads(line)
            except json.JSONDecodeError as e:
                raise VarsError(f"{f}:{n}: malformed JSON record: {e}")
            key = (
                r.get("log_id"), r.get("faddr"), r.get("msg"), r.get("module"),
                r.get("line"))
            if key in seen:
                continue
            seen.add(key)
            msg = r.get("msg", "")
            result.append(ErrorRecord(
                r.get("log_id", "MISC-NOTAGID-0001"), msg,
                r.get("module", "?"), r.get("line", 0),
                instruction_address(msg),
                int(r["faddr"], 16) if r.get("faddr") else None,
                r.get("exception")))
    return result


def containing_function(addr: int, starts: List[int]) -> Optional[int]:
    """Return the function (start address) that contains addr.

    starts must be sorted; it should contain all functions of the source
    file (FNS_INCLUDE). The function is the one with the greatest start
    address <= addr, which assumes that the functions of a source file are
    laid out contiguously.
    """
    i = bisect.bisect_right(starts, addr)
    return starts[i - 1] if i > 0 else None
