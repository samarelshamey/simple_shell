#include "simpleshell.h"

/**
 * _stringcharacter - check char in a string
 *
 * @string: string
 *
 * @ch: charachter
 *
 * Return: pointer
*/

char *_stringcharacter(char *string, char ch)
{
	do {
		if (*string == ch)
			return (string);
	} while (*string++ != '\0');
	return (NULL);
}

/**
 * _strcopy - function to copy string
 *
 * @destination: destination
 *
 * @source: source
 *
 * Return: pointer
*/

char *_strcopy(char *destination, char *source)
{
	int y = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[y])
	{
		destination[y] = source[y];
		y++;
	}
	destination[y] = 0;
	return (destination);
}
/**
 * _strconcat - concatenates strings
 *
 * @destination: destination buffer
 *
 * @source: source buffer
 *
 * Return: pointer
*/
char *_strconcat(char *destination, char *source)
{
	char *y = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (y);
}
