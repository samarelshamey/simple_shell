#include "simpleshell.h"

/**
 * _puts - function to print
 *
 * @string: string
 *
 * Return: nothing
*/
void _puts(char *string)
{
	int y = 0;

	if (!string)
		return;
	while (string[y] != '\0')
	{
		_putchar(string[y]);
		y++;
	}
}
/**
 * _putchar - print the char
 *
 * @ch: character
 *
 * Return: integer
*/

int _putchar(char ch)
{
	static int h;
	static char buffer[BUFF_SIZE_W];

	if (ch == BUFF_FLUSH || h >= BUFF_SIZE_W)
	{
		write(1, buffer, h);
		h = 0;
	}
	if (ch != BUFF_FLUSH)
		buffer[h++] = ch;
	return (1);
}
