
/* from unknown config.h */
#define IF_ECHO(x)
#define IF_PRINTF(x)
#define IF_TEST(x)
#define IF_KILL(x)
#define IF_CHOWN(x)
#define IF_LS(x)

#define IF_FEATURE_SHOW_THREADS(x)
#define IF_SELINUX(x)

#define ENABLE_FEATURE_SYSLOG       0
#define ENABLE_FEATURE_CROND_D      0
#define ENABLE_FEATURE_TOPMEM       0
#define ENABLE_KILLALL              0
#define ENABLE_PGREP                0
#define ENABLE_PIDOF                0
#define ENABLE_SESTATUS             0
#define ENABLE_PKILL                0
#define ENABLE_SELINUX              0
#define ENABLE_FEATURE_TOP_SMP_PROCESS        0
#define ENABLE_FEATURE_PS_ADDITIONAL_COLUMNS  0
#define ENABLE_FEATURE_SHOW_THREADS           1

#define BB_BIG_ENDIAN    0
#define BB_LITTLE_ENDIAN 1

#define USER_MAX_SIZE  28


/* Confirmed configuration constants */

// CONFIG_UDHCP_DEBUG && CONFIG_UDHCP_DEBUG >= 2
// evaluates to true (from networking/udhcp/common.c:log_option

// controls the presence of dname_enc and dname_dec in networking/udhcp/domain_codec.c
#define ENABLE_FEATURE_UDHCP_RFC3397   1


/* standard constants */

#define SIGHUP     1
#define SIGINT     2
#define SIGQUIT    3
#define SIGABRT    6
#define SIGUSR1   10
#define SIGUSR2   12
#define SIGPIPE   13
#define SIGALRM   14
#define SIGTERM   15
#define SIGXCPU   24
#define SIGXFSZ   25
#define SIGVTALRM 26

#define UINT_MAX  0xFFFFFFFF
#define ULONG_MAX 0xFFFFFFFF

/* standard scalar types for CIL */

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int int64_t;
typedef unsigned long long uint64_t;

typedef long int __off_t;
typedef __off_t off_t;
typedef int64_t __off64_t;

typedef unsigned int size_t;
typedef int ssize_t;
typedef unsigned int __mode_t;
typedef __mode_t mode_t;
typedef long int __time_t;
typedef __time_t time_t;
typedef long int __suseconds_t;
typedef unsigned int __socklen_t;
typedef __socklen_t socklen_t;
typedef uint16_t in_port_t;
typedef uint64_t __dev_t;
typedef long int __fd_mask;


typedef unsigned int __uid_t;
typedef __uid_t uid_t;
typedef unsigned int __gid_t;
typedef __gid_t gid_t;
typedef int __pid_t;
typedef __pid_t pid_t;

/* standard system includes */

// # 127 "/usr/include/dirent.h" 3 4
typedef struct __dirstream DIR;
typedef DIR ch__DIR;               // map CHB type

// # 35 "/usr/include/bits/setjmp.h" 3 4
typedef int __jmp_buf[6];

// # 1 "/usr/include/bits/types/sigset_t.h" 1 3 4
// # 1 "/usr/include/bits/types/__sigset_t.h" 1 3 4
struct __sigset_st
{
  // unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  unsigned long int __val[32];
};
typedef struct __sigset_st __sigset_t;
// # 5 "/usr/include/bits/types/sigset_t.h" 2 3 4
typedef __sigset_t sigset_t;
// typedef sigset_t ch__sigset_t;    // map CHB type


// # 26 "/usr/include/bits/types/struct___jmp_buf_tag.h" 3 4
struct __jmp_buf_tag
  {
    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };
// # 31 "/usr/include/setjmp.h" 2 3 4
typedef struct __jmp_buf_tag jmp_buf[1];

// # 26 "/usr/include/sys/poll.h" 2 3 4
typedef unsigned long int nfds_t;

struct pollfd
  {
    int fd;
    short int events;
    short int revents;
  };
typedef struct pollfd ch__pollfd;   // map CHB type

// # 23 "/usr/include/bits/termios.h" 3 4
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

// # 24 "/usr/include/bits/termios-struct.h" 3 4
struct termios
  {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[32];
    speed_t c_ispeed;
    speed_t c_ospeed;
  };
typedef struct termios ch__termios;


// # 1 "/usr/include/bits/types/FILE.h" 1 3 4
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;

typedef FILE ch__FILE;           // map CHB type

// # 35 "/usr/include/bits/types/struct_FILE.h" 3 4
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;

struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  // char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
  char _unused2[40];
};

