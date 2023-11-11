#include "simpleshell.h"

/**
 * fd_put - print char
 *
 * @ch: character
 *
 * @fd: field descriptor
 *
 * Return: integer
*/
int fd_put(char ch, int fd)
{
	static int y;
	static char buffer[BUFF_SIZE];

	if (ch == BUFF_FLUSH || y >= BUFF_SIZE)
	{
		write(fd, buffer, y);
		y = 0;
	}
	if (ch != BUFF_FLUSH)
		buffer[y++] = ch;
	return (1);
}
/**
 * fd_puts - print string
 *
 * @s: string
 *
 * @fd: field descriptor
 *
 * Return:integer
 */
int fd_puts(char *s, int fd)
{
	int y = 0;

	if (!s)
		return (0);
	while (s)
	{
		y += fd_put(*s, fd);
	}
	return (y);
}
