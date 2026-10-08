# Lifting Errors

Liftings are generated incrementally from the assembly code using analysis
results like invariants and reaching definitions provided by the OCaml
analyzer. During this process error conditions may be encountered that
prohibit a faithful lifting. When that happens an error log message is
generated that contains a brief description of the problem, and a diagnostic
code that indicates what party may be able to fix the problem, or whether
a construct was encountered that is simply not supported yet. The lifting
process is continued, and a lifting is produced, to enable better
investigation of the problem, but the lifting itself should be considered
invalid, whenever error messages were produced.

The functions that currently generate errors are listed in the vars.sh
file present in each directory under `FNS_PENDING_ERRORS`. The script
`test.10.check-errors.sh` records every error in `logs/error_log.json`.

Error records contain a log-id `CCCC-DESCRIPTOR-nnnn`, where `CCCC`
is the category. Each record is attributed to the function that was
lifted when it was logged.

## Categories

Four categories of error messages are currently distinguished:

- **USER:** Data provided in the userdata is incorrect or incomplete,
    or some information is missing that the user is expected to
    provide, like a function signature, or the type of a global variable.
    These errors are likely fixable by the user.

- **UNSP:** The lifting process hit a construct that is not yet supported
    for lifting, e.g., an indirect call or an unmodeled assembly instruction.
    These errors are not fixable by the user; they typically require the
    addition of new features to the lifter or analyzer.

- **RSLT:** Analysis results are unusable or imprecise. These errors can
    sometimes be addressed by userdata or headers, e.g., by specifying
    local variable types or callee function signatures. More often they
    are caused by a combination of assembly code structure and limitations
    of the analysis.

- **RDEF:** Reaching definitions are missing or unresolved. Problems with
    reaching definitions are typically caused by the lack of path sensitivity
    of the analysis (CodeHawk analysis is flow sensitive): joins merge paths
    and thereby reaching definitions that should stay separate. CodeHawk
    provides an option for the user to selectively disable certain paths
    along which reaching definitions are collected, which is often sufficient
    to solve the problem. However, finding the specific paths to disable is
    not always easy or obvious.


## Descriptors

Below is a selection of the descriptors currently used. The list of descriptors
is still growing as more log messages get associated with a log_id. Moreover
descriptors may become obsolete when issues in CodeHawk get resolved.

### USER: missing or incomplete user-provided information

- `GLOBDECL`: Unknown global address used as an argument
- `STRCTDEF`: Struct definition is missing for named struct declaration

### UNSP: constructs not yet handled by the lifter

- `INDCALL`: Indirect call not yet handled by the lifter
- `ASMINSTR`: Encountered an assembly instruction that has not been modeled yet

### RSLT: unusable or imprecise analysis results

- `BRNOCC`: Conditional branch without branch condition
- `ERRVAL`: Error value encountered for the value of a variable or expression
- `PRNOCC`: Predicated instruction without condition

### RDEF: missing or unresolved reaching definitions

- `CLOBBER`: A reaching definition is the value of a register clobbered by a call
- `MISSING`: Reaching definitions are missing entirely