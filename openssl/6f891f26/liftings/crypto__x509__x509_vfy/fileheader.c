#include "../../shareddata/header.c"

// crypto/x509/x509_vfy.c

// static and global variable definitions

const char X509_version[40];

// function signatures

int null_callback(int ok, struct x509_store_ctx_st * e)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",141), chkx_binloc("0xf49f8") ));

int X509_verify_cert(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",153), chkx_binloc("0xf69f4") ));

struct x509_st * find_issuer(struct x509_store_ctx_st * ctx, struct stack_st_X509 * sk, struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",398) ));

int check_issued(struct x509_store_ctx_st * ctx, struct x509_st * x, struct x509_st * issuer)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",413), chkx_binloc("0xf52a8") ));

int get_issuer_sk(struct x509_st * * issuer, struct x509_store_ctx_st * ctx, struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",432), chkx_binloc("0xf4bb8") ));

int check_chain_extensions(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",449) ));

int check_name_constraints(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",607) ));

int check_trust(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",643) ));

int check_revocation(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",669), chkx_binloc("0xf63c8") ));

int check_cert(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",692) ));

int check_crl_time(struct x509_store_ctx_st * ctx, struct X509_crl_st * crl, int notify)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",771), chkx_binloc("0xf5a10") ));

int get_crl_sk(struct x509_store_ctx_st * ctx, struct X509_crl_st * * pcrl, struct X509_crl_st * * pdcrl, struct x509_st * * pissuer, int * pscore, unsigned int * preasons, struct stack_st_X509_CRL * crls)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",830), chkx_binloc("0xf5b34") ));

int crl_extension_match(struct X509_crl_st * a, struct X509_crl_st * b, int nid)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",882), chkx_binloc("0xf51c0") ));

int check_delta_base(struct X509_crl_st * delta, struct X509_crl_st * base)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",924) ));

void get_delta_sk(struct x509_store_ctx_st * ctx, struct X509_crl_st * * dcrl, int * pscore, struct X509_crl_st * base, struct stack_st_X509_CRL * crls)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",954) ));

int get_crl_score(struct x509_store_ctx_st * ctx, struct x509_st * * pissuer, unsigned int * preasons, struct X509_crl_st * crl, struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",985) ));

void crl_akid_check(struct x509_store_ctx_st * ctx, struct X509_crl_st * crl, struct x509_st * * pissuer, int * pcrl_score)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1054) ));

int check_crl_path(struct x509_store_ctx_st * ctx, struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1119) ));

int check_crl_chain(struct x509_store_ctx_st * ctx, struct stack_st_X509 * cert_path, struct stack_st_X509 * crl_path)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1158) ));

int idp_check_dp(struct DIST_POINT_NAME_st * a, struct DIST_POINT_NAME_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1178) ));

int crldp_check_crlissuer(struct DIST_POINT_st * dp, struct X509_crl_st * crl, int crl_score)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1244) ));

int crl_crldp_check(struct x509_st * x, struct X509_crl_st * crl, int crl_score, unsigned int * preasons)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1264) ));

int get_crl_delta(struct x509_store_ctx_st * ctx, struct X509_crl_st * * pcrl, struct X509_crl_st * * pdcrl, struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1303) ));

int check_crl(struct x509_store_ctx_st * ctx, struct X509_crl_st * crl)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1349), chkx_binloc("0xf741c") ));

int cert_crl(struct x509_store_ctx_st * ctx, struct X509_crl_st * crl, struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1456), chkx_binloc("0xf5118") ));

int check_policy(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1489), chkx_binloc("0xf4fd4") ));

int check_cert_time(struct x509_store_ctx_st * ctx, struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1539) ));

int internal_verify(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1586), chkx_binloc("0xf6754") ));

int X509_cmp_current_time(const struct asn1_string_st * ctm)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1676), chkx_binloc("0xf69ec") ));

int X509_cmp_time(const struct asn1_string_st * ctm, long * cmp_time)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1681), chkx_binloc("0xf57c4") ));

struct asn1_string_st * X509_gmtime_adj(struct asn1_string_st * s, long adj)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1760), chkx_binloc("0xf57bc") ));

struct asn1_string_st * X509_time_adj(struct asn1_string_st * s, long offset_sec, long * in_tm)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1765), chkx_binloc("0xf57ac") ));

struct asn1_string_st * X509_time_adj_ex(struct asn1_string_st * s, int offset_day, long offset_sec, long * in_tm)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1770), chkx_binloc("0xf5708") ));

int X509_get_pubkey_parameters(struct evp_pkey_st * pkey, struct stack_st_X509 * chain)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1789), chkx_binloc("0xf55d8") ));

