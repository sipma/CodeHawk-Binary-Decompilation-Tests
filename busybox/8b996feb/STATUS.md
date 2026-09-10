# Lifting Status -- Busybox 8b996feb

Per-source-file breakdown of function lifting results. The columns show the
following:
- **Analyzed:** the number of functions analyzed for each file. For most files
   this is the total number of functions in the binary from that file.
- **Lifted:** the number of functions that were successfully lifted. A function
   is considered successfully lifted if: (1) no errors were generated
   during lifting, (2) all local variables are typed, (3) the function
   is parsed (syntactically) by gcc without errors, and (4) semantics
   were confirmed via manual inspection.
- **Errors:** the number of functions that produced error messages during
   lifting
- **Typing:** the number of functions that lifted without errors, but that
   include one or more local variables without type
- **Other:** the number of functions for which gcc parsing failed or that
   have semantic issues identified by manual inspection.


| Source file | Analyzed | Lifted | Errors | Typing | Other Issues |
|---|---:|---:|---:|---:|---:|
| `libbb/bb_pwd.c` | 11 | 10 | 1 | 0 | 0 |
| `libbb/bb_strtonum.c` | 5 | 0 | 2 | 2 | 1 |
| `libbb/copyfd.c` | 4 | 1 | 2 | 1 | 0 |
| `libbb/procps.c` | 13 | 6 | 3 | 3 | 1 |
| `libbb/xfuncs_printf.c` | 44 | 31 | 5 | 6 | 2 |
| `libbb/xfuncs.c` | 18 | 5 | 8 | 1 | 4 |
| `miscutils/less.c` | 21 | 2 | 13 | 1 | 5 |
| `networking/udhcp/common.c` | 7 | 0 | 3 | 2 | 2 |
| `networking/udhcp/domain_codec.c` | 2 | 0 | 1 | 1 | 0 |
| **Total** | **125** | **55** | **38** | **17** | **15** |
| **Percent** | | 44% | 30% | 14% | 12% |
