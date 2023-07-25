#include "main.h"

bool file_stat_check(char *pathname, struct stat *statusbuffer)
{
	int statusreturn;

	statusreturn = stat(pathname, &statusbuffer);

	if (statusreturn == 0)
	{
		return (true);
	}

	return (false);
}
