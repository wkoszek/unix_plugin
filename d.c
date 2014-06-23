#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "d.h"

#define	SECNAME	"chuj"
#define	START	"__start_" SECNAME
#define	END	"__stop_" SECNAME

int
main(int argc, char **argv)
{
	void *dll = NULL;
	char *fname = NULL;
	int e = 0;
	struct d *dbegin = NULL;
	struct d *dend = NULL;
	struct d *dptr;

	if (argc != 2)
		exit(EXIT_FAILURE);
	fname = argv[1];
	dll = dlopen(strdup(fname), RTLD_NOW);
	if (dll == NULL)
		err(EXIT_FAILURE, "dlopen()");
	dbegin = dlsym(dll, START);
	if (dbegin == NULL)
		err(EXIT_FAILURE, "No " START);
	dend = dlsym(dll, END);
	if (dend == NULL)
		err(EXIT_FAILURE, "No " END);
	for (dptr = dbegin; dptr < dend; dptr++)
		printf("Value: %d\n", dptr->ericsson);
	e = dlclose(dll);
	assert(e == 0);
	exit(EXIT_SUCCESS);
}
