#include "simpleshell.h"

/**
 * path_finding - find cmd path
 *
 * @inf: information
 *
 * @path: path strinh
 *
 * @commd: command
 *
 * Return: char
*/
char *path_finding(info_type *inf, char *path, char *commd)
{
	char *p;
	int y = 0, pos = 0;

	if (!path)
		return (NULL);
	if ((_strlength(commd) > 2) && startwith(commd, "./"))
	{
		if (is_commd(inf, commd))
			return (commd);
	}
	while (1)
	{
		if (!path[y] || path[y] == ':')
		{
			p = charsDuplicate(path, pos, y);
			if (!*p)
				_strconcat(p, commd);
			else
			{
				_strconcat(p, "/");
				_strconcat(p, commd);
			}
			if (is_commd(inf, p))
				return (p);
			if (!path[y])
				break;
			pos = y;
		}
		y++;
	}
	return (NULL);
}
/**
 * is_commd - check if execute command
 *
 * @inf: information
 *
 * @p: path
 *
 * Return: integer
*/
int is_commd(info_type *inf, char *p)
{
	struct stat st;

	(void)inf;
	if (!p || stat(p, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * charsDuplicate - deuplicate charac
 *
 * @path: path
 *
 * @star: start
 *
 * @stp: stop
 *
 * Return: character
*/
char *charsDuplicate(char *path, int star, int stp)
{
	int y = 0, x = 0;
	static char buffer[1024];

	for (x = 0, y = star; y < stp; y++)
		if (path[y] != ':')
			buffer[x++] = path[y];
	buffer[x] = 0;
	return (buffer);
}
