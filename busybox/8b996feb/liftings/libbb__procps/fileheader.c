#define CHLIBBB_PROCPS

#include "../../shareddata/header.c"


typedef struct id_to_name_map_t {
	uid_t id;
	char name[USERNAME_MAX_SIZE];
} id_to_name_map_t;

typedef struct cache_t {
	id_to_name_map_t *cache;
	int size;
} cache_t;

static cache_t username, groupname;

// line 27
static void clear_cache(cache_t *cp);

// line 55
static char* get_cached(cache_t *cp, uid_t id,
			char* FAST_FUNC x2x_utoa(uid_t id));

// line 81
static int read_to_buf(const char *filename, void *buf);

// line 124
static unsigned long fast_strtoul_16(char **endptr);

// line 144
static unsigned long fast_strtoul_10(char **endptr);

// lines 168
static char *skip_fields(char *str, int count);

// Global variables

/* 0x6d7ec */
cache_t username;

/* 0x6d7f4 */
cache_t groupname;
