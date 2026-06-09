#include "../../shareddata/header.c"

// crypto/rand/rand_lib.c


// static and global variable definitions

struct engine_st * funct_ref
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",75) ));

const struct rand_meth_st * default_RAND_meth
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",77) ));

// function signatures

int RAND_set_rand_method(const struct rand_meth_st * meth)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",79), chkx_binloc("0xbf530") ));

const struct rand_meth_st * RAND_get_rand_method(void)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",92), chkx_binloc("0xbf5f8") ));

int RAND_set_rand_engine(struct engine_st * engine)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",117), chkx_binloc("0xbf57c") ));

void RAND_cleanup(void)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",138), chkx_binloc("0xbf7b0") ));

void RAND_seed(const void * buf, int num)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",146), chkx_binloc("0xbf774") ));

void RAND_add(const void * buf, int num, double entropy)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",153), chkx_binloc("0xbf728") ));

int RAND_bytes(unsigned char * buf, int num)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",160), chkx_binloc("0xbf6e4") ));

int RAND_pseudo_bytes(unsigned char * buf, int num)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",168), chkx_binloc("0xbf6a0") ));

int RAND_status(void)
   __attribute__ (( chkc_srcloc("crypto/rand/rand_lib.c",176), chkx_binloc("0xbf66c") ));

