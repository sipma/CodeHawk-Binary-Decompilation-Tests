# Lifting Errors -- OpenSSL libcrypto 6f891f26

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

Error messages are tagged by a diagnostic category code. The following codes
are currently used:

- **USERDATA:** Data provided in the userdata is incorrect or incomplete.
     This should be able to be fixed by the user.
- **TYPING:** Type information provided via header files is incomplete or
    inconsistent. Many types are inferred automatically by the analyzer.
    However, a prerequisite for producing a lifting is the presence of a
    function prototype in a header file. In some cases it may also be necessary
    to provide types for local stack variables (via the function annotations).
    Type omissions should be fixable by the user. Type inconsistencies may
    be harder to diagnose, but are usually still fixable by the user.
- **UNSUPPORTED:** The lifting process hit a construct that is not yet
    supported by the analyzer, e.g., an indirect call, or an unsupported
    assembly instruction, or an unresolved branch condition. This problem is
    not fixable by the user; it requires the addition of new features to the
    analyzer.
- **INTERNAL:** An internal invariant was violated. The lifting process
    encountered an error value or is otherwise missing the required data
    to construct a valid lifting. This is generally not fixable by the user;
    it could be an analyzer defect that requires CodeHawk maintainers'
    attention.

## SUMMARY

| Category | Error count | Distinct code locations |
| --- | ---: | ---: |
| USERDATA |  14 | 1 |
| TYPING   |  39 | 4 |
| UNSUPPORTED | 181 | 15 |
| INTERNAL | 96 | 11 |
| **Total** | 330 | 31 |

## CATEGORY DETAILS

The tables below detail the (deduplicated) error message counts for each
category. The location indicates the location in the CodeHawk-Binary
source code (file, line number) where the error message was raised.

### USERDATA

| Location `[File:line]` | Error count | Representative message |
|---|---:|---|
| `ARMCallOpcode:513` | 14 | `Unknown global address <addr> as call argument at address <addr>` |
| **Subtotal** | **14** | |


### TYPING

| Location `[File:line]` | Error count | Representative message |
|---|---:|---|
| `astcmds:425` | 24 | `<faddr>: N referenced local variable(s) have unresolved type: <names>` |
| `XXprUtil:1240` | 6 | `Compinfo ASN1_VALUE_st does not have a field at offset 4 (at address <addr>)` |
| `XXprUtil:1528` | 6 | `Struct definition is missing for ASN1_VALUE_st at address <addr> (no fields found)` |
| `XXprUtil:1468` | 3 | `Struct definition is missing for ASN1_VALUE_st at address <addr> (no fields found)` |
| **Subtotal** | **39** | |

Note: The astcmds message indicates missing types for local variables. This condition is
checked only if no other error messages were generated.


### UNSUPPORTED

| Location `[File:line]` | Error count | Representative message |
|---|---:|---|
| `ARMCallOpcode:300` | 41 | `Indirect call not yet handled at address <addr>` |
| `ARMBranch:377` | 32 | `Conditional branch without inferred branch condition at address <addr>` |
| `ARMLoadRegister:258` | 31 | `LDR: Indirect call via Load to PC not yet handled at <addr>` |
| `XXprUtil:1104` | 22 | `AST def conversion of variable <reg>_val_... to lval-expression at address <addr> not yet supported` |
| `XXprUtil:344` | 21 | `Non-struct pointer type unsigned char * not yet handled at <addr>` |
| `ARMOpcode:501` | 9 | `Conditional branch without inferred condition <addr>` |
| `XXprUtil:1501` | 6 | `Address expression (R3 - 0x1) with operator minus not yet supported at <addr>` |
| `XXprUtil:691` | 5 | `Conversion of global variable <gv> access with offset <n> at address <addr> not yet supported` |
| `XXprUtil:610` | 4 | `Stack variable offset 2 of localstackvar_32 not yet handled at address <addr>` |
| `XXprUtil:958` | 3 | `AST def conversion of initial memory value ... that may have changed reverted to original variable at <addr>` |
| `ARMAdd:263` | 2 | `ADD: aggregate jumptable at address <addr> not yet handled` |
| `XXprUtil:685` | 2 | `Conversion of global variable with address <addr> and offset [R0] at address <addr> not yet supported` |
| `XXprUtil:517` | 1 | `AST conversion of memory variable stack: not in global symbol table not yet supported at address <addr>` |
| `XXprUtil:1685` | 1 | `Stack variable with offset -26 not yet supported at address <addr>` |
| `XXprUtil:1665` | 1 | `No stack varinfo found at offset -48 at address <addr>` |
| **Subtotal** | **181** | |

