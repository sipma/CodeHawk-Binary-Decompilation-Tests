# Lifting Errors -- Busybox 8b996feb

<!-- errors:begin -->

## SUMMARY

The functions in `FNS_PENDING_ERRORS` are lifted by the check-errors
script, which records every error in `logs/error_log.json`. Each
error has a log id `CCCC-DESCRIPTOR-nnnn`, where `CCCC` is the
category. Records that are identical apart from their timestamp are
counted once. Each record is attributed to the function that was
being lifted when it was logged.

**Functions** is the number of distinct functions with at least one
error of that category; a function may have errors in more than one
category. **Records** is the number of distinct error records.

| Category | Log ids | Functions | Records |
|---|---:|---:|---:|
| USER | 1 | 3 | 3 |
| UNSP | 6 | 7 | 9 |
| RSLT | 8 | 20 | 150 |
| RDEF | 4 | 12 | 27 |
| **Total** | **19** | **33** | **189** |

Functions with errors according to `vars.sh` (`FNS_PENDING_ERRORS`): 33.

## CATEGORY DETAILS

Per log id (shown without its category prefix): the number of
distinct functions and records, and the most common
message (with addresses replaced by `<addr>`).

### USER -- Userdata: missing or incomplete user-provided information

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `GLBDECL-0001` | 3 | 3 | `Unknown global address <addr> as call argument at address <addr>` |
| **Subtotal** | **3** | **3** | |

### UNSP -- Unsupported: constructs not yet handled by the lifter

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `DATASTR-0002` | 2 | 3 | `Stack variable constant offset -20 of localstackvar_20 not yet handled at address <addr>` |
| `INDCALL-0001` | 2 | 2 | `BL: Indirect call not yet handled at address <addr>` |
| `ASMINSTR-0001` | 1 | 1 | `no lifting support available for instruction SBFX at address <addr>` |
| `BINOP-0001` | 1 | 1 | `conversion of binary expression <addr>, R1_in with operator xbyte at address <addr> not yet supported` |
| `DATASTR-0001` | 1 | 1 | `Stack variable constant offset 1 of localstackvar_68 not yet handled at address <addr>` |
| `INDEXEXP-0001` | 1 | 1 | `Address expression (R5 - <addr>) with operator minus not yet supported at <addr>` |
| **Subtotal** | **7** | **9** | |

### RSLT -- Analysis results: unusable or imprecise analysis results

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `ERRGLB-0001` | 13 | 117 | `conversion of initial memory value less_globals_in that may have changed reverted to original variable at <addr>` |
| `BRNOCC-0001` | 4 | 25 | `Bcc: conditional branch without branch conditions at address <addr>` |
| `PRNOCC-0001` | 2 | 2 | `No instruction condition predicate found at address <addr>` |
| `ERRFRZ-0001` | 1 | 1 | `Encountered unsimplified frozen value: R3_val_<addr>_amp_<addr> at address <addr>` |
| `ERRVAL-0001` | 1 | 1 | `Encountered error value at address <addr>` |
| `ERRVAL-0002` | 1 | 1 | `both memory value and address values are error values at address <addr>:` |
| `RANDOM-0001` | 1 | 2 | `Encountered random constant at address <addr>` |
| `XCFALSE-0001` | 1 | 1 | `Encountered constant FALSE at address <addr>` |
| **Subtotal** | **20** | **150** | |

### RDEF -- Reaching definitions: missing or unresolved reaching definitions

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `CLOBBER-0001` | 9 | 10 | `Reaching definition of address <addr>_clobber for clobbered value R1 not found` |
| `CLOBBER-0002` | 9 | 11 | `clobbered value <addr>_clobber found at address <addr>` |
| `UNRESOLVED-0001` | 2 | 2 | `Reaching definition address <addr> for variable R3  not found` |
| `MISSING-0002` | 1 | 4 | `No rdefs found for R0 at address <addr>` |
| **Subtotal** | **12** | **27** | |

<!-- errors:end -->
