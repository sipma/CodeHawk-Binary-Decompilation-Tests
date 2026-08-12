
#define CHMISCUTILS_LESS

#define ENABLE_FEATURE_LESS_REGEXP    0

// from status_print
#define ENABLE_FEATURE_LESS_FLAGS     0

// from buffer_fill_and_print
#define ENABLE_FEATURE_LESS_DASHCMD   0

// from getch_nowait
#define ENABLE_FEATURE_LESS_WINCH     0


#include "../../shareddata/header.c"

// line 253
static void set_tty_cooked(void);

// line 261
static void move_cursor(int line, int row);

// line 266
static void clear_line(void);

// line 271
static void print_hilite(const char *str);

// line 276
static void print_statusline(const char *str);

// line 283
static void less_exit(int code);

// line 407
static void read_lines(void);

// line 571
static void buffer_print(void);

// line 597
static void status_print(void);

// line 752
static void print_ascii(const char *str);

// line 789
static void buffer_print(void);

// line 802
static void buffer_fill_and_print(void);

// line 838
static void buffer_down(int nlines);

// line 846
static void buffer_up(int nlines);

// line 854
static void buffer_line(int linenum);

// line 885
static void reinitialize(void);

// line 907
static int64_t getch_nowait(void);

// line 977
static int64_t less_getch(int pos);

// line 997
static char* less_gets(int sz);

// line 1028
static void examine_file(void);

// line 1059
static void change_file(int direction);


// Local globals

struct globals {
  int cur_fline; /* signed */                           /*   0 */
  int kbd_fd;  /* fd to get input from */               /*   4 */
  int less_gets_pos;                                    /*   8 */
  /* last position in last line, taking into account tabs */
  size_t last_line_pos;                                 /*  12 */
  unsigned max_fline;                                   /*  16 */
  unsigned max_lineno; /* this one tracks linewrap */   /*  20 */
  unsigned max_displayed_line;                          /*  24 */
  unsigned width;                                       /*  28 */
#if ENABLE_FEATURE_LESS_WINCH
  unsigned winch_counter;
#endif
  ssize_t eof_error; /* eof if 0, error if < 0 */
  ssize_t readpos;
  ssize_t readeof; /* must be signed */
  const char **buffer;
  const char **flines;
  const char *empty_line_marker;
  unsigned num_files;
  unsigned current_file;
  char *filename;
  char **files;
#if ENABLE_FEATURE_LESS_MARKS
  unsigned num_marks;
  unsigned mark_lines[15][2];
#endif
#if ENABLE_FEATURE_LESS_REGEXP
  unsigned *match_lines;
  int match_pos; /* signed! */
  int wanted_match; /* signed! */
  int num_matches;
  regex_t pattern;
  smallint pattern_valid;
#endif
#if ENABLE_FEATURE_LESS_ASK_TERMINAL
  smallint winsize_err;
#endif
  smallint terminated;
  struct termios term_orig, term_less;                 /*  76 */
  char kbd_input[KEYCODE_BUFFER_SIZE];
};


struct globals *less_globals;
