#include "shell.h"

/**
 * env - print the current environment
 *
 * Return: Nothing
 */
void env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

void quite(void)
{
	_exit(0);
}

int main(void)
{
	if (1)
	{
		perror(getenv("PWD"));
	}
	env();
	quite();
	return (0);
}
