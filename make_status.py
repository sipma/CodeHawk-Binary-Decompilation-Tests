#!/usr/bin/env python3
"""Generate the status table of <suite>/STATUS.md from the vars.sh files.

With --top, generate instead the summary table of <root>/STATUS.md, with one
row per suite <root>/<package>/<hash> (default root: the current directory),
summing the per-file counts of that suite. The application name is taken from
the 'Software' row of <suite>/README.md, or else is the package name.

Only the table between the markers

  <!-- status-table:begin -->
  <!-- status-table:end -->

is (re)generated; all other text in STATUS.md is preserved. If the markers
are absent, the existing table (starting at the '| Source file' or
'| Application' line) is replaced and the markers are added around it; if there is no table, it is
appended.

Before anything is written, the function partition in each vars.sh is
checked: lifted, errors, typing, and other must be disjoint and together
cover exactly FNS_INCLUDE. Any inconsistency is reported and nothing is
written.

Examples:
  ./make_status.py openssl/6f891f26            # update STATUS.md
  ./make_status.py openssl/6f891f26 --check    # show diff, exit 1 if stale
  ./make_status.py busybox/8b996feb --stdout   # print the new STATUS.md
  ./make_status.py --top                       # update the top-level STATUS.md
"""

import argparse
import difflib
import re
import sys

from pathlib import Path
from typing import List, Tuple

import suiteinfo


BEGIN = "<!-- status-table:begin -->"
END = "<!-- status-table:end -->"


def percent(n: int, total: int) -> str:
    # round half up (python's round() rounds half to even)
    return f"{(200 * n + total) // (2 * total)}%" if total else "-"


COUNTS_HEADER = "Analyzed | Lifted | Errors | Typing | Other Issues |"


def counts(fs: suiteinfo.FunctionSets) -> List[int]:
    return [len(x) for x in fs]


def row(cells: List[str]) -> str:
    return "|" + "".join(f" {c} |" if c else " |" for c in cells)


def total_rows(rows: List[List[int]], nlabels: int) -> List[str]:
    """Return the Total and Percent rows for the given count rows.

    The counts are preceded by nlabels label columns. The last five counts
    are the function counts, for which the Percent row gives the fraction of
    the functions analyzed; other counts are summed in the Total row only.
    """
    totals = [sum(c) for c in zip(*rows)] if rows else []
    fns = totals[-5:]
    pad = [""] * (nlabels - 1)
    return [
        row(["**Total**"] + pad + [f"**{t}**" for t in totals]),
        row(["**Percent**"] + pad + [""] * (len(totals) - 4)
            + [percent(t, fns[0]) for t in fns[1:]])]


def make_table(rows: List[Tuple[str, suiteinfo.FunctionSets]]) -> List[str]:
    lines = [
        "| Source file | " + COUNTS_HEADER,
        "|---|---:|---:|---:|---:|---:|"]
    for (src, fs) in rows:
        lines.append(
            f"| `{src}` | " + " | ".join(str(c) for c in counts(fs)) + " |")
    return lines + total_rows([counts(fs) for (_, fs) in rows], 1)


def application(suite: Path) -> str:
    """Return the 'Software' entry of suite/README.md, or the package name."""
    readme = suite / "README.md"
    if readme.is_file():
        for line in readme.read_text().splitlines():
            m = re.match(r"^\|\s*Software\s*\|\s*(.+?)\s*\|", line)
            if m:
                return m.group(1)
    return suite.parent.name


def make_top_table(
        rows: List[Tuple[Path, List[suiteinfo.FunctionSets]]]) -> List[str]:
    lines = [
        "| Application | Binary MD5 prefix | Source files | " + COUNTS_HEADER,
        "|---|---|---:|---:|---:|---:|---:|---:|"]
    countrows: List[List[int]] = []
    for (suite, fss) in rows:
        c = [len(fss)] + [sum(x) for x in zip(*map(counts, fss))]
        countrows.append(c)
        lines.append(
            f"| [{application(suite)}]({suite.parent.name}/{suite.name}/STATUS.md)"
            f" | `{suite.name}` | " + " | ".join(str(x) for x in c) + " |")
    return lines + total_rows(countrows, 2)


def suite_sets(
        suite: Path, problems: List[str]
) -> List[Tuple[str, suiteinfo.FunctionSets]]:
    """Return the function sets per source file; add problems found."""
    rows: List[Tuple[str, suiteinfo.FunctionSets]] = []
    for d in suiteinfo.lifting_dirs(suite):
        try:
            fs = suiteinfo.function_sets(d)
        except suiteinfo.VarsError as e:
            problems.append(str(e))
            continue
        problems.extend(f"{d}: {p}" for p in fs.check())
        rows.append((suiteinfo.source_file(d), fs))
    return sorted(rows, key=lambda r: r[0])


def splice(text: str, table: List[str]) -> str:
    lines = text.splitlines()
    block = [BEGIN] + table + [END]
    if BEGIN in lines and END in lines:
        (b, e) = (lines.index(BEGIN), lines.index(END))
        if e < b:
            raise ValueError("status-table end marker precedes begin marker")
        lines[b:e + 1] = block
    else:
        # the existing table starts with the same first column header
        header = table[0][:table[0].index("|", 1)]
        start = next(
            (i for (i, l) in enumerate(lines) if l.startswith(header)), None)
        if start is None:
            lines += [""] + block
        else:
            end = start
            while end < len(lines) and lines[end].startswith("|"):
                end += 1
            lines[start:end] = block
    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument(
        "suite", nargs="?",
        help=("suite directory, containing liftings/; with --top, the root "
              "directory containing the suites (default: .)"))
    parser.add_argument(
        "--top", action="store_true",
        help="generate the summary table over all suites")
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument(
        "--check", action="store_true",
        help="do not write; show the diff and exit 1 if STATUS.md is stale")
    mode.add_argument(
        "--stdout", action="store_true",
        help="do not write; print the new STATUS.md")
    args = parser.parse_args()

    problems: List[str] = []
    if args.top:
        root = Path(args.suite or ".")
        statusfile = root / "STATUS.md"
        suites = sorted(p.parent for p in root.glob("*/*/liftings"))
        if not suites:
            print(f"No suites found in {root}", file=sys.stderr)
            return 2
        table = make_top_table([
            (s, [fs for (_, fs) in suite_sets(s, problems)]) for s in suites])
    else:
        if args.suite is None:
            parser.error("a suite directory is required (or use --top)")
        suite = Path(args.suite)
        statusfile = suite / "STATUS.md"
        if not (suite / "liftings").is_dir():
            print(f"Directory not found: {suite / 'liftings'}", file=sys.stderr)
            return 2
        table = make_table(suite_sets(suite, problems))
    if problems:
        print("Inconsistent vars.sh; STATUS.md not updated:", file=sys.stderr)
        for p in problems:
            print("  " + p, file=sys.stderr)
        return 1

    old = statusfile.read_text() if statusfile.is_file() else ""
    new = splice(old, table)

    if args.stdout:
        sys.stdout.write(new)
        return 0
    if args.check:
        diff = list(difflib.unified_diff(
            old.splitlines(keepends=True), new.splitlines(keepends=True),
            str(statusfile), str(statusfile) + " (generated)"))
        sys.stdout.writelines(diff)
        return 1 if diff else 0
    if new == old:
        print(f"{statusfile} is up to date")
    else:
        statusfile.write_text(new)
        print(f"{statusfile} updated")
    return 0


if __name__ == "__main__":
    sys.exit(main())
