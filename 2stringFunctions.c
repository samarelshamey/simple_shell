#include "simpleshell.h"

/**
 * _stringcopy - copy strings
 *
 * @destination: destination string
 *
 * @source: string source
 *
 * @m: the number of char to be copied
 *
 * Return: pointer char
*/

char *_stringcopy(char *destination, char *source, int m)
{
	int h, j;
	char *s = destination;

	h = 0;
	while (source[h] != '\0' && h < m - 1)
	{
		destination[h] = source[h];
		h++;
	}
	if (h < m)
	{
		j = h;
		while (j < m)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _stringconcat - concatenates strings
 *
 * @s1: first string
 *
 * @s2: second string
 *
 * @m: number of bytes
 *
 * Return: char pointer
*/
char *_stringconcat(char *s1, char *s2, int m)
{
	int h, j;
	char *s = s1;

	h = 0;
	j = 0;
	while (s1[h] != '\0')
		h++;
	while (s2[j] != '\0' && j < m)
	{
		s1[h] = s2[j];
		h++;
		j++;
	}
	if (j < m)
		s1[h] = '\0';
	return (s);
}
/**
 * _strduplicate - string duplicate
 *
 * @string: string
 *
 * Return: pointer
*/
char *_strduplicate(const char *string)
{
	int len = 0;
	char *x;

	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;
	x = malloc(sizeof(char) * (len + 1));
	if (!x)
		return (NULL);
	for (len++; len--;)
		x[len] = *--string;
	return (x);
}

