
#define CHNETWORKING_UDHCP

#include "../../shareddata/header.c"

static char *allocate_tempopt_if_needed(
		const struct dhcp_optflag *optflag,
		char *buffer,
		int *length_p);

static NOINLINE void attach_option(
		struct option_set **opt_list,
		const struct dhcp_optflag *optflag,
		char *buffer,
		int length);
