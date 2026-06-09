
#include "../../shareddata/header.c"

// crypto/evp/bio_enc.c

#define ENC_BLOCK_SIZE	(1024*4)
#define BUF_OFFSET	(EVP_MAX_BLOCK_LENGTH*2)

typedef struct enc_struct
	{
	int buf_len;
	int buf_off;
	int cont;		/* <= 0 when finished */
	int finished;
	int ok;			/* bad decrypt */
	EVP_CIPHER_CTX cipher;
	/* buf is larger than ENC_BLOCK_SIZE because EVP_DecryptUpdate
	 * can return up to a block more data than is presented to it
	 */
	char buf[ENC_BLOCK_SIZE+BUF_OFFSET+2];
	} BIO_ENC_CTX;


// static and global variable definitions

struct bio_method_st methods_enc
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",90) ));

// function signatures

struct bio_method_st * BIO_f_cipher(void)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",103), chkx_binloc("0xcbea8") ));

int enc_new(struct bio_st * bi)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",108), chkx_binloc("0xcbfc4") ));

int enc_free(struct bio_st * a)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",128), chkx_binloc("0xcbf78") ));

int enc_read(struct bio_st * b, char * out, int outl)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",143), chkx_binloc("0xcc040") ));

int enc_write(struct bio_st * b, const char * in, int inl)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",231), chkx_binloc("0xcc200") ));

long enc_ctrl(struct bio_st * b, int cmd, long num, void * ptr)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",286), chkx_binloc("0xcc360") ));

long enc_callback_ctrl(struct bio_st * b, int cmd, void (*fp)(struct bio_st * $par$1, int $par$2, const char * $par$3, int $par$4, long $par$5, long $par$6))
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",376), chkx_binloc("0xcbf68") ));

void BIO_set_cipher(struct bio_st * b, const struct evp_cipher_st * c, const unsigned char * k, const unsigned char * i, int e)
   __attribute__ (( chkc_srcloc("crypto/evp/bio_enc.c",410), chkx_binloc("0xcbec4") ));

