#include "../../shareddata/header.c"

// crypto/evp/p_lib.c

int EVP_PKEY_bits(struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",85), chkx_binloc("0xca028") ));

int EVP_PKEY_size(struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",92), chkx_binloc("0xca064") ));

int EVP_PKEY_save_parameters(struct evp_pkey_st * pkey, int mode)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",99), chkx_binloc("0xca0a0") ));

int EVP_PKEY_copy_parameters(struct evp_pkey_st * to, const struct evp_pkey_st * from)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",124), chkx_binloc("0xca3a4") ));

int EVP_PKEY_missing_parameters(const struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",143), chkx_binloc("0xca0d4") ));

int EVP_PKEY_cmp_parameters(const struct evp_pkey_st * a, const struct evp_pkey_st * b)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",150), chkx_binloc("0xca108") ));

int EVP_PKEY_cmp(const struct evp_pkey_st * a, const struct evp_pkey_st * b)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",159), chkx_binloc("0xca158") ));

struct evp_pkey_st * EVP_PKEY_new(void)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",182), chkx_binloc("0xca5fc") ));

int pkey_set_type(struct evp_pkey_st * pkey, int type, const char * str, int len)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",207), chkx_binloc("0xca688") ));

int EVP_PKEY_set_type(struct evp_pkey_st * pkey, int type)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",253), chkx_binloc("0xca7f0") ));

int EVP_PKEY_set_type_str(struct evp_pkey_st * pkey, const char * str, int len)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",258), chkx_binloc("0xca7e0") ));

int EVP_PKEY_assign(struct evp_pkey_st * pkey, int type, void * key)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",263), chkx_binloc("0xca7fc") ));

void * EVP_PKEY_get0(struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",271), chkx_binloc("0xca1d0") ));

int EVP_PKEY_set1_RSA(struct evp_pkey_st * pkey, struct rsa_st * key)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",277), chkx_binloc("0xca8c8") ));

struct rsa_st * EVP_PKEY_get1_RSA(struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",285), chkx_binloc("0xca598") ));

int EVP_PKEY_set1_DSA(struct evp_pkey_st * pkey, struct dsa_st * key)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",297), chkx_binloc("0xca894") ));

struct dsa_st * EVP_PKEY_get1_DSA(struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",305), chkx_binloc("0xca534") ));

int EVP_PKEY_set1_EC_KEY(struct evp_pkey_st * pkey, struct ec_key_st * key)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",318), chkx_binloc("0xca860") ));

struct ec_key_st * EVP_PKEY_get1_EC_KEY(struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",326), chkx_binloc("0xca4cc") ));

int EVP_PKEY_set1_DH(struct evp_pkey_st * pkey, struct dh_st * key)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",341), chkx_binloc("0xca82c") ));

struct dh_st * EVP_PKEY_get1_DH(struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",349), chkx_binloc("0xca468") ));

int EVP_PKEY_type(int type)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",360), chkx_binloc("0xca360") ));

int EVP_PKEY_id(const struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",377), chkx_binloc("0xca1d8") ));

int EVP_PKEY_base_id(const struct evp_pkey_st * pkey)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",382), chkx_binloc("0xca39c") ));

void EVP_PKEY_free(struct evp_pkey_st * x)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",387), chkx_binloc("0xca2a0") ));

void EVP_PKEY_free_it(struct evp_pkey_st * x)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",411) ));

int unsup_alg(struct bio_st * out, const struct evp_pkey_st * pkey, int indent, const char * kstr)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",427) ));

int EVP_PKEY_print_public(struct bio_st * out, const struct evp_pkey_st * pkey, int indent, struct asn1_pctx_st * pctx)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",436), chkx_binloc("0xca220") ));

int EVP_PKEY_print_private(struct bio_st * out, const struct evp_pkey_st * pkey, int indent, struct asn1_pctx_st * pctx)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",445), chkx_binloc("0xca97c") ));

int EVP_PKEY_print_params(struct bio_st * out, const struct evp_pkey_st * pkey, int indent, struct asn1_pctx_st * pctx)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",454), chkx_binloc("0xca8fc") ));

int EVP_PKEY_get_default_digest_nid(struct evp_pkey_st * pkey, int * pnid)
   __attribute__ (( chkc_srcloc("crypto/evp/p_lib.c",462), chkx_binloc("0xca1e0") ));

