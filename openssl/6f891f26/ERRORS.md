# Lifting Errors -- OpenSSL libcrypto 6f891f26

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
| USER | 2 | 2 | 9 |
| UNSP | 10 | 56 | 158 |
| RSLT | 11 | 29 | 80 |
| RDEF | 2 | 3 | 11 |
| MISC | 1 | 1 | 1 |
| **Total** | **26** | **75** | **259** |

Functions with errors according to `vars.sh` (`FNS_PENDING_ERRORS`): 75.

### Consistency with vars.sh

- `crypto__evp__bio_b64`: lifting of `0xcb5dc` aborted: `ABORT: Unable to create lifting for <addr> (No register with name R1_R3)`

## CATEGORY DETAILS

Per log id (shown without its category prefix): the number of
distinct functions and records, and the most common
message (with addresses replaced by `<addr>`).

### USER -- Userdata: missing or incomplete user-provided information

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `STRCTDEF-0001` | 2 | 6 | `Struct definition is missing for ASN1_VALUE_st at address <addr> (no fields found)` |
| `STRCTDEF-0002` | 2 | 3 | `Struct definition is missing for ASN1_VALUE_st at address <addr> (no fields found)` |
| **Subtotal** | **2** | **9** | |

### UNSP -- Unsupported: constructs not yet handled by the lifter

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `INDCALL-0001` | 32 | 41 | `BL: Indirect call not yet handled at address <addr>` |
| `INDCALL-0002` | 14 | 31 | `LDR: Indirect call via Load to PC not yet handled at <addr>` |
| `INDEXEXP-0001` | 4 | 6 | `Address expression (R3 - <addr>) with operator minus not yet supported at <addr>` |
| `GLBVAR-0002` | 3 | 46 | `Conversion of global variable gv_<addr> access with offset 4294852668 at address <addr> not yet supported` |
| `RETVAR-0001` | 3 | 24 | `Non-struct pointer type unsigned char * for variable rtn_sk_value__0 not yet handled at <addr>` |
| `DATASTR-0001` | 2 | 4 | `Stack variable constant offset 1 of localstackvar_32 not yet handled at address <addr>` |
| `DATASTR-0002` | 1 | 1 | `Stack variable constant offset -26 of prompt3 not yet handled at address <addr>` |
| `JMPTBL-0001` | 1 | 2 | `ADD: aggregate jumptable at address <addr> not yet handled` |
| `PTRXPR-0001` | 1 | 2 | `Conversion of pointer expression encountered unexpected  base expression (ssa_R4_1 + ssa_R1_2) at address <addr>` |
| `STCKARG-0001` | 1 | 1 | `Conversion of stack argument arg.0000 not yet supported at address <addr>` |
| **Subtotal** | **56** | **158** | |

### RSLT -- Analysis results: unusable or imprecise analysis results

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `BRNOCC-0001` | 13 | 32 | `Bcc: conditional branch without branch conditions at address <addr>` |
| `ERRFRZ-0001` | 7 | 15 | `Encountered unsimplified frozen value: R3_val_<addr>_amp_<addr> at address <addr>` |
| `XCTRUE-0001` | 4 | 5 | `Encountered constant TRUE at address <addr>` |
| `PRNOCC-0001` | 3 | 3 | `No instruction condition predicate found at address <addr>` |
| `RANDOM-0001` | 3 | 6 | `Encountered random constant at address <addr>` |
| `ERRCXPR-0002` | 2 | 10 | `LDR: Unable to use a C expression for rhs. Fall back to native byte-based address: (R5 + <addr>) to form rhs *(ssa_R5_4 + 4) at address <addr>` |
| `ERRGLB-0001` | 2 | 3 | `conversion of initial memory value app_pkey_methods_in that may have changed reverted to original variable at <addr>` |
| `ERRVAL-0003` | 2 | 2 | `STM: Error value encountered in LHSs at address <addr>` |
| `ERRCXPR-0001` | 1 | 1 | `LDRH: Unable to use a C expression for rhs. Fall back to native byte-based address: (R12 + R1) to form rhs *(ssa_R12_0 + ssa_R1_7) at address <addr>` |
| `ERRCXPR-0003` | 1 | 2 | `LDRB: Unable to use a C expression for rhs. Fall back to native byte-based address: (R0 + <addr>) to form rhs *(ssa_R0_25 + 1) at address <addr>` |
| `ERRVAL-0005` | 1 | 1 | `STM: Error value encountered in LHSs at address <addr>` |
| **Subtotal** | **29** | **80** | |

### RDEF -- Reaching definitions: missing or unresolved reaching definitions

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `CLOBBER-0001` | 3 | 6 | `Reaching definition of address <addr>_clobber for clobbered value R3 not found` |
| `CLOBBER-0002` | 2 | 5 | `clobbered value <addr>_clobber found at address <addr>` |
| **Subtotal** | **3** | **11** | |

### MISC -- Miscellaneous: aborted liftings and messages without a specific log id

| Log id | Functions | Records | Representative message |
|---|---:|---:|---|
| `ABORT-0001` | 1 | 1 | `ABORT: Unable to create lifting for <addr> (No register with name R1_R3)` |
| **Subtotal** | **1** | **1** | |

<!-- errors:end -->
