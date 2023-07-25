int main(int argc, char *argv[], char *env[])
{
	char *buffer = NULL, *shprmpt = "$ ", *fullpath, **arguments;
	size_t  buffersize = 0, arg_num;
	ssize_t bytes;
	pid_t pid;
	int status;
	bool piped = false;
	struct stat statusbuffer; //struct stat  holds file metadata, extremely usefull, will save us a a lot of time

	while (1 && !piped)//we might need that later
	{
		//check if input is from the terminal or is piped
		if (isatty(STDIN_FILENO == 0))
		{
			piped = true;
		}

		//made _putchar & _puts beacuse printf is forbidden
		_puts(shprmpt);

		//they say getline is better than fgets and doc says we have to free memory allocated by getline
		bytes = getline(&buffer, &buffersize, stdin);
		
		if (bytes == -1)
		{
			perror("Couldn't Read Bytes");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		if (buffer[bytes - 1] == '\n')
		{
			buffer[bytes - 1] = '\0';
		}

		arguments = tokenize(buffer, " ", &arg_num);

		if (handle_builtin(arguments, arg_num))
		{
			continue;
		}

		if (!file_stat_check(arguments[0], &statusbuffer))
		{
			fullpath = file_path_check(args[0], &statusbuffer);
			if (fullpath == NULL)
			{
				perror("Can't Get Status");
				free_array(arguments, arg_num);
				continue;
			}
			else
			{
				free(arguments[0]);
				arguments[0] = fullpath;
			}
		}

		pid = fork();

		if (pid == -1)
		{
			perror("Can't Fork");
			free_array(arguments, arg_num);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			execute(arguments, arg_num, env);
		}

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Can't Wait");
			free_array(arguments, arg_num);
			exit(EXIT_FAILURE);
		}
	}

	free(buffer);
	return (0);
}

int _execute(char **args, int arg_num, char **envp)
{
	execve(args[0], args, envp);
	free_array(args, arg_num);
	perror("Can't Execute");
	exit(EXIT_FAILURE);
}
