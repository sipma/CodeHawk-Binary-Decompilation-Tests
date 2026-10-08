#!/usr/bin/env python3
"""Generate <suite>/ERRORS.md from the error logs of the lifting directories.

Input is liftings/<dir>/logs/error_log.json, produced by
test.10.check-errors.sh, which lifts the functions in FNS_PENDING_ERRORS.
Each record has a log_id CCCC-DESCRIPTOR-nnnn, where CCCC is the category.

Records that are identical apart from the timestamp are counted once. Each
record is attributed to the function containing the instruction address in
the record's faddr field, logged by chkx for the function being lifted. For
logs from older versions of chkx without faddr, the record is attributed to
the function containing the instruction address in its message (the function
in FNS_INCLUDE with the greatest start address not above it). The primary
count is the number of distinct functions per log_id.

Lifting of a function that raises an exception is reported by chkx with log
id MISC-ABORT-0001 (older versions abort chkx; this is detected from the
Traceback in the script output saved by run_tests.py).

Only the text between the markers

  <!-- errors:begin -->
  <!-- errors:end -->

is (re)generated. If the markers are absent, everything after the title line
is replaced. Notes per category can be kept in <suite>/errors_notes.md, as
sections '## CCCC' followed by text; they are inserted below the table of
that category.

Examples:
  ./make_errors.py openssl/6f891f26            # update ERRORS.md
  ./make_errors.py openssl/6f891f26 --check    # show diff, exit 1 if stale
  ./make_errors.py busybox/8b996feb --stdout   # print the new ERRORS.md
  ./make_errors.py openssl/6f891f26 --locations  # add module:line column
"""

import argparse
import collections
import difflib
import re
import sys

from pathlib import Path
from typing import Dict, List, Optional, Set, Tuple

import suiteinfo
from suiteinfo import ErrorRecord


BEGIN = "<!-- errors:begin -->"
END = "<!-- errors:end -->"

CATEGORIES = {
    "USER": "Userdata: missing or incomplete user-provided information",
    "UNSP": "Unsupported: constructs not yet handled by the lifter",
    "RSLT": "Analysis results: unusable or imprecise analysis results",
    "RDEF": "Reaching definitions: missing or unresolved reaching definitions",
    "MISC": "Miscellaneous: aborted liftings and messages without a specific log id",
}


def representative(msgs: List[str]) -> str:
    """Return the most common message shape, with addresses abstracted."""
    def norm(m: str) -> str:
        m = re.sub(r"^[A-Z]{4}: ", "", m.strip())
        return re.sub(r"0x[0-9a-fA-F]+", "<addr>", m)
    shapes = collections.Counter(norm(m) for m in msgs)
    # most common; ties broken alphabetically for a stable result
    shape = min(shapes.items(), key=lambda kv: (-kv[1], kv[0]))[0]
    return "`" + shape.replace("`", "'").replace("|", "\\|") + "`"


def read_notes(suite: Path) -> Dict[str, str]:
    f = suite / "errors_notes.md"
    if not f.is_file():
        return {}
    notes: Dict[str, List[str]] = {}
    current: Optional[str] = None
    for line in f.read_text().splitlines():
        m = re.match(r"^##\s+([A-Z]{4})\s*$", line)
        if m:
            current = m.group(1)
            notes[current] = []
        elif current is not None:
            notes[current].append(line)
    return {k: "\n".join(v).strip() for (k, v) in notes.items()}


class Collected:

    def __init__(self) -> None:
        # (dir name, function address) attributed to each record
        self.records: List[Tuple[str, Optional[int], ErrorRecord]] = []
        self.pending_errors = 0
        self.missing_logs: List[str] = []
        self.stale_logs: List[str] = []
        # chkx aborted (python exception): (dir name, exception line)
        self.crashes: List[Tuple[str, str]] = []
        # lifting of a function aborted: (dir name, function, message)
        self.aborts: List[Tuple[str, Optional[int], str]] = []
        # number of records attributed by address instead of faddr
        self.by_address = 0
        # consistency problems: (dir name, description)
        self.no_records: List[Tuple[str, List[str]]] = []
        self.outside: List[Tuple[str, List[str]]] = []
        self.unattributed: List[Tuple[str, ErrorRecord]] = []


def aborted(d: Path) -> Optional[str]:
    """Return the exception if the check-errors run of chkx aborted.

    Looks at the output of the check-errors script as saved by run_tests.py
    (logs/test.10.check-errors.sh.log). An abort is not recorded in
    error_log.json, so the functions after it have no records. Script output
    older than error_log.json is from a different run and is ignored.
    """
    errlog = d / suiteinfo.ERROR_LOG
    f = d / "logs" / "test.10.check-errors.sh.log"
    if f.is_file() and not (
            errlog.is_file() and f.stat().st_mtime < errlog.stat().st_mtime):
        lines = f.read_text(errors="replace").splitlines()
        if any(l.startswith("Traceback ") for l in lines):
            return next(
                (l.strip() for l in reversed(lines) if l.strip()), "?")
    return None


