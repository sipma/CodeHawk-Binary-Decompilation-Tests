#include "../../shareddata/header.c"

struct doall_md
	{
	void *arg;
	void (*fn)(const EVP_MD *ciph,
			const char *from, const char *to, void *arg);
	};

typedef struct doall_md doall_md_st;

struct doall_cipher
	{
	void *arg;
	void (*fn)(const EVP_CIPHER *ciph,
			const char *from, const char *to, void *arg);
	};

typedef struct doall_cipher doall_cipher_st;

int obj_cleanup_defer;


// crypto/evp/names.c

int EVP_add_cipher(const struct evp_cipher_st * c)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",65), chkx_binloc("0xc8990") ));

int EVP_add_digest(const struct env_md_st * md)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",81), chkx_binloc("0xc88d8") ));

const struct evp_cipher_st * EVP_get_cipherbyname(const char * name)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",106), chkx_binloc("0xc88d0") ));

const struct env_md_st * EVP_get_digestbyname(const char * name)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",114), chkx_binloc("0xc88c8") ));

void EVP_cleanup(void)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",122), chkx_binloc("0xc886c") ));

void do_all_cipher_fn(const struct obj_name_st * nm, void * arg)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",147), chkx_binloc("0xc86c4") ));

void EVP_CIPHER_do_all(void (*fn)(const struct evp_cipher_st * ciph, const char * from, const char * to, void * x), void * arg)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",156), chkx_binloc("0xc882c") ));

void EVP_CIPHER_do_all_sorted(void (*fn)(const struct evp_cipher_st * ciph, const char * from, const char * to, void * x), void * arg)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",165), chkx_binloc("0xc87ac") ));

void do_all_md_fn(const struct obj_name_st * nm, void * arg)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",181), chkx_binloc("0xc8718") ));

void EVP_MD_do_all(void (*fn)(const struct env_md_st * md, const char * from, const char * to, void * x), void * arg)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",190), chkx_binloc("0xc87ec") ));

void EVP_MD_do_all_sorted(void (*fn)(const struct env_md_st * md, const char * from, const char * to, void * x), void * arg)
   __attribute__ (( chkc_srcloc("crypto/evp/names.c",199), chkx_binloc("0xc876c") ));

