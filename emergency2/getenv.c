#include "main.h"

char *_getenv(char *key)
{
	char **ptr = environ;
	size_t namelen = _strlen(key);

	while (*ptr)
	{
		if (_strncmp(*ptr, key, namelen) == 0 && (*ptr)[namelen] == "=")
		{
			return (&((*ptr)[namlen + 1]));
		}
		ptr++;
	}

	return (NULL);
}
