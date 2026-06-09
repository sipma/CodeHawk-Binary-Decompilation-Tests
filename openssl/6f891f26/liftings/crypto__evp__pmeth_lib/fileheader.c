#include "../../shareddata/header.c"

// crypto/evp/pmeth_lib.c

// IMPLEMENT_OBJ_BSEARCH_CMP_FN(const EVP_PKEY_METHOD *, const EVP_PKEY_METHOD *,
//			     pmeth);

// static and global variable definitions

struct stack_st_EVP_PKEY_METHOD * app_pkey_methods
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",73) ));

const struct evp_pkey_method_st * standard_methods[6];


DECLARE_STACK_OF(EVP_PKEY_METHOD)
STACK_OF(EVP_PKEY_METHOD) *app_pkey_methods;

typedef EVP_PKEY_METHOD **ppEVP_PKEY_METHOD;


// function signatures

int pmeth_cmp(const const struct evp_pkey_method_st * * a, const const struct evp_pkey_method_st * * b)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",99), chkx_binloc("0xcf130") ));

int pmeth_cmp_BSEARCH_CMP_FN(const void * a_, const void * b_)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",105), chkx_binloc("0xcf148") ));

const struct evp_pkey_method_st * * OBJ_bsearch_pmeth(const struct evp_pkey_method_st * * key, const const struct evp_pkey_method_st * * base, int num)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",105) ));

const struct evp_pkey_method_st * EVP_PKEY_meth_find(int type)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",108), chkx_binloc("0xcf880") ));

struct evp_pkey_ctx_st * int_ctx_new(struct evp_pkey_st * pkey, struct engine_st * e, int id)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",127), chkx_binloc("0xcf910") ));

struct evp_pkey_method_st * EVP_PKEY_meth_new(int id, int flags)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",200), chkx_binloc("0xcf7c0") ));

void EVP_PKEY_meth_get0_info(int * ppkey_id, int * pflags, const struct evp_pkey_method_st * meth)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",241), chkx_binloc("0xcf160") ));

void EVP_PKEY_meth_copy(struct evp_pkey_method_st * dst, const struct evp_pkey_method_st * src)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",250), chkx_binloc("0xcf17c") ));

void EVP_PKEY_meth_free(struct evp_pkey_method_st * pmeth)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",291), chkx_binloc("0xcf5c8") ));

struct evp_pkey_ctx_st * EVP_PKEY_CTX_new(struct evp_pkey_st * pkey, struct engine_st * e)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",297), chkx_binloc("0xcfaf4") ));

struct evp_pkey_ctx_st * EVP_PKEY_CTX_new_id(int id, struct engine_st * e)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",302), chkx_binloc("0xcfae8") ));

struct evp_pkey_ctx_st * EVP_PKEY_CTX_dup(struct evp_pkey_ctx_st * pctx)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",307), chkx_binloc("0xcf664") ));

int EVP_PKEY_meth_add0(const struct evp_pkey_method_st * pmeth)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",351), chkx_binloc("0xcf5e0") ));

