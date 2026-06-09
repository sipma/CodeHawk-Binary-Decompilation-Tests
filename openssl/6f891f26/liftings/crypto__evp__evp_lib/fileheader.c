#include "../../shareddata/header.c"

// crypto/evp/evp_lib.c

int EVP_CIPHER_param_to_asn1(struct evp_cipher_ctx_st * c, struct asn1_type_st * type)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",64), chkx_binloc("0xcd16c") ));

int EVP_CIPHER_asn1_to_param(struct evp_cipher_ctx_st * c, struct asn1_type_st * type)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",77), chkx_binloc("0xcd24c") ));

int EVP_CIPHER_get_asn1_iv(struct evp_cipher_ctx_st * c, struct asn1_type_st * type)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",90), chkx_binloc("0xcd1ac") ));

int EVP_CIPHER_set_asn1_iv(struct evp_cipher_ctx_st * c, struct asn1_type_st * type)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",108), chkx_binloc("0xcd0f4") ));

int EVP_CIPHER_type(const struct evp_cipher_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",123), chkx_binloc("0xccf98") ));

int EVP_CIPHER_block_size(const struct evp_cipher_st * e)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",181), chkx_binloc("0xcce20") ));

int EVP_CIPHER_CTX_block_size(const struct evp_cipher_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",186), chkx_binloc("0xcce28") ));

int EVP_Cipher(struct evp_cipher_ctx_st * ctx, unsigned char * out, const unsigned char * in, unsigned int inl)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",191), chkx_binloc("0xcce34") ));

const struct evp_cipher_st * EVP_CIPHER_CTX_cipher(const struct evp_cipher_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",196), chkx_binloc("0xcce50") ));

unsigned long EVP_CIPHER_flags(const struct evp_cipher_st * cipher)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",201), chkx_binloc("0xcce58") ));

unsigned long EVP_CIPHER_CTX_flags(const struct evp_cipher_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",206), chkx_binloc("0xcce60") ));

void * EVP_CIPHER_CTX_get_app_data(const struct evp_cipher_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",211), chkx_binloc("0xcce6c") ));

void EVP_CIPHER_CTX_set_app_data(struct evp_cipher_ctx_st * ctx, void * data)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",216), chkx_binloc("0xcce74") ));

int EVP_CIPHER_iv_length(const struct evp_cipher_st * cipher)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",221), chkx_binloc("0xcce7c") ));

int EVP_CIPHER_CTX_iv_length(const struct evp_cipher_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",226), chkx_binloc("0xcce84") ));

int EVP_CIPHER_key_length(const struct evp_cipher_st * cipher)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",231), chkx_binloc("0xcce90") ));

int EVP_CIPHER_CTX_key_length(const struct evp_cipher_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",236), chkx_binloc("0xcce98") ));

int EVP_CIPHER_nid(const struct evp_cipher_st * cipher)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",241), chkx_binloc("0xccea0") ));

int EVP_CIPHER_CTX_nid(const struct evp_cipher_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",246), chkx_binloc("0xccea8") ));

int EVP_MD_block_size(const struct env_md_st * md)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",251), chkx_binloc("0xcceb4") ));

int EVP_MD_type(const struct env_md_st * md)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",256), chkx_binloc("0xccebc") ));

int EVP_MD_pkey_type(const struct env_md_st * md)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",261), chkx_binloc("0xccec4") ));

int EVP_MD_size(const struct env_md_st * md)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",266), chkx_binloc("0xccf40") ));

unsigned long EVP_MD_flags(const struct env_md_st * md)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",276), chkx_binloc("0xccecc") ));

const struct env_md_st * EVP_MD_CTX_md(const struct env_md_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",281), chkx_binloc("0xcced4") ));

void EVP_MD_CTX_set_flags(struct env_md_ctx_st * ctx, int flags)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",288), chkx_binloc("0xccee0") ));

void EVP_MD_CTX_clear_flags(struct env_md_ctx_st * ctx, int flags)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",293), chkx_binloc("0xccef0") ));

int EVP_MD_CTX_test_flags(const struct env_md_ctx_st * ctx, int flags)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",298), chkx_binloc("0xccf04") ));

void EVP_CIPHER_CTX_set_flags(struct evp_cipher_ctx_st * ctx, int flags)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",303), chkx_binloc("0xccf10") ));

void EVP_CIPHER_CTX_clear_flags(struct evp_cipher_ctx_st * ctx, int flags)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",308), chkx_binloc("0xccf20") ));

int EVP_CIPHER_CTX_test_flags(const struct evp_cipher_ctx_st * ctx, int flags)
   __attribute__ (( chkc_srcloc("crypto/evp/evp_lib.c",313), chkx_binloc("0xccf34") ));

