#include "simpleshell.h"

/**
 * _strlength - function to check string length
 *
 * @s: string
 *
 * Return: intger
*/
int _strlength(char *s)
{
	int y = 0;

	if (!s)
		return (0);
	while (*s++)
		y++;
	return (y);
}

/**
 * startwith - check start with hay
 *
 * @word: string to search
 *
 * @needle: the substring to find
 *
 * Return: char pointer
*/

char *startwith(const char *word, const char *needle)
{
	while (*needle)
		if (*needle++ != *word++)
			return (NULL);
	return ((char *)word);
}

/**
 * _strcompare - function compare two strings
 *
 * @s1: first string
 *
 * @s2: second string
 *
 * Return: integer
*/
int _strcompare(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
