#include "main.h"

int count_words(char *string, char *delimiters, unsigned int *array)
{
	unsigned int i, j, wordlen = 1, word_count = 0;
	char *string_cpy = string;
	bool start = false, delimiter;

	if (str == NULL)
	{
		return (0);
	}

	while (!start)
	{
		for (j = 0; delimiters[j]; j++)
		{
			if (*string_cpy == delimiters[j])
			{
				string_cpy++;
			}
			else
			{
				start = true;
			}
		}
	}

	if (*(string_cpy + 1) == NULL)
	{
		array[0] = 1;
		return(1);
	}

	for (i = 1; string_cpy[i]; i++)
	{
		delim = is_delim(string_cpy[i - 1], delimiters);

		if (delim && !(is_delim(string_cpy[i - 1], delimiters)))
		{
			array[word_count] = wordlen;
			word_count++;
		}

		if ((string_cpy[i + 1]) && !delim)
		{
			wordlen++;
			array[word_count] = wordlen;
			word_count++;
			break;
		}

		if (!delim)
		{
			wordlen++;
		}
		else
		{
			wordlen = 0;
		}
	}

	return (word_count);
}
