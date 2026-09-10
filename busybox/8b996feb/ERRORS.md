# Lifting Errors -- Busybox 8b996feb

## SUMMARY

| Category | Error count | Distinct code locations |
| --- | ---: | ---: |
| USERDATA |  3 | 1 |
| TYPING   |  20 | 4 |
| UNSUPPORTED | 165 | 11 |
| INTERNAL | 42 | 7 |
| **Total** | 230 | 23 |


## CATEGORY DETAILS

The tables below detail the (deduplicated) error message counts for each
category. The location indicates the location in the CodeHawk-Binary
source code (file, line number) where the error message was raised.

### USERDATA

| Location `[File:line]` | Error count | Representative message |
|---|---:|---|
| `ARMCallOpcode:513` | 3 | `Unknown global address <addr> as call argument at address <addr>` |
| **Subtotal** | **3** | |

### TYPING

| Location `[File:line]` | Error count | Representative message |
|---|---:|---|
| `astcmds:424` | 17 | `<faddr>: N referenced local variable(s) have unresolved type: <names>` |
| `XXprUtil:394` | 1 | `Struct definition is missing for group at address <addr> (no fields found)` |
| `XXprUtil:1517` | 1 | `Struct definition is missing for group at address <addr> (no fields found)` |
| `XXprUtil:1457` | 1 | `Struct definition is missing for _ch__group_st at address <addr> (no fields found)` |
| **Subtotal** | **20** | |


### UNSUPPORTED

| Location `[File:line]` | Error count | Representative message |
|---|---:|---|
| `XXprUtil:954` | 116 | `AST def conversion of initial memory value ... that may have changed reverted to original variable at <addr>` |
| `ARMBranch:377` | 25 | `Conditional branch without inferred branch condition at address <addr>` |
| `XXprUtil:863` | 8 | `Cannot determine argument index for initial stack argument 0 at address <addr>` |
| `XXprUtil:1100` | 4 | `AST def conversion of variable <reg>_val_... to lval-expression at address <addr> not yet supported` |
| `XXprUtil:1672` | 3 | `Stack variable with offset -12 not yet supported at address <addr>` |
| `ARMOpcode:501` | 3 | `Conditional branch without inferred condition at address <addr>` |
| `ARMCallOpcode:300` | 2 | `Indirect call not yet handled at address <addr>` |
| `XXprUtil:608` | 1 | `Stack variable offset 1 of localstackvar_68 not yet handled at address <addr>` |
| `XXprUtil:1490` | 1 | `Address expression (R5 - 0x1) with operator minus not yet supported at <addr>` |
| `XXprUtil:1325` | 1 | `AST def conversion of binary expression ... with operator xbyte at address <addr> not yet supported` |
| `ARMOpcode:443` | 1 | `No lifting support available for instruction SBFX at address <addr>` |
| **Subtotal** | **165** | |

### INTERNAL

| Location `[File:line]` | Error count | Representative message |
|---|---:|---|
| `ASTIProvenance:481` | 17 | `Reaching definition address <val>_clobber for variable <reg> not found` |
| `XXprUtil:1016` | 16 | `Rdef: <ssaval>_clobber has not yet been introduced at address <addr>` |
| `XXprUtil:1024` | 4 | `No rdefs found for <reg> at address <addr>` |
| `ARMPop:239` | 2 | `POP: Encountered error value at address <addr>` |
| `XXprUtil:239` | 1 | `Encountered constant-value boolean false at address <addr>` |
| `ARMMove:521` | 1 | `Ternary assignment without associated predicate at address <addr>` |
| `ARMLoadRegisterByte:287` | 1 | `LDRB: both memory value and address values are error values at address <addr>` |
| **Subtotal** | **42** | |



## Messages by source file

