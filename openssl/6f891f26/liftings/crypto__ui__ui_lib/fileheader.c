#include "../../shareddata/header.c"

// crypto/ui/ui_lib.c

// static and global variable definitions

const struct ui_method_st * default_UI_meth
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",69) ));

// function signatures

struct ui_st * UI_new(void)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",71), chkx_binloc("0x11b808") ));

struct ui_st * UI_new_method(const struct ui_method_st * method)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",76), chkx_binloc("0x11b768") ));

void free_string(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",98), chkx_binloc("0x11ae04") ));

void UI_free(struct ui_st * ui)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",117), chkx_binloc("0x11b720") ));

int allocate_string_stack(struct ui_st * ui)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",126) ));

struct ui_string_st * general_allocate_prompt(struct ui_st * ui, const char * prompt, int prompt_freeable, enum UI_string_types type, int input_flags, char * result_buf)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",139) ));

int general_allocate_string(struct ui_st * ui, const char * prompt, int prompt_freeable, enum UI_string_types type, int input_flags, char * result_buf, int minsize, int maxsize, const char * test_buf)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",165), chkx_binloc("0x11b810") ));

int general_allocate_boolean(struct ui_st * ui, const char * prompt, const char * action_desc, const char * ok_chars, const char * cancel_chars, int prompt_freeable, enum UI_string_types type, int input_flags, char * result_buf)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",190), chkx_binloc("0x11b328") ));

int UI_add_input_string(struct ui_st * ui, const char * prompt, int flags, char * result_buf, int minsize, int maxsize)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",243), chkx_binloc("0x11bc44") ));

int UI_dup_input_string(struct ui_st * ui, const char * prompt, int flags, char * result_buf, int minsize, int maxsize)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",251), chkx_binloc("0x11bb9c") ));

int UI_add_verify_string(struct ui_st * ui, const char * prompt, int flags, char * result_buf, int minsize, int maxsize, const char * test_buf)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",270), chkx_binloc("0x11bb64") ));

int UI_dup_verify_string(struct ui_st * ui, const char * prompt, int flags, char * result_buf, int minsize, int maxsize, const char * test_buf)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",277), chkx_binloc("0x11bac8") ));

int UI_add_input_boolean(struct ui_st * ui, const char * prompt, const char * action_desc, const char * ok_chars, const char * cancel_chars, int flags, char * result_buf)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",296), chkx_binloc("0x11b6e4") ));

int UI_dup_input_boolean(struct ui_st * ui, const char * prompt, const char * action_desc, const char * ok_chars, const char * cancel_chars, int flags, char * result_buf)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",304), chkx_binloc("0x11b51c") ));

int UI_add_info_string(struct ui_st * ui, const char * text)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",364), chkx_binloc("0x11ba94") ));

int UI_dup_info_string(struct ui_st * ui, const char * text)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",370), chkx_binloc("0x11ba04") ));

int UI_add_error_string(struct ui_st * ui, const char * text)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",388), chkx_binloc("0x11b9d0") ));

int UI_dup_error_string(struct ui_st * ui, const char * text)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",394), chkx_binloc("0x11b940") ));

char * UI_construct_prompt(struct ui_st * ui, const char * object_desc, const char * object_name)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",411), chkx_binloc("0x11b1d0") ));

void * UI_add_user_data(struct ui_st * ui, void * user_data)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",446), chkx_binloc("0x11a8d4") ));

void * UI_get0_user_data(struct ui_st * ui)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",453), chkx_binloc("0x11a8e4") ));

const char * UI_get0_result(struct ui_st * ui, int i)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",458), chkx_binloc("0x11b12c") ));

int print_error(const char * str, unsigned long len, struct ui_st * ui)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",473), chkx_binloc("0x11ae54") ));

int UI_process(struct ui_st * ui)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",487), chkx_binloc("0x11afcc") ));

int UI_ctrl(struct ui_st * ui, int cmd, long i, void * p, void (*f)(void))
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",549), chkx_binloc("0x11aacc") ));

int UI_get_ex_new_index(long argl, void * argp, int (*new_func)(void * parent, void * ptr, struct crypto_ex_data_st * ad, int idx, long argl, void * argp), int (*dup_func)(struct crypto_ex_data_st * to, struct crypto_ex_data_st * from, void * from_d, int idx, long argl, void * argp), void (*free_func)(void * parent, void * ptr, struct crypto_ex_data_st * ad, int idx, long argl, void * argp))
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",576), chkx_binloc("0x11af94") ));

int UI_set_ex_data(struct ui_st * r, int idx, void * arg)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",583), chkx_binloc("0x11af8c") ));

void * UI_get_ex_data(struct ui_st * r, int idx)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",588), chkx_binloc("0x11af84") ));

void UI_set_default_method(const struct ui_method_st * meth)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",593), chkx_binloc("0x11a8ec") ));

const struct ui_method_st * UI_get_default_method(void)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",598), chkx_binloc("0x11af44") ));

const struct ui_method_st * UI_get_method(struct ui_st * ui)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",607), chkx_binloc("0x11a908") ));

const struct ui_method_st * UI_set_method(struct ui_st * ui, const struct ui_method_st * meth)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",612), chkx_binloc("0x11a910") ));

struct ui_method_st * UI_create_method(char * name)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",619), chkx_binloc("0x11aec8") ));

void UI_destroy_method(struct ui_method_st * ui_method)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",634), chkx_binloc("0x11ade0") ));

int UI_method_set_opener(struct ui_method_st * method, int (*opener)(struct ui_st * ui))
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",641), chkx_binloc("0x11a91c") ));

int UI_method_set_writer(struct ui_method_st * method, int (*writer)(struct ui_st * ui, struct ui_string_st * uis))
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",652), chkx_binloc("0x11a930") ));

int UI_method_set_flusher(struct ui_method_st * method, int (*flusher)(struct ui_st * ui))
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",663), chkx_binloc("0x11a944") ));

int UI_method_set_reader(struct ui_method_st * method, int (*reader)(struct ui_st * ui, struct ui_string_st * uis))
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",674), chkx_binloc("0x11a958") ));

int UI_method_set_closer(struct ui_method_st * method, int (*closer)(struct ui_st * ui))
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",685), chkx_binloc("0x11a96c") ));

int UI_method_set_prompt_constructor(struct ui_method_st * method, char * (*prompt_constructor)(struct ui_st * ui, const char * object_desc, const char * object_name))
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",696), chkx_binloc("0x11a980") ));

int (*UI_method_get_opener(struct ui_method_st * method))(struct ui_st * $par$1)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",707), chkx_binloc("0x11a994") ));

int (*UI_method_get_writer(struct ui_method_st * method))(struct ui_st * $par$1, struct ui_string_st * $par$2)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",715), chkx_binloc("0x11a9a0") ));

int (*UI_method_get_flusher(struct ui_method_st * method))(struct ui_st * $par$1)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",723), chkx_binloc("0x11a9ac") ));

int (*UI_method_get_reader(struct ui_method_st * method))(struct ui_st * $par$1, struct ui_string_st * $par$2)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",731), chkx_binloc("0x11a9b8") ));

int (*UI_method_get_closer(struct ui_method_st * method))(struct ui_st * $par$1)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",739), chkx_binloc("0x11a9c4") ));

char * (*UI_method_get_prompt_constructor(struct ui_method_st * method))(struct ui_st * $par$1, const char * $par$2, const char * $par$3)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",747), chkx_binloc("0x11a9d0") ));

enum UI_string_types UI_get_string_type(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",755), chkx_binloc("0x11a9dc") ));

int UI_get_input_flags(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",762), chkx_binloc("0x11a9e8") ));

const char * UI_get0_output_string(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",769), chkx_binloc("0x11a9f4") ));

const char * UI_get0_action_string(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",776), chkx_binloc("0x11aa00") ));

const char * UI_get0_result_string(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",790), chkx_binloc("0x11aa2c") ));

const char * UI_get0_test_string(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",804), chkx_binloc("0x11aa54") ));

int UI_get_result_minsize(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",817), chkx_binloc("0x11aa7c") ));

int UI_get_result_maxsize(struct ui_string_st * uis)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",831), chkx_binloc("0x11aaa4") ));

int UI_set_result(struct ui_st * ui, struct ui_string_st * uis, const char * result)
   __attribute__ (( chkc_srcloc("crypto/ui/ui_lib.c",845), chkx_binloc("0x11ab84") ));

