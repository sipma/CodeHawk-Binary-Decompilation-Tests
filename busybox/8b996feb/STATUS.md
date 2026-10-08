# Lifting Status -- Busybox 8b996feb

Per-source-file breakdown of function lifting results. 

<!-- status-table:begin -->
| Source file | Analyzed | Lifted | Errors | Typing | Other Issues |
|---|---:|---:|---:|---:|---:|
| `libbb/bb_pwd.c` | 11 | 10 | 1 | 0 | 0 |
| `libbb/bb_strtonum.c` | 5 | 0 | 2 | 2 | 1 |
| `libbb/copyfd.c` | 4 | 1 | 2 | 1 | 0 |
| `libbb/procps.c` | 13 | 6 | 3 | 3 | 1 |
| `libbb/xfuncs.c` | 18 | 8 | 7 | 1 | 2 |
| `libbb/xfuncs_printf.c` | 43 | 36 | 2 | 4 | 1 |
| `miscutils/less.c` | 21 | 2 | 13 | 1 | 5 |
| `networking/udhcp/common.c` | 7 | 0 | 2 | 2 | 3 |
| `networking/udhcp/domain_codec.c` | 2 | 1 | 1 | 0 | 0 |
| **Total** | **124** | **64** | **33** | **14** | **13** |
| **Percent** | | 52% | 27% | 11% | 10% |
<!-- status-table:end -->
