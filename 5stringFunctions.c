#include "simpleshell.h"

/**
 * stringtow - function to split string
 *
 * @string: string
 *
 * @delimeter: delimeter string
 *
 * Return: pointer to array
 */

char **stringtow(char *string, char *delimeter)
{
	int g, h, k, m, wordsnumber = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!delimeter)
		delimeter = " ";
	for (g = 0; string[g] != '\0'; g++)
		if (is_delimeter(string[g], delimeter) &&
				(is_delimeter(string[g + 1], delimeter) || !string[g + 1]))
			wordsnumber++;
	if (wordsnumber == 0)
		return (NULL);
	s = malloc((1 + wordsnumber) * sizeof(char *));
	if (!s)
		return (NULL);
	for (g = 0, h = 0; h < wordsnumber; h++)
	{
		while (is_delimeter(string[g], delimeter))
			g++;
		k = 0;
		while (is_delimeter(string[g + k], delimeter) && string[g + k])
			k++;
		s[h] = malloc((k + 1) * sizeof(char));
		if (!s[h])
		{
			for (k = 0; k < h; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[h][m] = string[g++];
		s[h][m] = 0;
	}
	s[h] = NULL;
	return (s);
}
/**
 * stringtow2 - split strings
 *
 * @string: string
 *
 * @delimeter: delimeter
 *
 * Return: pointer to an array
*/
char **stringtow2(char *string, char delimeter)
{
	int g, h, k, m, wordsnumber = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);
	for (g = 0; string[g] != '\0'; g++)
		if ((string[g] != delimeter && string[g + 1] == delimeter) ||
					(string[g] != delimeter && !string[g + 1]) ||
					 string[g + 1] == delimeter)
			wordsnumber++;
	if (wordsnumber == 0)
		return (NULL);
	s = malloc((1 + wordsnumber) * sizeof(char *));
	if (!s)
		return (NULL);
	for (g = 0, h = 0; h < wordsnumber; h++)
	{
		while (string[g] == delimeter && string[g] != delimeter)
			g++;
		k = 0;
		while (string[g + k] != delimeter && string[g + k] &&
				string[g + h] != delimeter)
			k++;
		s[h] = malloc((k + 1) * sizeof(char));
		if (!s[h])
		{
			for (k = 0; k < h; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[h][m] = string[g++];
		s[h][m] = 0;
	}
	s[h] = NULL;
	return (s);
}