def collect(suite: Path) -> Collected:
    c = Collected()
    for d in suiteinfo.lifting_dirs(suite):
        fs = suiteinfo.function_sets(d)
        c.pending_errors += len(fs.errors)
        records = suiteinfo.read_error_log(d)
        if records is None:
            if fs.errors:
                c.missing_logs.append(d.name)
            continue
        if ((d / suiteinfo.ERROR_LOG).stat().st_mtime
                < (d / "vars.sh").stat().st_mtime):
            c.stale_logs.append(d.name)
        crash = aborted(d)
        if crash is not None:
            c.crashes.append((d.name, crash))
        starts = sorted(int(f, 16) for f in fs.analyzed)
        errfns = {int(f, 16) for f in fs.errors}
        found: Set[int] = set()
        for r in records:
            if r.faddr is not None:
                fn: Optional[int] = r.faddr
            elif r.address is not None:
                fn = suiteinfo.containing_function(r.address, starts)
                c.by_address += 1
            else:
                fn = None
            if r.log_id.startswith("MISC-ABORT"):
                c.aborts.append((d.name, fn, r.msg))
            c.records.append((d.name, fn, r))
            if fn is None:
                c.unattributed.append((d.name, r))
            else:
                found.add(fn)
        if errfns - found:
            c.no_records.append(
                (d.name, [hex(f) for f in sorted(errfns - found)]))
        if found - errfns:
            c.outside.append(
                (d.name, [hex(f) for f in sorted(found - errfns)]))
    return c


def make_block(
        c: Collected, notes: Dict[str, str], locations: bool = False
) -> List[str]:
    bylogid: Dict[str, List[Tuple[str, Optional[int], ErrorRecord]]] = (
        collections.defaultdict(list))
    for x in c.records:
        bylogid[x[2].log_id].append(x)

    def functions(xs) -> Set[Tuple[str, int]]:
        return {(dn, fn) for (dn, fn, _) in xs if fn is not None}

    cats = sorted(
        {lid.split("-")[0] for lid in bylogid},
        key=lambda k: (list(CATEGORIES).index(k) if k in CATEGORIES
                       else len(CATEGORIES), k))
    bycat = {
        cat: [x for x in c.records if x[2].category == cat] for cat in cats}
    allfns = functions(c.records)

    out: List[str] = []
    out += [
        "## SUMMARY",
        "",
        "The functions in `FNS_PENDING_ERRORS` are lifted by the check-errors",
        "script, which records every error in `logs/error_log.json`. Each",
        "error has a log id `CCCC-DESCRIPTOR-nnnn`, where `CCCC` is the",
        "category. Records that are identical apart from their timestamp are",
        "counted once. Each record is attributed to the function that was",
        "being lifted when it was logged.",
        "",
        "**Functions** is the number of distinct functions with at least one",
        "error of that category; a function may have errors in more than one",
        "category. **Records** is the number of distinct error records.",
        "",
        "| Category | Log ids | Functions | Records |",
        "|---|---:|---:|---:|"]
    for cat in cats:
        xs = bycat[cat]
        nids = len({x[2].log_id for x in xs})
        out.append(
            f"| {cat} | {nids} | {len(functions(xs))} | {len(xs)} |")
    out.append(
        f"| **Total** | **{len(bylogid)}** | **{len(allfns)}** | "
        f"**{len(c.records)}** |")
    out += [
        "",
        f"Functions with errors according to `vars.sh` "
        f"(`FNS_PENDING_ERRORS`): {c.pending_errors}.",
        ""]

    problems = (
        c.missing_logs or c.stale_logs or c.crashes or c.aborts
        or c.by_address or c.no_records or c.outside
        or c.unattributed)
    if problems:
        out += ["### Consistency with vars.sh", ""]
        for dn in c.missing_logs:
            out.append(f"- `{dn}`: no `logs/error_log.json`")
        for (dn, exc) in c.crashes:
            out.append(
                f"- `{dn}`: chkx aborted (`{exc}`); "
                "the error log is incomplete")
        for (dn, fn, msg) in c.aborts:
            out.append(
                f"- `{dn}`: lifting of `{hex(fn) if fn is not None else '?'}` "
                f"aborted: {representative([msg])}")
        if c.by_address:
            out.append(
                f"- {c.by_address} records without `faddr` (older chkx) "
                "were attributed by the instruction address in the message")
        for dn in c.stale_logs:
            out.append(f"- `{dn}`: `logs/error_log.json` is older than `vars.sh`")
        for (dn, fns) in c.no_records:
            out.append(
                f"- `{dn}`: in `FNS_PENDING_ERRORS` but no error records: "
                + ", ".join(f"`{f}`" for f in fns))
        for (dn, fns) in c.outside:
            out.append(
                f"- `{dn}`: error records for functions not in "
                f"`FNS_PENDING_ERRORS`: " + ", ".join(f"`{f}`" for f in fns))
        for (dn, r) in c.unattributed:
            out.append(
                f"- `{dn}`: record not attributable to a function: "
                f"`{r.log_id}` {representative([r.msg])}")
        out.append("")

    out += [
        "## CATEGORY DETAILS",
        "",
        "Per log id (shown without its category prefix): the number of",
        "distinct functions and records, "
        + ("the location(s) in the CodeHawk-Binary\nsource code "
           "(module:line) where the message is raised, "
           if locations else "")
        + "and the most common\nmessage (with addresses replaced by "
        "`<addr>`).",
        ""]
    loccol = (" Location |", "---|") if locations else ("", "")
    for cat in cats:
        title = CATEGORIES.get(cat, cat)
        out += [
            f"### {cat} -- {title}",
            "",
            f"| Log id | Functions | Records |{loccol[0]} "
            "Representative message |",
            f"|---|---:|---:|{loccol[1]}---|"]
        ids = sorted(
            {x[2].log_id for x in bycat[cat]},
            key=lambda lid: (-len(functions(bylogid[lid])), lid))
        for lid in ids:
            xs = bylogid[lid]
            locs = sorted(
                {x[2].location for x in xs},
                key=lambda l: (l.split(":")[0], int(l.split(":")[1])))
            shortid = lid.split("-", 1)[1] if "-" in lid else lid
            out.append(
                f"| `{shortid}` | {len(functions(xs))} | {len(xs)} | "
                + ("<br>".join(f"`{l}`" for l in locs) + " | "
                   if locations else "")
                + representative([x[2].msg for x in xs]) + " |")
        out.append(
            f"| **Subtotal** | **{len(functions(bycat[cat]))}** | "
            f"**{len(bycat[cat])}** |" + (" |" if locations else "") + " |")
        out.append("")
        if notes.get(cat):
            out += [notes[cat], ""]
    return out


