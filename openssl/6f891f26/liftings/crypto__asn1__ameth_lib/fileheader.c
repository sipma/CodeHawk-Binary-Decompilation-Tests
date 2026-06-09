#include "../../shareddata/header.c"

// crypto/asn1/ameth_lib.c

// static and global variable definitions

const struct evp_pkey_asn1_method_st * standard_methods[11];

struct stack_st_EVP_PKEY_ASN1_METHOD * app_methods
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",100) ));


/*
DECLARE_OBJ_BSEARCH_CMP_FN(const EVP_PKEY_ASN1_METHOD *,
			   const EVP_PKEY_ASN1_METHOD *, ameth);
IMPLEMENT_OBJ_BSEARCH_CMP_FN(const EVP_PKEY_ASN1_METHOD *,
			     const EVP_PKEY_ASN1_METHOD *, ameth);
*/

// function signatures

int ameth_cmp(const const struct evp_pkey_asn1_method_st * * a, const const struct evp_pkey_asn1_method_st * * b)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",120), chkx_binloc("0xe26e4") ));

int ameth_cmp_BSEARCH_CMP_FN(const void * a_, const void * b_)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",126), chkx_binloc("0xe26fc") ));

const struct evp_pkey_asn1_method_st * * OBJ_bsearch_ameth(const struct evp_pkey_asn1_method_st * * key, const const struct evp_pkey_asn1_method_st * * base, int num)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",126) ));

int EVP_PKEY_asn1_get_count(void)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",129), chkx_binloc("0xe2bf0") ));

const struct evp_pkey_asn1_method_st * EVP_PKEY_asn1_get0(int idx)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",137), chkx_binloc("0xe2aac") ));

const struct evp_pkey_asn1_method_st * pkey_asn1_find(int type)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",148) ));

const struct evp_pkey_asn1_method_st * EVP_PKEY_asn1_find(struct engine_st * * pe, int type)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",174), chkx_binloc("0xe2af4") ));

const struct evp_pkey_asn1_method_st * EVP_PKEY_asn1_find_str(struct engine_st * * pe, const char * str, int len)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",202), chkx_binloc("0xe2c28") ));

int EVP_PKEY_asn1_add0(const struct evp_pkey_asn1_method_st * ameth)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",240), chkx_binloc("0xe2a08") ));

int EVP_PKEY_asn1_add_alias(int to, int from)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",254), chkx_binloc("0xe2a7c") ));

int EVP_PKEY_asn1_get0_info(int * ppkey_id, int * ppkey_base_id, int * ppkey_flags, const char * * pinfo, const char * * ppem_str, const struct evp_pkey_asn1_method_st * ameth)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",264), chkx_binloc("0xe2714") ));

const struct evp_pkey_asn1_method_st * EVP_PKEY_get0_asn1(struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",283), chkx_binloc("0xe277c") ));

struct evp_pkey_asn1_method_st * EVP_PKEY_asn1_new(int id, int flags, const char * pem_str, const char * info)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",288), chkx_binloc("0xe28ec") ));

void EVP_PKEY_asn1_copy(struct evp_pkey_asn1_method_st * dst, const struct evp_pkey_asn1_method_st * src)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",357), chkx_binloc("0xe2784") ));

void EVP_PKEY_asn1_free(struct evp_pkey_asn1_method_st * ameth)
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",391), chkx_binloc("0xe28a8") ));

void EVP_PKEY_asn1_set_public(struct evp_pkey_asn1_method_st * ameth, int (*pub_decode)(struct evp_pkey_st * pk, struct X509_pubkey_st * pub), int (*pub_encode)(struct X509_pubkey_st * pub, const struct evp_pkey_st * pk), int (*pub_cmp)(const struct evp_pkey_st * a, const struct evp_pkey_st * b), int (*pub_print)(struct bio_st * out, const struct evp_pkey_st * pkey, int indent, struct asn1_pctx_st * pctx), int (*pkey_size)(const struct evp_pkey_st * pk), int (*pkey_bits)(const struct evp_pkey_st * pk))
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",403), chkx_binloc("0xe2838") ));

void EVP_PKEY_asn1_set_private(struct evp_pkey_asn1_method_st * ameth, int (*priv_decode)(struct evp_pkey_st * pk, struct pkcs8_priv_key_info_st * p8inf), int (*priv_encode)(struct pkcs8_priv_key_info_st * p8, const struct evp_pkey_st * pk), int (*priv_print)(struct bio_st * out, const struct evp_pkey_st * pkey, int indent, struct asn1_pctx_st * pctx))
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",420), chkx_binloc("0xe2860") ));

void EVP_PKEY_asn1_set_param(struct evp_pkey_asn1_method_st * ameth, int (*param_decode)(struct evp_pkey_st * pkey, const unsigned char * * pder, int derlen), int (*param_encode)(const struct evp_pkey_st * pkey, unsigned char * * pder), int (*param_missing)(const struct evp_pkey_st * pk), int (*param_copy)(struct evp_pkey_st * to, const struct evp_pkey_st * from), int (*param_cmp)(const struct evp_pkey_st * a, const struct evp_pkey_st * b), int (*param_print)(struct bio_st * out, const struct evp_pkey_st * pkey, int indent, struct asn1_pctx_st * pctx))
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",431), chkx_binloc("0xe2870") ));

void EVP_PKEY_asn1_set_free(struct evp_pkey_asn1_method_st * ameth, void (*pkey_free)(struct evp_pkey_st * pkey))
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",449), chkx_binloc("0xe2898") ));

void EVP_PKEY_asn1_set_ctrl(struct evp_pkey_asn1_method_st * ameth, int (*pkey_ctrl)(struct evp_pkey_st * pkey, int op, long arg1, void * arg2))
   __attribute__ (( chkc_srcloc("crypto/asn1/ameth_lib.c",455), chkx_binloc("0xe28a0") ));

