#include "shell.h"

/**
 * print - write to stdout/ stderr
 * @fd: file descriptor
 * @format: The format to be printed out to a file descriptor
 *
 * Return: number of charater written or -1 on error
 */
int print(int fd, const char *format, ...)
{
	int i, j, count = 0;
	va_list args;
	char *str;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(fd, &format[i], sizeof(char));
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(args, char *);
			j = 0;
			while (str[j])
			{
				write(fd, &str[j], sizeof(char));
				j++;
			}
			i++;
			count += j;
		}
	}
	return (count);
}

/**
 * ctrl_c - print the terminal again when ctrl+c is pressed
 * @signum: The signal ctrl+c sends
 *
 * Return: Nothing
 */
void ctrl_c(int signum)
{
	if (signum == SIGINT)
		print(STDOUT_FILENO, "\n($) ");
}

/**
 * is_delim - check if a character is a delimiter
 * @delim: The delimiters string
 * @c: The character to be checked
 *
 * Return: 1 if it's true and 0 if false
 */

int is_delim(char *delim, char c)
{
	int i = 0;

	while (delim[i])
	{
		if (delim[i] == c)
			return (1);
		i++;
	}
	return (0);
}
