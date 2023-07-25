#include "main.h"

char **tokenize(char *string, char* delimiter, size_t *word_count)
{
	int i, j;
	char **words;
	char *string_ptr = string;
	bool start = false;
	unsigned int word_num;
	unsigned int word_size[100];

	init_zero(word_size, 100);
	word_num = count_word(string, delimiter, word_size);

	if(word_num == 0)
	{
		return (NULL);
	}

	words = malloc((sizeof(char *) * word_num) + 1);
	if (words == NULL)
	{
		return (NULL);
	}

	for (j = 0; j < word_num; j++)
	{
		words[j] = malloc((sizeof(char) * word_size[j]) + 1);
		if (words[j] == NULL)
		{
			for (j--; j >= 0; j--)
			{
				free(words[j]);
			}
			free(words);
			return (NULL);
		}

		for (i = 0; i < word_size[j]; i++, string_ptr++)
		{
			while (!is_delim(*string_ptr, delimiter))
			{
				string_ptr++;
			}

			words[j][i] = *string_ptr;
		}

		words[j][i] = '\0';
	}

	*word_count = word_num;

	words[j] = NULL;

	return (words);
}