### INTERNAL

| Location `[File:line]` | Error count | Representative message |
|---|---:|---|
| `XXprUtil:1020` | 40 | `Rdef: <ssaval>_clobber has not yet been introduced at address <addr>` |
| `ASTIProvenance:481` | 30 | `Reaching definition address <val>_clobber for variable <reg> not found` |
| `ARMLoadRegister:283` | 9 | `LDR: Unable to use a C expression for rhs. Fall back to native byte-based address: ... at address <addr>` |
| `XXprUtil:239` | 7 | `Encountered constant-value boolean false at address <addr>` |
| `ARMStoreMultipleIncrementAfter:514` | 2 | `STM: Error value encountered in LHSs at address <addr>` |
| `XXprUtil:1209` | 2 | `AST def conversion of pointer expression encountered unexpected base expression (...) at address <addr>` |
| `ARMLoadRegisterByte:281` | 2 | `LDRB: Unable to use a C expression for rhs. Fall back to native byte-based address: ... at address <addr>` |
| `ARMStoreMultipleIncrementBefore:138` | 1 | `STMIB: Error value encountered at address <addr>` |
| `ARMLoadRegisterHalfword:274` | 1 | `LDRH: Unable to use a C expression for rhs. Fall back to native byte-based address: ... at address <addr>` |
| `ASTInterface:1207` | 1 | `Analysis generated an unknown register name: R1_R3 at address <addr>` (formerly an uncaught exception, see below) |
| `ARMLoadMultipleIncrementAfter:285` | 1 | `LDM: Error value encountered at address <addr>` |
| **Subtotal** | **96** | |


## Messages by source file

