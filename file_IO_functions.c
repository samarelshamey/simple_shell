#include "simpleshell.h"

/**
 * gethistory - get history file
 *
 * @inf: information
 *
 * Return: char
*/
char *gethistory(info_type *inf)
{
	char *buffer, *direc;

	direc = getting_environ_value(inf, "HOME=");
	if (!direc)
		return (NULL);
	buffer = malloc(sizeof(char) *
			(_strlength(direc) + _strlength(HISTORY_FILE) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcopy(buffer, direc);
	_strconcat(buffer, "/");
	_strconcat(buffer, HISTORY_FILE);
	return (buffer);
}
/**
 * buildinghistory - add new entries to history
 *
 * @inf: information
 *
 * @buffer: buffer
 *
 * @count: line count
 *
 * Return: integer
*/

int buildinghistory(info_type *inf, char *buffer, int count)
{
	list_type *node = NULL;

	if (inf->history)
		node = inf->history;
	node_at_end(&node, buffer, count);
	if (!inf->history)
		inf->history = node;
	return (0);
}

/**
 * history_renumbering - renumber after changes
 *
 * @inf: information
 *
 * Return: integer
*/

int history_renumbering(info_type *inf)
{
	int y = 0;
	list_type *node = inf->history;

	while (node)
	{
		node->n = y++;
		node = node->next;
	}
	return (inf->histc = y);
}
