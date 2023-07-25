#include "main.h"

char *file_path_check(char *filename, struct stat *statusbuffer)
{
	size_t i, path_num;
	char *fullpath, *cuurentpath = _getenv("PATH"), **paths = tokenize(currentpath, ":", &path_num);

	for (i = 0; i < path_num; i++)
	{
		fullpath = strs_concat(3, paths[i], "/", filename);

		if (file_stat_check(fullpath, statusbuffer))
		{
			free_array(paths, path_num);
			return (fullpath);
		}
	}

	free_array(paths, path_num);
	free(fullpath);
	return (NULL);
}
