#include "../../shareddata/header.c"

// crypto/asn1/a_enum.c

int ASN1_ENUMERATED_set(struct asn1_string_st * a, long v)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_enum.c",69), chkx_binloc("0xd4de0") ));

long ASN1_ENUMERATED_get(struct asn1_string_st * a)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_enum.c",109), chkx_binloc("0xd4b98") ));

struct asn1_string_st * BN_to_ASN1_ENUMERATED(struct bignum_st * bn, struct asn1_string_st * ai)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_enum.c",138), chkx_binloc("0xd4cb4") ));

struct bignum_st * ASN1_ENUMERATED_to_BN(struct asn1_string_st * ai, struct bignum_st * bn)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_enum.c",174), chkx_binloc("0xd4c30") ));

