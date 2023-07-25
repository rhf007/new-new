#include "main.h"

int main (int argc, char **argv, char **env)
{
	size_t x;
	int i;

	char *path =_getenv("PATH");
	char **paths = split_string(path, ":",&x);

	for (i = 0; paths[i]; i++)
	{
		_puts(paths[i]);
	}
	free_array(paths, x);
	return (0);
}
