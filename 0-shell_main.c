#include "shell.h"

/**
 * main - Shell entry point
 * @argc: number of argument passed to the program
 * @argv: address of strings passed to the program
 *
 * Return: 0 on success
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	char *line, **args;
	int int_mode, exit_flag;

	exit_flag = 1;

	signal(SIGINT, ctrl_c);
	while (exit_flag)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode)
			print(STDOUT_FILENO, "($) ");
		line = _readline();
		if (!line)
			break;
		args = tokenize(line);
		if (!args)
		{
			perror("Error 3");
			exit(EXIT_FAILURE);
		}
		if (_strcmp(args[0], "env") == 0)
			env();
		else if (_strcmp(args[0], "exit") == 0)
		{
			exit_flag = 0;
			quit();
		}
		else
			execute(args[0], args, NULL, argv[0]);
		free(args);
		free(line);
	}
	return (0);
}
