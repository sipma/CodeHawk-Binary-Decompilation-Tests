# Lifting Status -- OpenSSL libcrypto 6f891f26

Per-source-file breakdown of function lifting results.

<!-- status-table:begin -->
| Source file | Analyzed | Lifted | Errors | Typing | Other Issues |
|---|---:|---:|---:|---:|---:|
| `crypto/asn1/a_bitstr.c` | 6 | 3 | 3 | 0 | 0 |
| `crypto/asn1/a_d2i_fp.c` | 5 | 3 | 2 | 0 | 0 |
| `crypto/asn1/a_enum.c` | 4 | 1 | 2 | 0 | 1 |
| `crypto/asn1/a_gentm.c` | 4 | 2 | 2 | 0 | 0 |
| `crypto/asn1/a_mbstr.c` | 9 | 5 | 1 | 0 | 3 |
| `crypto/asn1/ameth_lib.c` | 18 | 2 | 0 | 3 | 13 |
| `crypto/asn1/x_name.c` | 20 | 2 | 3 | 2 | 13 |
| `crypto/evp/bio_b64.c` | 8 | 3 | 3 | 0 | 2 |
| `crypto/evp/bio_enc.c` | 8 | 1 | 3 | 0 | 4 |
| `crypto/evp/evp_lib.c` | 31 | 24 | 4 | 1 | 2 |
| `crypto/evp/names.c` | 11 | 3 | 2 | 0 | 6 |
| `crypto/evp/p_lib.c` | 29 | 10 | 12 | 0 | 7 |
| `crypto/evp/pmeth_lib.c` | 37 | 28 | 7 | 0 | 2 |
| `crypto/rand/rand_lib.c` | 9 | 2 | 6 | 0 | 1 |
| `crypto/ui/ui_lib.c` | 53 | 13 | 3 | 7 | 30 |
| `crypto/x509/x509_cmp.c` | 22 | 13 | 1 | 4 | 4 |
| `crypto/x509/x509_def.c` | 6 | 6 | 0 | 0 | 0 |
| `crypto/x509/x509_vfy.c` | 50 | 31 | 13 | 4 | 2 |
| `crypto/x509/x509_vpm.c` | 20 | 12 | 1 | 3 | 4 |
| `crypto/x509v3/v3_purp.c` | 29 | 7 | 7 | 2 | 13 |
| **Total** | **379** | **171** | **75** | **26** | **107** |
| **Percent** | | 45% | 20% | 7% | 28% |
<!-- status-table:end -->