void EVP_PKEY_CTX_free(struct evp_pkey_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",365), chkx_binloc("0xcf564") ));

int EVP_PKEY_CTX_ctrl(struct evp_pkey_ctx_st * ctx, int keytype, int optype, int cmd, int p1, void * p2)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",384), chkx_binloc("0xcf324") ));

int EVP_PKEY_CTX_ctrl_str(struct evp_pkey_ctx_st * ctx, const char * name, const char * value)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",417), chkx_binloc("0xcf468") ));

int EVP_PKEY_CTX_get_operation(struct evp_pkey_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",440), chkx_binloc("0xcf244") ));

void EVP_PKEY_CTX_set0_keygen_info(struct evp_pkey_ctx_st * ctx, int * dat, int datlen)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",445), chkx_binloc("0xcf24c") ));

void EVP_PKEY_CTX_set_data(struct evp_pkey_ctx_st * ctx, void * data)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",451), chkx_binloc("0xcf258") ));

void * EVP_PKEY_CTX_get_data(struct evp_pkey_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",456), chkx_binloc("0xcf260") ));

struct evp_pkey_st * EVP_PKEY_CTX_get0_pkey(struct evp_pkey_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",461), chkx_binloc("0xcf268") ));

struct evp_pkey_st * EVP_PKEY_CTX_get0_peerkey(struct evp_pkey_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",466), chkx_binloc("0xcf270") ));

void EVP_PKEY_CTX_set_app_data(struct evp_pkey_ctx_st * ctx, void * data)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",471), chkx_binloc("0xcf278") ));

void * EVP_PKEY_CTX_get_app_data(struct evp_pkey_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",476), chkx_binloc("0xcf280") ));

void EVP_PKEY_meth_set_init(struct evp_pkey_method_st * pmeth, int (*init)(struct evp_pkey_ctx_st * ctx))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",481), chkx_binloc("0xcf288") ));

void EVP_PKEY_meth_set_copy(struct evp_pkey_method_st * pmeth, int (*copy)(struct evp_pkey_ctx_st * dst, struct evp_pkey_ctx_st * src))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",487), chkx_binloc("0xcf290") ));

void EVP_PKEY_meth_set_cleanup(struct evp_pkey_method_st * pmeth, void (*cleanup)(struct evp_pkey_ctx_st * ctx))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",493), chkx_binloc("0xcf298") ));

void EVP_PKEY_meth_set_paramgen(struct evp_pkey_method_st * pmeth, int (*paramgen_init)(struct evp_pkey_ctx_st * ctx), int (*paramgen)(struct evp_pkey_ctx_st * ctx, struct evp_pkey_st * pkey))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",499), chkx_binloc("0xcf2a0") ));

void EVP_PKEY_meth_set_keygen(struct evp_pkey_method_st * pmeth, int (*keygen_init)(struct evp_pkey_ctx_st * ctx), int (*keygen)(struct evp_pkey_ctx_st * ctx, struct evp_pkey_st * pkey))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",507), chkx_binloc("0xcf2ac") ));

void EVP_PKEY_meth_set_sign(struct evp_pkey_method_st * pmeth, int (*sign_init)(struct evp_pkey_ctx_st * ctx), int (*sign)(struct evp_pkey_ctx_st * ctx, unsigned char * sig, unsigned long * siglen, const unsigned char * tbs, unsigned long tbslen))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",515), chkx_binloc("0xcf2b8") ));

void EVP_PKEY_meth_set_verify(struct evp_pkey_method_st * pmeth, int (*verify_init)(struct evp_pkey_ctx_st * ctx), int (*verify)(struct evp_pkey_ctx_st * ctx, const unsigned char * sig, unsigned long siglen, const unsigned char * tbs, unsigned long tbslen))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",524), chkx_binloc("0xcf2c4") ));

void EVP_PKEY_meth_set_verify_recover(struct evp_pkey_method_st * pmeth, int (*verify_recover_init)(struct evp_pkey_ctx_st * ctx), int (*verify_recover)(struct evp_pkey_ctx_st * ctx, unsigned char * sig, unsigned long * siglen, const unsigned char * tbs, unsigned long tbslen))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",533), chkx_binloc("0xcf2d0") ));

void EVP_PKEY_meth_set_signctx(struct evp_pkey_method_st * pmeth, int (*signctx_init)(struct evp_pkey_ctx_st * ctx, struct env_md_ctx_st * mctx), int (*signctx)(struct evp_pkey_ctx_st * ctx, unsigned char * sig, unsigned long * siglen, struct env_md_ctx_st * mctx))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",543), chkx_binloc("0xcf2dc") ));

void EVP_PKEY_meth_set_verifyctx(struct evp_pkey_method_st * pmeth, int (*verifyctx_init)(struct evp_pkey_ctx_st * ctx, struct env_md_ctx_st * mctx), int (*verifyctx)(struct evp_pkey_ctx_st * ctx, const unsigned char * sig, int siglen, struct env_md_ctx_st * mctx))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",552), chkx_binloc("0xcf2e8") ));

void EVP_PKEY_meth_set_encrypt(struct evp_pkey_method_st * pmeth, int (*encrypt_init)(struct evp_pkey_ctx_st * ctx), int (*encryptfn)(struct evp_pkey_ctx_st * ctx, unsigned char * out, unsigned long * outlen, const unsigned char * in, unsigned long inlen))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",561), chkx_binloc("0xcf2f4") ));

void EVP_PKEY_meth_set_decrypt(struct evp_pkey_method_st * pmeth, int (*decrypt_init)(struct evp_pkey_ctx_st * ctx), int (*decrypt)(struct evp_pkey_ctx_st * ctx, unsigned char * out, unsigned long * outlen, const unsigned char * in, unsigned long inlen))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",570), chkx_binloc("0xcf300") ));

void EVP_PKEY_meth_set_derive(struct evp_pkey_method_st * pmeth, int (*derive_init)(struct evp_pkey_ctx_st * ctx), int (*derive)(struct evp_pkey_ctx_st * ctx, unsigned char * key, unsigned long * keylen))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",579), chkx_binloc("0xcf30c") ));

void EVP_PKEY_meth_set_ctrl(struct evp_pkey_method_st * pmeth, int (*ctrl)(struct evp_pkey_ctx_st * ctx, int type, int p1, void * p2), int (*ctrl_str)(struct evp_pkey_ctx_st * ctx, const char * type, const char * value))
   __attribute__ (( chkc_srcloc("crypto/evp/pmeth_lib.c",587), chkx_binloc("0xcf318") ));

