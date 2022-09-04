#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: The address of the string
 *
 * Return: The length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * _strcat - concatenate a string with '/' character in between
 * @dest: pointer to the destination
 * @src: pointer to the source
 *
 * Return: The pointer to the concatenated string, or NULL
 */

char *_strcat(char *dest, char *src)
{
	int i, j, len1, len2;
	char *ptr;

	ptr = dest;
	len1 = _strlen(dest);
	len2 = _strlen(src);
	dest = malloc(sizeof(char) * (len1 + len2 + 2));
	if (!dest)
		return (NULL);
	for (i = 0; ptr[i]; i++)
		dest[i] = ptr[i];
	dest[i] = '/';
	j = ++i;
	for (i = 0; src[i]; i++, j++)
		dest[j] = src[i];
	dest[j] = '\0';
	return (dest);
}