// # 1 "/usr/include/bits/types/struct_tm.h" 1 3 4
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
typedef struct tm ch__tm;    // map CHB type

// # 28 "/usr/include/bits/sockaddr.h" 3 4
typedef unsigned short int sa_family_t;

// # 178 "/usr/include/bits/socket.h" 2 3 4
struct sockaddr
  {
    sa_family_t sa_family;
    char sa_data[14];
  };

typedef struct sockaddr ch__sockaddr;   // map CHB type


// # 24 "/usr/include/netinet/in.h" 2 3 4
typedef uint32_t in_addr_t;
typedef in_addr_t ch__in_addr;    // map CHB type
struct in_addr
  {
    in_addr_t s_addr;
  };

// # 245 "/usr/include/netinet/in.h" 3 4
struct sockaddr_in
  {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
    unsigned char sin_zero[sizeof (struct sockaddr)
      - (sizeof (unsigned short int))
      - sizeof (in_port_t)
      - sizeof (struct in_addr)];
  };



// # 24 "/usr/include/bits/socket_type.h" 3 4
enum __socket_type
{
  SOCK_STREAM = 1,
  SOCK_DGRAM = 2,
  SOCK_RAW = 3,
  SOCK_RDM = 4,
  SOCK_SEQPACKET = 5,
  SOCK_DCCP = 6,
  SOCK_PACKET = 10,
  SOCK_CLOEXEC = 02000000,
  SOCK_NONBLOCK = 00004000
};

#define AF_UNSPEC   0
#define AF_UNIX     1
#define AF_INET     2
#define AF_INET6   10


// # 49 "/usr/include/pwd.h" 3 4
struct passwd
{
  char *pw_name;
  char *pw_passwd;

  __uid_t pw_uid;
  __gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};
typedef struct passwd ch__passwd;     // map CHB type

// # 235 "/usr/include/netdb.h" 3 4
struct servent
{
  char *s_name;
  char **s_aliases;
  int s_port;
  char *s_proto;
};

// # 59 "/usr/include/stdlib.h" 3 4
typedef struct
  {
    int quot;
    int rem;
  } div_t;

// # 48 "/usr/include/mntent.h" 3 4
struct mntent
  {
    char *mnt_fsname;
    char *mnt_dir;
    char *mnt_type;
    char *mnt_opts;
    int mnt_freq;
    int mnt_passno;
  };

// # 54 "/usr/include/setjmp.h" 3 4
typedef struct __jmp_buf_tag sigjmp_buf[1];

// # 1 "/usr/include/bits/types/struct_timeval.h" 1 3 4
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
typedef struct timeval ch__timeval;    // map CHB type


// # 90 "/usr/include/netdb.h" 3 4
struct hostent
{
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  int h_length;
  char **h_addr_list;
};
typedef struct hostent ch__hostent;  // map CHB type

// # 25 "/usr/include/netinet/ip.h" 2 3 4
struct iphdr
  {
    unsigned int ihl:4;
    unsigned int version:4;
    uint8_t tos;
    uint16_t tot_len;
    uint16_t id;
    uint16_t frag_off;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t check;
    uint32_t saddr;
    uint32_t daddr;

  };

// # 52 "/usr/include/netinet/udp.h" 2 3 4
struct udphdr
{
  __extension__ union
  {
    struct
    {
      uint16_t uh_sport;
      uint16_t uh_dport;
      uint16_t uh_ulen;
      uint16_t uh_sum;
    };
    struct
    {
      uint16_t source;
      uint16_t dest;
      uint16_t len;
      uint16_t check;
    };
  };
};

// # 29 "/home/henny/forks/CodeHawk-Binary-Decompilation-Tests/busybox/8b996feb/liftings/networking__udhcp__common/../../shareddata/header_common.h"
struct dhcp_packet {
 uint8_t op;
 uint8_t htype;
 uint8_t hlen;
 uint8_t hops;
 uint32_t xid;
 uint16_t secs;
 uint16_t flags;

 uint32_t ciaddr;
 uint32_t yiaddr;

 uint32_t siaddr_nip;
 uint32_t gateway_nip;
 uint8_t chaddr[16];
 uint8_t sname[64];
 uint8_t file[128];
 uint32_t cookie;
 uint8_t options[308 + 80];
} __attribute__ ((__packed__));

// # 59 "/usr/include/sys/select.h" 3 4
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;


/* Other types */

/* __builtin_va_list not yet handled by CodeHawk */
typedef void *va_list;
typedef va_list __gnuc_va_list;

/* Library functions without a summary */

// # 54 "/usr/include/setjmp.h" 3 4
extern void longjmp (struct __jmp_buf_tag __env[1], int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));

