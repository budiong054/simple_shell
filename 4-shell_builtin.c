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
