#include "unix_plugin.h"

unix_plugin_t	sample_plugin;

int
sample_plugin(int x)
{
	return x*2;
}
