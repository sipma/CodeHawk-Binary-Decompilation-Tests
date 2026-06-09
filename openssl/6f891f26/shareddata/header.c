#define NULL 0

//------------------------------------------------------------------------------
// Standard type definitions
//------------------------------------------------------------------------------
typedef _Bool bool;
typedef unsigned char uint8_t;
typedef char int8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef long long unsigned int uint64_t;
typedef long long int int64_t;
typedef unsigned long size_t;
typedef int ssize_t;
typedef long double float128;
typedef unsigned int wchar_t;
typedef unsigned int wint_t;
typedef unsigned int wchar_t_;
typedef unsigned short wchar16;
typedef void* uintptr_t;



typedef int32_t __blkcnt_t;

typedef uint32_t __ino_t;

typedef int32_t __kernel_daddr_t;

struct __kernel_fsid_t
{
    int32_t val[0x2];
};

typedef long time_t;

typedef int32_t __kernel_long_t;

typedef __kernel_long_t __kernel_clock_t;

typedef __kernel_long_t __kernel_time_t;

typedef uint32_t __kernel_ulong_t;

typedef __kernel_ulong_t __kernel_ino_t;

typedef uint32_t __nlink_t;

typedef int32_t __off64_t;

typedef int32_t __off_t;

typedef void _IO_lock_t;

struct tm
{
  int    tm_sec; //   seconds [0,61]
  int    tm_min; //   minutes [0,59]
  int    tm_hour;  //  hour [0,23]
  int    tm_mday; //  day of month [1,31]
  int    tm_mon; //   month of year [0,11]
  int    tm_year;  //  years since 1900
  int    tm_wday;  //  day of week [0,6] (Sunday = 0)
  int    tm_yday;  //  day of year [0,365]
  int    tm_isdst;  // daylight savings flag
};

typedef struct tm ch_tm;

struct _IO_FILE
{
    int32_t _flags;
    char* _IO_read_ptr;
    char* _IO_read_end;
    char* _IO_read_base;
    char* _IO_write_base;
    char* _IO_write_ptr;
    char* _IO_write_end;
    char* _IO_buf_base;
    char* _IO_buf_end;
    char* _IO_save_base;
    char* _IO_backup_base;
    char* _IO_save_end;
    void* _markers;
    struct _IO_FILE* _chain;
    int32_t _fileno;
    int32_t _flags2;
    __off_t _old_offset;
    uint16_t _cur_column;
    char _vtable_offset;
    char _shortbuf[0x1];
    _IO_lock_t* _lock;
    __off64_t _offset;
    void* _codecvt;
    void* _wide_data;
    struct _IO_FILE* _freeres_list;
    void* _freeres_buf;
    int32_t __pad5;
    int32_t _mode;
    char _unused2;
};

typedef struct _IO_FILE FILE;



#define HMAC_TEST_PRIVATE_KEY_FORMAT                 1
#define OPENSSL_NO_CAMELLIA                          1
#define OPENSSL_NO_EC                                1
// #define OPENSSL_NO_ECDSA                             1
#define OPENSSL_NO_IDEA                              1
#define OPENSSL_NO_RC5                               1
#define OPENSSL_NO_SEED                              1

#define OPENSSL_NO_KRB5  1   // ** check **

/* affects the size and offsets of the SSL_CTX struct */
#define OPENSSL_NO_ENGINE      1

/* affects the size and offsets of the SSL_CTX struct */
#define OPENSSL_NO_SRP         1

#define SXNET_TEST             1

#define HEADER_BIO_H           1

#define DES_LONG unsigned long


#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

typedef void * va_list;


// library functions

int memcmp(void *a, void *b, unsigned long size);
void *memset(void *dst, int c, unsigned long size);
int strcmp(char *a, char *b);
size_t strlen(const char *a);
char *strchr(const char *s, int c);


#include "header_o_time.h"
#include "header_ossl_typ.h"
#include "header_safestack.h"
#include "header_sha.h"
#include "header_buffer.h"
#include "header_crypto.h"
#include "header_bio.h"
#include "header_bn.h"
#include "header_comp.h"
#include "header_lhash.h"
#include "header_conf.h"
#include "header_err.h"
#include "header_asn1.h"
#include "header_asn1_locl.h"
#include "header_ui.h"
#include "header_ui_locl.h"
#include "header_x509_vfy.h"
#include "header_asn1t.h"
#include "header_pkcs7.h"
#include "header_objects.h"
#include "header_ec.h"
#include "header_dh.h"
#include "header_dsa.h"
#include "header_rsa.h"
#include "header_evp.h"
#include "header_evp_locl.h"
#include "header_hmac.h"
#include "header_x509.h"
#include "header_rand.h"
#include "header_x509v3.h"
#include "header_ocsp.h"
#include "header_pem.h"

int ENGINE_free(ENGINE *e);

int ENGINE_init(ENGINE *e);

int ENGINE_finish(ENGINE *e);

const RAND_METHOD *ENGINE_get_RAND(const ENGINE *e);
ENGINE *ENGINE_get_default_RAND(void);
