#include "main.h"

void init_zero(unsigned int *array, size_t size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		array[i] = 0;
	}
}
