#include "../../shareddata/header.c"

// crypto/asn1/a_bitstr.c

int ASN1_BIT_STRING_set(struct asn1_string_st * x, unsigned char * d, int len)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_bitstr.c",63), chkx_binloc("0xd22fc") ));

int i2c_ASN1_BIT_STRING(struct asn1_string_st * a, unsigned char * * pp)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_bitstr.c",66), chkx_binloc("0xd2098") ));

struct asn1_string_st * c2i_ASN1_BIT_STRING(struct asn1_string_st * * a, const unsigned char * * pp, long len)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_bitstr.c",116), chkx_binloc("0xd2198") ));

int ASN1_BIT_STRING_set_bit(struct asn1_string_st * a, int n, int value)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_bitstr.c",176), chkx_binloc("0xd1f00") ));

int ASN1_BIT_STRING_get_bit(struct asn1_string_st * a, int n)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_bitstr.c",215), chkx_binloc("0xd1e2c") ));

int ASN1_BIT_STRING_check(struct asn1_string_st * a, unsigned char * flags, int flags_len)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_bitstr.c",232), chkx_binloc("0xd1e84") ));

