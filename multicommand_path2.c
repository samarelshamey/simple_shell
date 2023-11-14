#include "simpleshell.h"

/**
 * alias_replacement - replace alias
 *
 * @inf: information
 *
 * Return: integer
*/
int alias_replacement(info_type *inf)
{
	char *ptr;
	int y;
	list_type *node;

	for (y = 0; y < 10; y++)
	{
		node = node_starts(inf->alias, inf->argv[0], '=');
		if (!node)
			return (0);
		free(inf->argv[0]);
		ptr = _stringcharacter(node->s, '=');
		if (!ptr)
			return (0);
		ptr = _strduplicate(ptr + 1);
		if (!ptr)
			return (0);
		inf->argv[0] = ptr;
	}
	return (1);
}
/**
 * variable_replacement - replace vars
 *
 * @inf: information
 *
 * Return: integer
*/
int variable_replacement(info_type *inf)
{
	list_type *node;
	int y = 0;

	for (y = 0; inf->argv[y]; y++)
	{
		if (inf->argv[y][0] != '$' || !inf->argv[y][1])
			continue;
		if (!_strcompare(inf->argv[y], "$?"))
		{
			string_replacement(&(inf->argv[y]),
					_strduplicate(number_converting(inf->status, 10, 0)));
			continue;
		}
		if (!_strcompare(inf->argv[y],  "$$"))
		{
			string_replacement(&(inf->argv[y]),
					_strduplicate(number_converting(getpid(), 10, 0)));
			continue;
		}
		node = node_starts(inf->env, &inf->argv[y][1], '=');
		if (node)
		{
			string_replacement(&(inf->argv[y]),
					_strduplicate(_stringcharacter(node->s, '=') + 1));
			continue;
		}
		string_replacement(&inf->argv[y], _strduplicate(""));
	}
	return (0);
}
/**
 * string_replacement - replace string
 *
 * @first: old
 * @last: new
 *
 * Return: integer
*/
int string_replacement(char **first, char *last)
{
	free(*first);
	*first = last;
	return (1);
}
