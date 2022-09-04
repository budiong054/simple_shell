#include "shell.h"

/**
 * _readline - read characters from the terminal
 *
 * Return: The address of the string read
 */

char *_readline(void)
{
	char *lineptr;
	size_t n = BUFF_SIZE;
	int nread;

	lineptr = malloc(sizeof(char) * n);
	if (!lineptr)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	nread = getline(&lineptr, &n, stdin);
	if (nread == -1)
	{
		free(lineptr);
		print(STDIN_FILENO, "\n");
		return (NULL);
	}
	return (lineptr);
}

/**
 * tokenize - split a string into words
 * @str: address of the string
 *
 * Return: array of string or NULL if it fails
 */
char **tokenize(char *str)
{
	int i = 0, j, k, size = 0;
	char **args, *token;
	char delim[] = " \t\n";

	if (!str)
		return (NULL);
	for (j = 0; str[j]; j++)
	{
		if (is_delim(delim, str[j]))
			continue;
		k = j;
		while (!is_delim(delim, str[j]) && str[j])
			j++;
		if (j > k)
			size++;
	}
	args = malloc(sizeof(char *) * (size + 1));
	if (args == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
		return (NULL);
	}
	token = strtok(str, delim);
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = token;
	return (args);
}

/**
 * execute - execute a program refered to by the pathname
 * @pathname: The program pathname
 * @args: an array of arguments strings passed
 * @envp: an array of strings
 * @argv: The program name
 *
 * Return: Nothing
 */

void execute(char *pathname, char *args[], char *envp[], char *argv)
{
	int status;
	pid_t id;

	id = fork();
	if (id == 0)
	{
		if (!pathname)
		{
			/* problem 1 with valgrind */
			exit(EXIT_SUCCESS);
		}
		if (execve(pathname, args, envp) == -1 && pathname)
		{
			/* problem 2 with valgrind */
			print(STDERR_FILENO, "%s: 1: %s: not found\n", argv, pathname);
			exit(EXIT_FAILURE);
		}
	}
	else if (id == -1)
	{
		perror("Error 2");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
