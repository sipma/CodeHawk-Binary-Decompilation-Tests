#include "../../shareddata/header.c"
// crypto/asn1/a_d2i_fp.c

void * ASN1_d2i_fp(void * (*xnew)(void), void * (*d2i)(void * * $par$1, const unsigned char * * $par$2, long $par$3), struct _IO_FILE * in, void * * x)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_d2i_fp.c",70), chkx_binloc("0xd483c") ));

void * ASN1_d2i_bio(void * (*xnew)(void), void * (*d2i)(void * * $par$1, const unsigned char * * $par$2, long $par$3), struct bio_st * in, void * * x)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_d2i_fp.c",87), chkx_binloc("0xd47c8") ));

void * ASN1_item_d2i_bio(const struct ASN1_ITEM_st * it, struct bio_st * in, void * x)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_d2i_fp.c",106), chkx_binloc("0xd46bc") ));

void * ASN1_item_d2i_fp(const struct ASN1_ITEM_st * it, struct _IO_FILE * in, void * x)
   __attribute__ (( chkc_srcloc("crypto/asn1/a_d2i_fp.c",124), chkx_binloc("0xd4734") ));

int asn1_d2i_read_bio(struct bio_st * in, struct buf_mem_st * * pb)
  __attribute__ (( chkc_srcloc("crypto/asn1/a_d2i_fp.c",142), chkx_binloc("0xd4370"),
		   chk_access(read_write, 2) ));

