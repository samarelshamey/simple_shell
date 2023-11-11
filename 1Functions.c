#include "simpleshell.h"

/**
 * is_delimeter - checks for a delimeter
 *
 * @ch: character
 *
 * @delimeter: delimeter string
 *
 * Return: integer
*/
int is_delimeter(char ch, char *delimeter)
{
	while (*delimeter)
		if (*delimeter++ == ch)
			return (1);
	return (0);
}
/**
 * _erroratoi - convert string to integer
 *
 * @string: string to be converted
 *
 * Return: integer
*/
int _erroratoi(char *string)
{
	int g = 0;
	unsigned long int res = 0;

	if (*string == '+')
		string++;
	for (g = 0; string[g] != '\0'; g++)
	{
		if (string[g] >= '0' && string[g] <= '9')
		{
			res *= 10;
			res += (string[g] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * interactive_mode - check if shell is in interactive mode
 *
 * @information: address
 *
 * Return: integer
*/

int interactive_mode(info_type *information)
{
	return (isatty(STDIN_FILENO) && information->readfd <= 2);
}

/**
 * error_printing - print error message
 *
 * @information: info
 *
 * @str: string
 *
 * Rturn: nothing
*/
void error_printing(info_type *information, char *str)
{
	_errputs(information->fname);
	_errputs(": ");
	decimal_printing(information->err_count, STDERR_FILENO);
	_errputs(": ");
	_errputs(information->argv[0]);
	_errputs(": ");
	_errputs(str);
}
/**
 * _isalphabet - checks for alphabetic
 *
 * @ch: character
 *
 * Return: integer
*/
int _isalphabet(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}