| Source file | Error count | Breakdown (category, count, per location) |
|---|---:|---|
| `libbb/bb_pwd.c` | 6 | `ARMPop:239` INTERNAL(2), `XXprUtil:394` TYPING(1), `XXprUtil:1517` TYPING(1), `XXprUtil:1457` TYPING(1), `ARMCallOpcode:300` UNSUPPORTED(1) |
| `libbb/bb_strtonum.c` | 6 | `XXprUtil:1016` INTERNAL(2), `ASTIProvenance:481` INTERNAL(2), `astcmds:424` TYPING(2) |
| `libbb/copyfd.c` | 12 | `XXprUtil:1024` INTERNAL(4), `ARMOpcode:501` UNSUPPORTED(2), `ARMBranch:377` UNSUPPORTED(2), `XXprUtil:1100` UNSUPPORTED(1), `XXprUtil:1016` INTERNAL(1), `ASTIProvenance:481` INTERNAL(1), `astcmds:424` TYPING(1) |
| `libbb/procps.c` | 13 | `XXprUtil:1016` INTERNAL(2), `ASTIProvenance:481` INTERNAL(2), `ARMBranch:377` UNSUPPORTED(2), `astcmds:424` TYPING(3), `XXprUtil:608` UNSUPPORTED(1), `XXprUtil:1100` UNSUPPORTED(1), `ARMMove:521` INTERNAL(1), `ARMCallOpcode:300` UNSUPPORTED(1) |
| `libbb/xfuncs_printf.c` | 22 | `XXprUtil:863` UNSUPPORTED(8), `astcmds:424` TYPING(6), `XXprUtil:1016` INTERNAL(5), `ASTIProvenance:481` INTERNAL(3) |
| `libbb/xfuncs.c` | 15 | `ASTIProvenance:481` INTERNAL(4), `XXprUtil:1016` INTERNAL(2), `ARMCallOpcode:513` USERDATA(2), `astcmds:424` TYPING(1), `XXprUtil:239` INTERNAL(1), `XXprUtil:1672` UNSUPPORTED(1), `XXprUtil:1325` UNSUPPORTED(1), `XXprUtil:1100` UNSUPPORTED(1), `ARMOpcode:443` UNSUPPORTED(1), `ARMLoadRegisterByte:287` INTERNAL(1) |
| `miscutils/less.c` | 147 | `XXprUtil:954` UNSUPPORTED(116), `ARMBranch:377` UNSUPPORTED(21), `ASTIProvenance:481` INTERNAL(4), `XXprUtil:1016` INTERNAL(3), `astcmds:424` TYPING(1), `XXprUtil:1490` UNSUPPORTED(1), `ARMCallOpcode:513` USERDATA(1) |
| `networking/udhcp/common.c` | 7 | `astcmds:424` TYPING(2), `XXprUtil:1672` UNSUPPORTED(2), `XXprUtil:1016` INTERNAL(1), `ASTIProvenance:481` INTERNAL(1), `ARMOpcode:501` UNSUPPORTED(1) |
| `networking/udhcp/domain_codec.c` | 2 | `XXprUtil:1100` UNSUPPORTED(1), `astcmds:424` TYPING(1) |
| **Total** | **230** | |

## Observations

- **Missing features:** Handling of global variables (`XXprUtil:954` and
  `XXprUtil:1100`) and Conditional branch without inferred brach condition
  (`ARMBranch:377` and `ARMOpcode:501`) are the most frequently occuring
  construct not yet supported with 120 and 28 error messages reported, resp.
  Interestingly almost all occurrences of the handling of global variables
  (116) appear in a single file, `miscutils/less.c`. The reason is the
  unusual way global variables are handled in the busybox apps, where they
  are usually packed into a struct, which can then either be statically
  or dynamically allocated within the app file.
- **Reaching definitions:** Reaching definitiions are the most frequent
  cause for internal invariant violations, in particular the perceived
  reaching definition of a register clobbered by a function call. The
  reason is that reaching definitions are computed on the control
  flow graph without taking into account branch conditions, and thus
  are an over-approximation of the actual set of reaching definitions,
  sometimes giving rise to reaching definitions from infeasible paths.