#include"main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int lencount = 0;

	while (*s != '\0')
	{
		lencount++;
		s++;
	}
	return (lencount);
}
