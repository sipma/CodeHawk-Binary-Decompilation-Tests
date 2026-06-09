#include "../../shareddata/header.c"

int memcmp(void *a, void *b, size_t size);

// crypto/x509/x509_cmp.c

int X509_issuer_and_serial_cmp(const struct x509_st * a, const struct x509_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",67), chkx_binloc("0xf3d38") ));

unsigned long X509_issuer_and_serial_hash(struct x509_st * a)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",80), chkx_binloc("0xf3c50") ));

int X509_issuer_name_cmp(const struct x509_st * a, const struct x509_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",108), chkx_binloc("0xf3bec") ));

int X509_subject_name_cmp(const struct x509_st * a, const struct x509_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",113), chkx_binloc("0xf3bd8") ));

int X509_CRL_cmp(const struct X509_crl_st * a, const struct X509_crl_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",118), chkx_binloc("0xf3bc4") ));

int X509_CRL_match(const struct X509_crl_st * a, const struct X509_crl_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",124), chkx_binloc("0xf3c00") ));

struct X509_name_st * X509_get_issuer_name(struct x509_st * a)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",130), chkx_binloc("0xf3830") ));

unsigned long X509_issuer_name_hash(struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",135), chkx_binloc("0xf3abc") ));

unsigned long X509_issuer_name_hash_old(struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",141), chkx_binloc("0xf3a38") ));

struct X509_name_st * X509_get_subject_name(struct x509_st * a)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",147), chkx_binloc("0xf383c") ));

struct asn1_string_st * X509_get_serialNumber(struct x509_st * a)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",152), chkx_binloc("0xf3848") ));

unsigned long X509_subject_name_hash(struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",157), chkx_binloc("0xf3ab0") ));

unsigned long X509_subject_name_hash_old(struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",163), chkx_binloc("0xf3a2c") ));

int X509_cmp(const struct x509_st * a, const struct x509_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",179), chkx_binloc("0xf3c10") ));

int X509_NAME_cmp(const struct X509_name_st * a, const struct X509_name_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",190), chkx_binloc("0xf3ac8") ));

unsigned long X509_NAME_hash(struct X509_name_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",219), chkx_binloc("0xf3a44") ));

unsigned long X509_NAME_hash_old(struct X509_name_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",241), chkx_binloc("0xf3974") ));

struct x509_st * X509_find_by_issuer_and_serial(struct stack_st_X509 * sk, struct X509_name_st * name, struct asn1_string_st * serial)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",264), chkx_binloc("0xf3d78") ));

struct x509_st * X509_find_by_subject(struct stack_st_X509 * sk, struct X509_name_st * name)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",286), chkx_binloc("0xf3b64") ));

struct evp_pkey_st * X509_get_pubkey(struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",300), chkx_binloc("0xf3868") ));

struct asn1_string_st * X509_get0_pubkey_bitstr(const struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",307), chkx_binloc("0xf3854") ));

int X509_check_private_key(struct x509_st * x, struct evp_pkey_st * k)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_cmp.c",313), chkx_binloc("0xf388c") ));

