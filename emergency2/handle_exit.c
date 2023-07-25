#include "main.h"

void handle_exit(char **exit_arguments, size_t arg_num)
{
	int status = EXIT_SUCCESS;

	if (exit_arguments[1])
	{
		status = _atoi(exit_arguments[1]);
	}

	free_array(exit_arguments, arg_num);
	exit(status);
}
