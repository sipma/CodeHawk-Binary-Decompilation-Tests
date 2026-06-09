#include "../../shareddata/header.c"

// crypto/x509/x509_vpm.c

// static and global variable definitions

const struct X509_VERIFY_PARAM_st default_table[5];

struct stack_st_X509_VERIFY_PARAM * param_table
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",372) ));

/*
DECLARE_OBJ_BSEARCH_CMP_FN(X509_VERIFY_PARAM, X509_VERIFY_PARAM,
			   table);
IMPLEMENT_OBJ_BSEARCH_CMP_FN(X509_VERIFY_PARAM, X509_VERIFY_PARAM,
			     table);
*/

// function signatures

void x509_verify_param_zero(struct X509_VERIFY_PARAM_st * param)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",70) ));

struct X509_VERIFY_PARAM_st * X509_VERIFY_PARAM_new(void)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",88), chkx_binloc("0xfd98c") ));

void X509_VERIFY_PARAM_free(struct X509_VERIFY_PARAM_st * param)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",97), chkx_binloc("0xfd84c") ));

int X509_VERIFY_PARAM_inherit(struct X509_VERIFY_PARAM_st * dest, const struct X509_VERIFY_PARAM_st * src)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",147), chkx_binloc("0xfd6ac") ));

int X509_VERIFY_PARAM_set1(struct X509_VERIFY_PARAM_st * to, const struct X509_VERIFY_PARAM_st * from)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",199), chkx_binloc("0xfd814") ));

int X509_VERIFY_PARAM_set1_name(struct X509_VERIFY_PARAM_st * param, const char * name)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",210), chkx_binloc("0xfd950") ));

int X509_VERIFY_PARAM_set_flags(struct X509_VERIFY_PARAM_st * param, unsigned long flags)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",220), chkx_binloc("0xfd43c") ));

int X509_VERIFY_PARAM_clear_flags(struct X509_VERIFY_PARAM_st * param, unsigned long flags)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",228), chkx_binloc("0xfd45c") ));

unsigned long X509_VERIFY_PARAM_get_flags(struct X509_VERIFY_PARAM_st * param)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",234), chkx_binloc("0xfd474") ));

int X509_VERIFY_PARAM_set_purpose(struct X509_VERIFY_PARAM_st * param, int purpose)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",239), chkx_binloc("0xfd844") ));

int X509_VERIFY_PARAM_set_trust(struct X509_VERIFY_PARAM_st * param, int trust)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",244), chkx_binloc("0xfd83c") ));

void X509_VERIFY_PARAM_set_depth(struct X509_VERIFY_PARAM_st * param, int depth)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",249), chkx_binloc("0xfd47c") ));

void X509_VERIFY_PARAM_set_time(struct X509_VERIFY_PARAM_st * param, long t)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",254), chkx_binloc("0xfd484") ));

int X509_VERIFY_PARAM_add0_policy(struct X509_VERIFY_PARAM_st * param, struct asn1_object_st * policy)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",260), chkx_binloc("0xfd598") ));

int X509_VERIFY_PARAM_set1_policies(struct X509_VERIFY_PARAM_st * param, struct stack_st_ASN1_OBJECT * policies)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",273), chkx_binloc("0xfd5e0") ));

int X509_VERIFY_PARAM_get_depth(const struct X509_VERIFY_PARAM_st * param)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",309), chkx_binloc("0xfd498") ));

int table_cmp(const struct X509_VERIFY_PARAM_st * a, const struct X509_VERIFY_PARAM_st * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",374) ));

int table_cmp_BSEARCH_CMP_FN(const struct X509_VERIFY_PARAM_st ** a_, const struct X509_VERIFY_PARAM_st ** b_)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",382), chkx_binloc("0xfd578") ));

struct X509_VERIFY_PARAM_st * OBJ_bsearch_table(struct X509_VERIFY_PARAM_st * key, const struct X509_VERIFY_PARAM_st * base, int num)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",382) ));

int param_cmp(const const struct X509_VERIFY_PARAM_st * * a, const const struct X509_VERIFY_PARAM_st * * b)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",385), chkx_binloc("0xfd584") ));

int X509_VERIFY_PARAM_add0_table(struct X509_VERIFY_PARAM_st * param)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",391), chkx_binloc("0xfd8b8") ));

const struct X509_VERIFY_PARAM_st * X509_VERIFY_PARAM_lookup(const char * name)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",416), chkx_binloc("0xfd4e8") ));

void X509_VERIFY_PARAM_table_cleanup(void)
   __attribute__ (( chkc_srcloc("crypto/x509/x509_vpm.c",432), chkx_binloc("0xfd4a0") ));

