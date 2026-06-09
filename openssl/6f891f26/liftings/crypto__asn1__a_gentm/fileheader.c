#include "../../shareddata/header.c"

// crypto/asn1/a_gentm.c

// auxiliary type definitions for userdata

typedef struct tm TM;

// static and global variable definitions

const int min[9];

const int max[9];

// function signatures

int ASN1_GENERALIZEDTIME_check(struct asn1_string_st * d)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_gentm.c",118),
		    chkx_binloc("0xd28d8"),
		    chk_access(read_only, 1) ));

int ASN1_GENERALIZEDTIME_set_string(struct asn1_string_st * s, const char * str)
  __attribute__ (( chkc_srcloc("crypto/asn1/a_gentm.c",189), chkx_binloc("0xd2c70"),
		   chk_access(read_only, 1) ));

struct asn1_string_st * ASN1_GENERALIZEDTIME_set(struct asn1_string_st * s, long t)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_gentm.c",211), chkx_binloc("0xd2c64") ));

struct asn1_string_st * ASN1_GENERALIZEDTIME_adj(struct asn1_string_st * s, long t, int offset_day, long offset_sec)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_gentm.c",217), chkx_binloc("0xd2b0c") ));

