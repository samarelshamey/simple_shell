#include "simpleshell.h"

/**
 * signal_handling - handle sign
 *
 * @num: signal number
 *
 * Return: nothing
*/
void signal_handling(__attribute__((unused))int num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFF_FLUSH);
}

/**
 * _getline - get the input
 *
 * @inf: information
 *
 * @p: pointer
 *
 * @len: length
 *
 * Return:  integer
*/
int _getline(info_type *inf, char **p, size_t *len)
{
	char *ptr = NULL, *newptr = NULL, *ch;
	static char buffer[BUFF_SIZE];
	static size_t y, l;
	ssize_t m = 0, n = 0;
	size_t x;

	ptr = *p;
	if (ptr && len)
		n = *len;
	if (y == l)
		y = l = 0;
	m = buffer_reading(inf, buffer, &l);
	if (m == -1 || (m == 0 && l == 0))
		return (-1);
	ch = _stringcharacter(buffer + y, '\n');
	x = ch ? 1 + (unsigned int)(ch - buffer) : l;
	newptr = _realloc(ptr, n, n ? n + x : x + 1);
	if (!newptr)
		return (ptr ? free(ptr), -1 : 1);

	if (n)
		_stringconcat(newptr, buffer + y, x - y);
	else
		_stringconcat(newptr, buffer + y, x - y + 1);
	n += x - y;
	y = x;
	ptr = newptr;
	if (len)
		*len = n;
	*p = ptr;
	return (n);
}
