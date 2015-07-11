#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <err.h>

#include "unix_plugin.h"

int
main(int argc, char **argv)
{
	unix_plugin_t	*func;
	void	*dll;
	char *fname;
	int e;

	if (argc != 2) {
		errx(EXIT_FAILURE, "unix_plugin usage!");
	}
	fname = argv[1];
	dll = dlopen(fname, RTLD_NOW);
	if (dll == NULL) {
		errx(EXIT_FAILURE, "dlopen()");
	}
	func = (unix_plugin_t *)dlsym(dll, "sample_plugin");
	if (func == NULL) {
		errx(EXIT_FAILURE, "No sample_plugin");
	}
	printf("Value: %d\n", func(123));
	e = dlclose(dll);
	assert(e == 0);
	exit(EXIT_SUCCESS);
}