| Source file | Error count | Breakdown (category, count, per location) |
|---|---:|---|
| `crypto/asn1/a_bitstr.c` | 11 | `XXprUtil:1501` UNSUPPORTED(5), `XXprUtil:1020` INTERNAL(2), `ASTIProvenance:481` INTERNAL(2), `ARMStoreMultipleIncrementBefore:138` INTERNAL(1), `XXprUtil:1104` UNSUPPORTED(1) |
| `crypto/asn1/a_d2i_fp.c` | 8 | `XXprUtil:1104` UNSUPPORTED(4), `ASTIProvenance:481` INTERNAL(2), `ARMBranch:377` UNSUPPORTED(1), `ARMCallOpcode:300` UNSUPPORTED(1) |
| `crypto/asn1/a_enum.c` | 18 | `XXprUtil:1020` INTERNAL(6), `ARMOpcode:501` UNSUPPORTED(4), `ARMBranch:377` UNSUPPORTED(4), `ASTIProvenance:481` INTERNAL(2), `XXprUtil:1104` UNSUPPORTED(1), `XXprUtil:1501` UNSUPPORTED(1) |
| `crypto/asn1/a_gentm.c` | 5 | `ARMBranch:377` UNSUPPORTED(3), `ARMOpcode:501` UNSUPPORTED(1), `ARMStoreMultipleIncrementAfter:514` INTERNAL(1) |
| `crypto/asn1/a_mbstr.c` | 10 | `ARMCallOpcode:300` UNSUPPORTED(4), `ARMAdd:263` UNSUPPORTED(2), `XXprUtil:1104` UNSUPPORTED(2), `XXprUtil:517` UNSUPPORTED(1), `ARMBranch:377` UNSUPPORTED(1) |
| `crypto/asn1/ameth_lib.c` | 4 | `XXprUtil:685` UNSUPPORTED(2), `astcmds:425` TYPING(2) |
| `crypto/asn1/x_name.c` | 22 | `XXprUtil:1240` TYPING(6), `XXprUtil:1528` TYPING(6), `XXprUtil:1468` TYPING(3), `ARMLoadRegister:283` INTERNAL(3), `astcmds:425` TYPING(2), `XXprUtil:344` UNSUPPORTED(1), `ARMLoadRegisterHalfword:274` INTERNAL(1) |
| `crypto/evp/bio_b64.c` | 30 | `XXprUtil:1104` UNSUPPORTED(7), `ASTIProvenance:481` INTERNAL(6), `XXprUtil:1020` INTERNAL(5), `ARMBranch:377` UNSUPPORTED(5), `XXprUtil:1209` INTERNAL(2), `ARMOpcode:501` UNSUPPORTED(2), `XXprUtil:239` INTERNAL(2), `ASTInterface:1207` INTERNAL(1) |
| `crypto/evp/bio_enc.c` | 10 | `XXprUtil:1104` UNSUPPORTED(3), `ARMBranch:377` UNSUPPORTED(3), `ARMCallOpcode:300` UNSUPPORTED(2), `XXprUtil:1020` INTERNAL(1), `ASTIProvenance:481` INTERNAL(1) |
| `crypto/evp/evp_lib.c` | 10 | `ARMBranch:377` UNSUPPORTED(6), `ARMCallOpcode:300` UNSUPPORTED(2), `ARMLoadRegister:258` UNSUPPORTED(1), `astcmds:425` TYPING(1) |
| `crypto/evp/names.c` | 4 | `ARMLoadRegister:258` UNSUPPORTED(4) |
| `crypto/evp/p_lib.c` | 14 | `ARMCallOpcode:300` UNSUPPORTED(13), `XXprUtil:239` INTERNAL(1) |
| `crypto/evp/pmeth_lib.c` | 8 | `ARMCallOpcode:300` UNSUPPORTED(4), `XXprUtil:958` UNSUPPORTED(3), `ARMLoadRegister:258` UNSUPPORTED(1) |
| `crypto/rand/rand_lib.c` | 8 | `ARMCallOpcode:300` UNSUPPORTED(6), `XXprUtil:1020` INTERNAL(1), `ASTIProvenance:481` INTERNAL(1) |
| `crypto/ui/ui_lib.c` | 18 | `ARMCallOpcode:300` UNSUPPORTED(7), `astcmds:425` TYPING(7), `ASTIProvenance:481` INTERNAL(2), `XXprUtil:1684` UNSUPPORTED(1), `ARMLoadMultipleIncrementAfter:285` INTERNAL(1) |
| `crypto/x509/x509_cmp.c` | 7 | `astcmds:425` TYPING(4), `XXprUtil:610` UNSUPPORTED(3) |
| `crypto/x509/x509_def.c` | 0 | (no pending-errors/pending-typing functions) |
| `crypto/x509/x509_vfy.c` | 78 | `ARMLoadRegister:258` UNSUPPORTED(24), `XXprUtil:344` UNSUPPORTED(12), `XXprUtil:1020` INTERNAL(8), `ARMLoadRegister:283` INTERNAL(6), `ASTIProvenance:481` INTERNAL(5), `ARMBranch:377` UNSUPPORTED(5), `XXprUtil:691` UNSUPPORTED(5), `astcmds:425` TYPING(4), `XXprUtil:239` INTERNAL(3), `ARMCallOpcode:300` UNSUPPORTED(2), `ARMOpcode:501` UNSUPPORTED(2), `XXprUtil:1104` UNSUPPORTED(1), `XXprUtil:610` UNSUPPORTED(1) |
| `crypto/x509/x509_vpm.c` | 5 | `astcmds:425` TYPING(2), `XXprUtil:1665` UNSUPPORTED(1), `XXprUtil:1104` UNSUPPORTED(1), `XXprUtil:239` INTERNAL(1) |
| `crypto/x509v3/v3_purp.c` | 60 | `XXprUtil:1020` INTERNAL(17), `ARMCallOpcode:513` USERDATA(14), `ASTIProvenance:481` INTERNAL(9), `XXprUtil:344` UNSUPPORTED(8), `ARMBranch:377` UNSUPPORTED(4), `ARMLoadRegisterByte:281` INTERNAL(2), `XXprUtil:1104` UNSUPPORTED(2), `astcmds:425` TYPING(2), `ARMStoreMultipleIncrementAfter:514` INTERNAL(1), `ARMLoadRegister:258` UNSUPPORTED(1) |
| **Total** | **330** | |

## Observations

- **Missing features:** Indirect calls (`ARMCallOpcode:300` and
  `ARMLoadRegister:258`) and unresolved conditions for conditional
  branches (`ARMBranch:377` and `ARMOpcode:501`) are the most
  frequently occurring constructs not yet supported with 72 and
  41 error messages reported resp.
- **Reaching definitions:** Reaching definitiions are the most frequent
  cause for internal invariant violations, in particular the perceived
  reaching definition of a register clobbered by a function call. The
  reason is that reaching definitions are computed on the control
  flow graph without taking into account branch conditions, and thus
  are an over-approximation of the actual set of reaching definitions,
  sometimes giving rise to reaching definitions from infeasible paths.