// # 654 "/usr/include/stdlib.h" 3 4
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// # 94 "/usr/include/pwd.h" 3 4
extern struct passwd *getpwuid (__uid_t __uid);

// # 564 "/usr/include/unistd.h" 3 4
extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


// # 139 "/usr/include/pwd.h" 3 4
extern int getpwent_r (struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result)
    __attribute__ ((__nonnull__ (1, 2, 4)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));

// # 778 "/usr/include/unistd.h" 3 4
extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));

// # 682 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));

// # 68 "/usr/include/signal.h" 2 3 4
typedef void (*__sighandler_t) (int);

// # 88 "/usr/include/signal.h" 3 4
extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__ , __leaf__));

// # 132 "/usr/include/sys/wait.h" 3 4
struct rusage;
extern __pid_t wait3 (int *__stat_loc, int __options,
        struct rusage * __usage) __attribute__ ((__nothrow__));

// # 1002 "/usr/include/unistd.h" 3 4
extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

// # 235 "/usr/include/netdb.h" 3 4
extern struct servent *getservbyport (int __port, const char *__proto);

// # 631 "/usr/include/unistd.h" 2 3 4
extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));

// # 799 "/usr/include/unistd.h" 3 4
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));

// # 407 "/usr/include/string.h" 3 4
extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

// # 328 "/usr/include/stdio.h" 3 4
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

// # 848 "/usr/include/stdlib.h" 3 4
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

// # 112 "/usr/include/signal.h" 3 4
extern int raise (int __sig) __attribute__ ((__nothrow__ , __leaf__));

// # 463 "/usr/include/string.h" 2 3 4
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));

// # 489 "/usr/include/string.h" 3 4
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


// # 328 "/usr/include/stdio.h" 3 4
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

// # 31 "/usr/include/setjmp.h" 2 3 4
extern int _setjmp (struct __jmp_buf_tag __env[1]) __attribute__ ((__nothrow__));

// # 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

// # 154 "/usr/include/time.h" 3 4
extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

// # 154 "/usr/include/time.h" 3 4
extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));

// # 48 "/usr/include/mntent.h" 3 4
extern FILE *setmntent (const char *__file, const char *__mode) __attribute__ ((__nothrow__ , __leaf__));
extern struct mntent *getmntent (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern struct mntent *getmntent_r (FILE *__restrict __stream,
       struct mntent *__restrict __result,
       char *__restrict __buffer,
       int __bufsize) __attribute__ ((__nothrow__ , __leaf__));

extern int endmntent (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

// # 389 "/usr/include/sys/stat.h" 3 4
extern int mknod (const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern int mkfifo (const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// # 799 "/usr/include/unistd.h" 3 4
extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;

// # 114 "/usr/include/sys/time.h" 3 4
extern int utimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// # 1150 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);

// # 1002 "/usr/include/unistd.h" 3 4
extern long int gethostid (void);

// # 186 "/usr/include/grp.h" 3 4
extern int getgrouplist (const char *__user, __gid_t __group,
    __gid_t *__groups, int *__ngroups);

// # 738 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

// # 80 "/usr/include/setjmp.h" 3 4
extern void siglongjmp (sigjmp_buf __env, int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));

// # 31 "/usr/include/setjmp.h" 2 3 4
extern int __sigsetjmp (struct __jmp_buf_tag __env[1], int __savemask) __attribute__ ((__nothrow__));

// # 193 "/usr/include/signal.h" 3 4
extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

// # 197 "/usr/include/grp.h" 3 4
extern int initgroups (const char *__user, __gid_t __group);

// # 61 "/usr/include/grp.h" 3 4
extern void endgrent (void);


// # 489 "/usr/include/unistd.h" 3 4
extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

// # 90 "/usr/include/netdb.h" 3 4
extern struct hostent *gethostbyaddr (const void *__addr, __socklen_t __len,
          int __type);

// # 217 "/usr/include/time.h" 3 4
extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));

// # 235 "/usr/include/netdb.h" 3 4
extern struct servent *getservbyname (const char *__name, const char *__proto);

#include "header_platform.h"

/* supporting definition for libbb.h */

#define LSA_LEN_SIZE 4
#define LSA_SIZEOF_SA 16

#if ENABLE_FEATURE_IPV6
# define LSA_SIZEOF_SA 28
#endif

#include "header_libbb.h"

#ifdef CHNETWORKING_UDHCP
#define CONFIG_UDHCPC_SLACK_FOR_BUGGY_SERVERS 80
# include "header_common.h"
#endif


#ifdef CHMISCUTILS_LESS
int less_main(int argc, char **argv);
#endif
