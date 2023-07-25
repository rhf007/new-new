#include "main.h"

int _strncmp(char *str1, char *str2, size_t size)
{
	int i, difference;

	for (i = 0; i < n; i++)
	{
		difference = str1[i] - str2[i];
		if (difference > 0 || difference < 0)
		{
			return (difference);
		}
	}

	return (0);
}