int X509_STORE_CTX_get_ex_new_index(long argl, void * argp, int (*new_func)(void * parent, void * ptr, struct crypto_ex_data_st * ad, int idx, long argl, void * argp), int (*dup_func)(struct crypto_ex_data_st * to, struct crypto_ex_data_st * from, void * from_d, int idx, long argl, void * argp), void (*free_func)(void * parent, void * ptr, struct crypto_ex_data_st * ad, int idx, long argl, void * argp))
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1831), chkx_binloc("0xf55a0") ));

int X509_STORE_CTX_set_ex_data(struct x509_store_ctx_st * ctx, int idx, void * data)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1840), chkx_binloc("0xf5598") ));

void * X509_STORE_CTX_get_ex_data(struct x509_store_ctx_st * ctx, int idx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1845), chkx_binloc("0xf5590") ));

int X509_STORE_CTX_get_error(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1850), chkx_binloc("0xf49fc") ));

void X509_STORE_CTX_set_error(struct x509_store_ctx_st * ctx, int err)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1855), chkx_binloc("0xf4a04") ));

int X509_STORE_CTX_get_error_depth(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1860), chkx_binloc("0xf4a0c") ));

struct x509_st * X509_STORE_CTX_get_current_cert(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1865), chkx_binloc("0xf4a14") ));

struct stack_st_X509 * X509_STORE_CTX_get_chain(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1870), chkx_binloc("0xf4a1c") ));

struct stack_st_X509 * X509_STORE_CTX_get1_chain(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1875), chkx_binloc("0xf54fc") ));

struct x509_st * X509_STORE_CTX_get0_current_issuer(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1889), chkx_binloc("0xf4a24") ));

struct X509_crl_st * X509_STORE_CTX_get0_current_crl(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1894), chkx_binloc("0xf4a2c") ));

struct x509_store_ctx_st * X509_STORE_CTX_get0_parent_ctx(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1899), chkx_binloc("0xf4a34") ));

void X509_STORE_CTX_set_cert(struct x509_store_ctx_st * ctx, struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1904), chkx_binloc("0xf4a3c") ));

void X509_STORE_CTX_set_chain(struct x509_store_ctx_st * ctx, struct stack_st_X509 * sk)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1909), chkx_binloc("0xf4a44") ));

void X509_STORE_CTX_set0_crls(struct x509_store_ctx_st * ctx, struct stack_st_X509_CRL * sk)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1914), chkx_binloc("0xf4a4c") ));

int X509_STORE_CTX_set_purpose(struct x509_store_ctx_st * ctx, int purpose)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1919), chkx_binloc("0xf54ec") ));

int X509_STORE_CTX_set_trust(struct x509_store_ctx_st * ctx, int trust)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1924), chkx_binloc("0xf54dc") ));

int X509_STORE_CTX_purpose_inherit(struct x509_store_ctx_st * ctx, int def_purpose, int purpose, int trust)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1939), chkx_binloc("0xf5374") ));

struct x509_store_ctx_st * X509_STORE_CTX_new(void)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",1987), chkx_binloc("0xf52fc") ));

void X509_STORE_CTX_free(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2000), chkx_binloc("0xf4fbc") ));

int X509_STORE_CTX_init(struct x509_store_ctx_st * ctx, struct x509_store_st * store, struct x509_st * x509, struct stack_st_X509 * chain)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2006), chkx_binloc("0xf4c78") ));

void X509_STORE_CTX_trusted_stack(struct x509_store_ctx_st * ctx, struct stack_st_X509 * sk)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2137), chkx_binloc("0xf4a54") ));

void X509_STORE_CTX_cleanup(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2143), chkx_binloc("0xf4b04") ));

void X509_STORE_CTX_set_depth(struct x509_store_ctx_st * ctx, int depth)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2166), chkx_binloc("0xf4afc") ));

void X509_STORE_CTX_set_flags(struct x509_store_ctx_st * ctx, unsigned long flags)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2171), chkx_binloc("0xf4af4") ));

void X509_STORE_CTX_set_time(struct x509_store_ctx_st * ctx, unsigned long flags, long t)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2176), chkx_binloc("0xf4ae8") ));

void X509_STORE_CTX_set_verify_cb(struct x509_store_ctx_st * ctx, int (*verify_cb)(int $par$1, struct x509_store_ctx_st * $par$2))
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2181), chkx_binloc("0xf4a78") ));

struct X509_POLICY_TREE_st * X509_STORE_CTX_get0_policy_tree(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2187), chkx_binloc("0xf4a80") ));

int X509_STORE_CTX_get_explicit_policy(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2192), chkx_binloc("0xf4a88") ));

int X509_STORE_CTX_set_default(struct x509_store_ctx_st * ctx, const char * name)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2197), chkx_binloc("0xf4ac4") ));

struct X509_VERIFY_PARAM_st * X509_STORE_CTX_get0_param(struct x509_store_ctx_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2206), chkx_binloc("0xf4a90") ));

void X509_STORE_CTX_set0_param(struct x509_store_ctx_st * ctx, struct X509_VERIFY_PARAM_st * param)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vfy.c",2211), chkx_binloc("0xf4a98") ));

