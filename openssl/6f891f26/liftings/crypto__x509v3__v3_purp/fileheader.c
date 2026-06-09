#include "../../shareddata/header.c"

// crypto/x509v3/v3_purp.c

// static and global variable definitions

struct x509_purpose_st xstandard[9];

struct stack_st_X509_PURPOSE * xptable
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",98) ));

const int supported_nids[11];

/*
DECLARE_OBJ_BSEARCH_CMP_FN(int, int, nid);
IMPLEMENT_OBJ_BSEARCH_CMP_FN(int, int, nid);
*/

// function signatures

int xp_cmp(const const struct x509_purpose_st * * a, const const struct x509_purpose_st * * b)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",100), chkx_binloc("0x106188") ));

int X509_check_purpose(struct x509_st * x, int id, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",109), chkx_binloc("0x106d10") ));

int X509_PURPOSE_set(int * p, int purpose)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",125), chkx_binloc("0x106ca8") ));

int X509_PURPOSE_get_count(void)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",135), chkx_binloc("0x106228") ));

struct x509_purpose_st * X509_PURPOSE_get0(int idx)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",141), chkx_binloc("0x1061d8") ));

int X509_PURPOSE_get_by_sname(char * sname)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",148), chkx_binloc("0x106dbc") ));

int X509_PURPOSE_get_by_id(int purpose)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",159), chkx_binloc("0x106a6c") ));

int X509_PURPOSE_add(int id, int trust, int flags, int (*ck)(const struct x509_purpose_st * $par$1, const struct x509_st * $par$2, int $par$3), char * name, char * sname, void * arg)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",172), chkx_binloc("0x106ad4") ));

void xptable_free(struct x509_purpose_st * p)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",229), chkx_binloc("0x106a2c") ));

void X509_PURPOSE_cleanup(void)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",242), chkx_binloc("0x106e0c") ));

int X509_PURPOSE_get_id(struct x509_purpose_st * xp)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",250), chkx_binloc("0x1061a0") ));

char * X509_PURPOSE_get0_name(struct x509_purpose_st * xp)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",255), chkx_binloc("0x1061a8") ));

char * X509_PURPOSE_get0_sname(struct x509_purpose_st * xp)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",260), chkx_binloc("0x1061b0") ));

int X509_PURPOSE_get_trust(struct x509_purpose_st * xp)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",265), chkx_binloc("0x1061b8") ));

int nid_cmp(const int * a, const int * b)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",270) ));

int nid_cmp_BSEARCH_CMP_FN(const void * a_, const void * b_)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",276), chkx_binloc("0x1061c0") ));

int * OBJ_bsearch_nid(int * key, const int * base, int num)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",276) ));

int X509_supported_extension(struct X509_extension_st * ex)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",278), chkx_binloc("0x106334") ));

void setup_dp(struct x509_st * x, struct DIST_POINT_st * dp)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",317) ));

void setup_crldp(struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",349) ));

void x509v3_cache_extensions(struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",357), chkx_binloc("0x10639c") ));

int check_ca(const struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",508) ));

int X509_check_ca(struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",529), chkx_binloc("0x107188") ));

int check_ssl_ca(const struct x509_st * x)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",541) ));

int check_purpose_ssl_client(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",552), chkx_binloc("0x107444") ));

int check_purpose_ssl_server(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",563), chkx_binloc("0x107508") ));

int check_purpose_ns_ssl_server(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",576), chkx_binloc("0x1076a8") ));

int purpose_smime(const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",587) ));

int check_purpose_smime_sign(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",607), chkx_binloc("0x1070b0") ));

int check_purpose_smime_encrypt(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",616), chkx_binloc("0x1075d0") ));

int check_purpose_crl_sign(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",625), chkx_binloc("0x1072c8") ));

int ocsp_helper(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",640), chkx_binloc("0x107254") ));

int check_purpose_timestamp_sign(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",649), chkx_binloc("0x107354") ));

int no_check(const struct x509_purpose_st * xp, const struct x509_st * x, int ca)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",684), chkx_binloc("0x1061d0") ));

int X509_check_issued(struct x509_st * issuer, struct x509_st * subject)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",701), chkx_binloc("0x10697c") ));

int X509_check_akid(struct x509_st * issuer, struct AUTHORITY_KEYID_st * akid)
   __attribute__ (( chkc_srcloc("crypto/x509v3/v3_purp.c",726), chkx_binloc("0x106260") ));

