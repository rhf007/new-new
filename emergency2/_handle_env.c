#include "main.h"

void _handle_env(char **env_arguments, size_t arg_num)
{
	if (env_arguments[1] == NULL)
	{
		_print_env();
	}

	free_array(env_arguments, arg_num);
}

void _print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}
