#include "simpleshell.h"

/**
 * _errputchar - print char
 *
 * @ch: char
 *
 * Return: integer
*/

int _errputchar(char ch)
{
	static int y;
	static char buffer[BUFF_SIZE_W];

	if (ch == BUFF_FLUSH || y >= BUFF_SIZE_W)
	{
		write(2, buffer, y);
		y = 0;
	}
	if (ch != BUFF_FLUSH)
		buffer[y++] = ch;
	return (1);
}
/**
 * _errputs - prints string
 *
 * @s: string
 *
 * Return: nothing
*/
void _errputs(char *s)
{
	int y = 0;

	if (!s)
		return;
	while (s[y] != '\0')
	{
		_errputchar(s[y]);
		y++;
	}
}
