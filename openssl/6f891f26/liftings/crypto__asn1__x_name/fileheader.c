#include "../../shareddata/header.c"

// crypto/asn1/x_name.c

// static and global variable definitions

const struct ASN1_TEMPLATE_st X509_NAME_ENTRY_seq_tt[2];

const struct ASN1_ITEM_st X509_NAME_ENTRY_local_it
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",94) ));

const struct ASN1_TEMPLATE_st X509_NAME_ENTRIES_item_tt
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",103) ));

const struct ASN1_ITEM_st X509_NAME_ENTRIES_local_it
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",105) ));

const struct ASN1_TEMPLATE_st X509_NAME_INTERNAL_item_tt
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",107) ));

const struct ASN1_ITEM_st X509_NAME_INTERNAL_local_it
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",109) ));

const struct ASN1_EXTERN_FUNCS_st x509_name_ff
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",117) ));

const struct ASN1_ITEM_st X509_NAME_local_it
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",127) ));

// function signatures

struct X509_name_entry_st * d2i_X509_NAME_ENTRY(struct X509_name_entry_st * * a, const unsigned char * * in, long len)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",96), chkx_binloc("0xd9478") ));

int i2d_X509_NAME_ENTRY(struct X509_name_entry_st * a, unsigned char * * out)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",96), chkx_binloc("0xd9438") ));

struct X509_name_entry_st * X509_NAME_ENTRY_new(void)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",96), chkx_binloc("0xd8ea8") ));

void X509_NAME_ENTRY_free(struct X509_name_entry_st * a)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",96), chkx_binloc("0xd8e70") ));

struct X509_name_entry_st * X509_NAME_ENTRY_dup(struct X509_name_entry_st * x)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",97), chkx_binloc("0xd8ddc") ));

struct X509_name_st * d2i_X509_NAME(struct X509_name_st * * a, const unsigned char * * in, long len)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",129), chkx_binloc("0xd9454") ));

int i2d_X509_NAME(struct X509_name_st * a, unsigned char * * out)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",129), chkx_binloc("0xd941c") ));

struct X509_name_st * X509_NAME_new(void)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",129), chkx_binloc("0xd8e8c") ));

void X509_NAME_free(struct X509_name_st * a)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",129), chkx_binloc("0xd8dfc") ));

struct X509_name_st * X509_NAME_dup(struct X509_name_st * x)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",130), chkx_binloc("0xd8dbc") ));

int x509_name_ex_new(struct ASN1_VALUE_st * * val, const struct ASN1_ITEM_st * it)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",132), chkx_binloc("0xd8cdc") ));

void x509_name_ex_free(struct ASN1_VALUE_st * * pval, const struct ASN1_ITEM_st * it)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",157), chkx_binloc("0xd8c78") ));

int x509_name_ex_d2i(struct ASN1_VALUE_st * * val, const unsigned char * * in, long len, const struct ASN1_ITEM_st * it, int tag, int aclass, char opt, struct ASN1_TLC_st * ctx)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",172), chkx_binloc("0xd949c") ));

int x509_name_ex_i2d(struct ASN1_VALUE_st * * val, unsigned char * * out, const struct ASN1_ITEM_st * it, int tag, int aclass)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",224), chkx_binloc("0xd9248") ));

void local_sk_X509_NAME_ENTRY_free(struct stack_st_X509_NAME_ENTRY * ne)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",244), chkx_binloc("0xd8c74") ));

void local_sk_X509_NAME_ENTRY_pop_free(struct stack_st_X509_NAME_ENTRY * ne)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",249), chkx_binloc("0xd8c58") ));

int x509_name_encode(struct X509_name_st * a)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",254) ));

int x509_name_ex_print(struct bio_st * out, struct ASN1_VALUE_st * * pval, int indent, const char * fname, const struct asn1_pctx_st * pctx)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",294), chkx_binloc("0xd8ba0") ));

int x509_name_canon(struct X509_name_st * a)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",318), chkx_binloc("0xd8ec4") ));

int asn1_string_canon(struct asn1_string_st * out, struct asn1_string_st * in)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",394) ));

int i2d_name_canon(struct stack_st_STACK_OF_X509_NAME_ENTRY * _intname, unsigned char * * in)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",480), chkx_binloc("0xd8bcc") ));

int X509_NAME_set(struct X509_name_st * * xn, struct X509_name_st * name)
   __attribute__ (( chkc_srcloc("crypto/asn1/x_name.c",500), chkx_binloc("0xd8e18") ));

