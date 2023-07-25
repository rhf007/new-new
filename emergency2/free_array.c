#include "main.h"

void free_array(char **array, int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		free(array[i]);
	}
	free(array);
}
