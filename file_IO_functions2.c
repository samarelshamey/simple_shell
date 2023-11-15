#include "simpleshell.h"

/**
 * writehistory - create file
 *
 * @inf: information
 *
 * Return: integer
*/

int writehistory(info_type *inf)
{
	ssize_t fd;
	char *fname = gethistory(inf);
	list_type *node = NULL;

	if (!fname)
		return (-1);
	fd = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (fd == -1)
		return (-1);
	for (node = inf->history; node; node = node->next)
	{
		fd_puts(node->s, fd);
		fd_put('\n', fd);
	}
	fd_put(BUFF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * readhistory - read from file
 * @inf: information
 *
 * Return: integer
*/

int readhistory(info_type *inf)
{
	int y, l = 0, count = 0;
	ssize_t fd, len, size = 0;
	struct stat st;
	char *buffer = NULL, *fname = gethistory(inf);

	if (!fname)
		return (0);
	fd = open(fname, O_RDONLY);
	free(fname);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		size = st.st_size;
	if (size < 2)
		return (0);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (0);
	len = read(fd, buffer, size);
	buffer[size] = 0;
	if (len <= 0)
		return (free(buffer), 0);
	close(fd);
	for (y = 0; y < size; y++)
		if (buffer[y] == '\n')
		{
			buffer[y] = 0;
			buildinghistory(inf, buffer + l, count++);
			l = y + 1;
		}
	if (l != y)
		buildinghistory(inf, buffer + l, count++);
	free(buffer);
	inf->histc = count;
	while (inf->histc-- >= HISTORY_MAXIMUM)
		node_deletion(&(inf->history), 0);
	history_renumbering(inf);
	return (inf->histc);
}

