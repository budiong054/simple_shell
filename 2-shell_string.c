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

/* remove me please */

/**
 * _strcmp - compare two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: 0 if they are equal, -1 if not equal
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, len1, len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (len1 != len2)
		return (-1);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
