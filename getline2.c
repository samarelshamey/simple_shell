#include "simpleshell.h"

/**
 * buffer_reading - read buffer
 *
 * @inf: information
 *
 * @buffer: buffer
 *
 * @size: size
 *
 * Return: size
*/
ssize_t buffer_reading(info_type *inf, char *buffer, size_t *size)
{
	ssize_t i = 0;

	if (*size)
		return (0);
	i = read(inf->readfd, buffer, BUFF_SIZE_R);
	if (i >= 0)
		*size = i;
	return (i);
}

/**
 * buffer_input - buffer commands
 *
 * @inf: information
 *
 * @buffer: buffer
 *
 * @l: length
 *
 * Return: read bytes
*/
ssize_t buffer_input(info_type *inf, char **buffer, size_t *l)
{
	size_t len = 0;
	ssize_t i = 0;

	if (!*l)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, signal_handling);
#if GET_LINE
			i = getline(buffer, &len, stdin);
#else
			i = _getline(inf, buffer, &len);
#endif
			if (i > 0)
			{
				if ((*buffer)[i - 1] == '\n')
				{
					(*buffer)[i - 1] = '\0';
					i--;
				}
				inf->linecount_f = 1;
				comment_remove(*buffer);
				buildinghistory(inf, *buffer, inf->histc++);
				if (_stringcharacter(*buffer, ';'))
				{
					*l = i;
					inf->commd_buff = buffer;
				}
			}
	}
	return (i);
}
/**
 * gettinginput - get line
 *
 * @inf: information
 *
 * Return: read byte
*/
ssize_t gettinginput(info_type *inf)
{
	static size_t y, k, l;
	ssize_t i = 0;
	char **buff = &(inf->argument), *ptr;
	static char *buffer;

	_putchar(BUFF_FLUSH);
	i = buffer_input(inf, &buffer, &l);
	if (i == -1)
		return (-1);
	if (l)
	{
		k = y;
		ptr = buffer + y;
		check_multicommand(inf, buffer, &k, y, l);
		while (k < l)
		{
			if (is_multicommand(inf, buffer, &k))
				break;
			k++;
		}
		y = k + 1;
		if (y >= l)
		{
			y = l = 0;
			inf->commd_buf_type = NORM_COMMD;
		}
		*buff = ptr;
		return (_strlength(ptr));
	}
	*buff = buffer;
	return (i);
}
