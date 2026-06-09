#include "../../shareddata/header.c"

// type definitions for userdata

typedef char *pchar;
typedef pchar *ppchar;

// crypto/asn1/a_mbstr.c

int ASN1_mbstring_copy(struct asn1_string_st * * out, const unsigned char * in, int len, int inform, unsigned long mask)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",83), chkx_binloc("0xd6c9c") ));

int ASN1_mbstring_ncopy(struct asn1_string_st * * out, const unsigned char * in, int len, int inform, unsigned long mask, long minsize, long maxsize)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",89), chkx_binloc("0xd62ac") ));

int traverse_string(const unsigned char * p, int len, int inform, int (*rfunc)(unsigned long value, void * in), void * arg)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",250) ));

int in_utf8(unsigned long value, int * arg)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",287), chkx_binloc("0xd60ec") ));

int out_utf8(unsigned long value, int * arg)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",297), chkx_binloc("0xd61ac") ));

int type_str(unsigned long value, unsigned long * arg)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",309), chkx_binloc("0xd61e0") ));

int cpy_asc(unsigned long value, int * arg)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",328), chkx_binloc("0xd6100") ));

int cpy_bmp(unsigned long value, void * arg)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",340), chkx_binloc("0xd611c") ));

int cpy_univ(unsigned long value, void * arg)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",353), chkx_binloc("0xd6140") ));

int cpy_utf8(unsigned long value, int * arg)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",368), chkx_binloc("0xd6180") ));

int is_printable(unsigned long value)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_mbstr.c",380) ));

