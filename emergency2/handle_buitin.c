#include "main.h"

bool handle_builtin(char **arguments, size_t arg_num)
{
	if (_strncmp(arguments[0], "exit", 4) == 0)
	{
		handle_exit(arguments, arg_num);
	}
	else if ((_strncmp(arguments[0], "env", 3) == 0) || (_strncmp(arguments[0], "printenv", 8) == 0))
	{
		handle_env(arguments, arg_num);
		return (true);
	}

	return (false);
}