def splice(text: str, block: List[str]) -> str:
    lines = text.splitlines()
    block = [BEGIN, ""] + block + [END]
    if BEGIN in lines and END in lines:
        (b, e) = (lines.index(BEGIN), lines.index(END))
        if e < b:
            raise ValueError("errors end marker precedes begin marker")
        lines[b:e + 1] = block
    else:
        title = lines[:1] if lines and lines[0].startswith("# ") else []
        lines = title + [""] + block
    return "\n".join(lines) + "\n"


def main() -> int:
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("suite", help="suite directory, containing liftings/")
    parser.add_argument(
        "--locations", action="store_true",
        help=("include a column with the location(s) in the CodeHawk-Binary "
              "source code (module:line) where each message is raised"))
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument(
        "--check", action="store_true",
        help="do not write; show the diff and exit 1 if ERRORS.md is stale")
    mode.add_argument(
        "--stdout", action="store_true",
        help="do not write; print the new ERRORS.md")
    args = parser.parse_args()

    suite = Path(args.suite)
    errorsfile = suite / "ERRORS.md"
    if not (suite / "liftings").is_dir():
        print(f"Directory not found: {suite / 'liftings'}", file=sys.stderr)
        return 2

    try:
        collected = collect(suite)
    except suiteinfo.VarsError as e:
        print(f"Error: {e}; ERRORS.md not updated", file=sys.stderr)
        return 1

    for dn in collected.missing_logs:
        print(f"Warning: {dn}: no logs/error_log.json", file=sys.stderr)
    for (dn, exc) in collected.crashes:
        print(f"Warning: {dn}: chkx aborted: {exc}", file=sys.stderr)
    for dn in collected.stale_logs:
        print(f"Warning: {dn}: logs/error_log.json is older than vars.sh; "
              "rerun the check-errors script", file=sys.stderr)

    old = errorsfile.read_text() if errorsfile.is_file() else ""
    new = splice(
        old, make_block(collected, read_notes(suite), args.locations))

    if args.stdout:
        sys.stdout.write(new)
        return 0
    if args.check:
        diff = list(difflib.unified_diff(
            old.splitlines(keepends=True), new.splitlines(keepends=True),
            str(errorsfile), str(errorsfile) + " (generated)"))
        sys.stdout.writelines(diff)
        return 1 if diff else 0
    if new == old:
        print(f"{errorsfile} is up to date")
    else:
        errorsfile.write_text(new)
        print(f"{errorsfile} updated")
    return 0


if __name__ == "__main__":
    sys.exit(main())
