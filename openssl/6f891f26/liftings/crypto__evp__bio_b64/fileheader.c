
#include "../../shareddata/header.c"

// crypto/evp/bio_b64.c

#define B64_BLOCK_SIZE	1024
#define B64_BLOCK_SIZE2	768
#define B64_NONE	0
#define B64_ENCODE	1
#define B64_DECODE	2


typedef struct b64_struct
	{
	/*BIO *bio; moved to the BIO structure */
	int buf_len;
	int buf_off;
	int tmp_len;		/* used to find the start when decoding */
	int tmp_nl;		/* If true, scan until '\n' */
	int encode;
	int start;		/* have we started decoding yet? */
	int cont;		/* <= 0 when finished */
	EVP_ENCODE_CTX base64;
	char buf[EVP_ENCODE_LENGTH(B64_BLOCK_SIZE)+10];
	char tmp[B64_BLOCK_SIZE];
	} BIO_B64_CTX;


// static and global variable definitions

struct bio_method_st methods_b64
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",94) ));

// function signatures

struct bio_method_st * BIO_f_base64(void)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",107), chkx_binloc("0xcae58") ));

int b64_new(struct bio_st * bi)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",112), chkx_binloc("0xcaeb4") ));

int b64_free(struct bio_st * a)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",134), chkx_binloc("0xcae84") ));

int b64_read(struct bio_st * b, char * out, int outl)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",144), chkx_binloc("0xcaf30") ));

int b64_write(struct bio_st * b, const char * in, int inl)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",373), chkx_binloc("0xcb5dc") ));

long b64_ctrl(struct bio_st * b, int cmd, long num, void * ptr)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",491), chkx_binloc("0xcbbd0") ));

long b64_callback_ctrl(struct bio_st * b, int cmd, void (*fp)(struct bio_st * $par$1, int $par$2, const char * $par$3, int $par$4, long $par$5, long $par$6))
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",581), chkx_binloc("0xcae74") ));

int b64_puts(struct bio_st * b, const char * str)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_b64.c",595), chkx_binloc("0xcbe78") ));

