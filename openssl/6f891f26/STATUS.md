# Lifting Status -- OpenSSL libcrypto 6f891f26

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
| `crypto/asn1/a_bitstr.c` | 6 | 3 | 3 | 0 | 0 |
| `crypto/asn1/a_d2i_fp.c` | 5 | 3 | 2 | 0 | 0 |
| `crypto/asn1/a_enum.c` | 4 | 1 | 2 | 0 | 1 |
| `crypto/asn1/a_gentm.c` | 4 | 2 | 2 | 0 | 0 |
| `crypto/asn1/a_mbstr.c` | 9 | 5 | 1 | 0 | 3 |
| `crypto/asn1/ameth_lib.c` | 18 | 2 | 2 | 2 | 12 |
| `crypto/asn1/x_name.c` | 20 | 2 | 3 | 2 | 13 |
| `crypto/evp/bio_b64.c` | 8 | 2 | 4 | 0 | 2 |
| `crypto/evp/bio_enc.c` | 8 | 1 | 3 | 0 | 4 |
| `crypto/evp/evp_lib.c` | 31 | 24 | 4 | 1 | 2 |
| `crypto/evp/names.c` | 11 | 3 | 2 | 0 | 6 |
| `crypto/evp/p_lib.c` | 29 | 10 | 12 | 0 | 7 |
| `crypto/evp/pmeth_lib.c` | 37 | 28 | 7 | 0 | 2 |
| `crypto/rand/rand_lib.c` | 9 | 1 | 7 | 0 | 1 |
| `crypto/ui/ui_lib.c` | 53 | 13 | 3 | 7 | 30 |
| `crypto/x509v3/v3_purp.c` | 29 | 7 | 8 | 2 | 12 |
| `crypto/x509/x509_cmp.c` | 22 | 13 | 1 | 4 | 4 |
| `crypto/x509/x509_def.c` | 6 | 6 | 0 | 0 | 0 |
| `crypto/x509/x509_vfy.c` | 50 | 31 | 13 | 4 | 2 |
| `crypto/x509/x509_vpm.c` | 20 | 12 | 3 | 2 | 3 |
| **Total** | **379** | **169** | **82** | **24** | **104** |
| **Percent** | | 45% | 22% | 6% | 27% |
