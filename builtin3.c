#include "simpleshell.h"

/**
 * alias_setting - set alias
 *
 * @inf: iformation
 *
 * @s: string
 *
 * Return: integer
*/
int alias_setting(info_type *inf, char *s)
{
	char *ptr;

	ptr = _stringcharacter(s, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (alias_unsetting(inf, s));
	alias_unsetting(inf, s);
	return (node_at_end(&(inf->alias), s, 0) == NULL);
}

/**
 * alias_unsetting - unset alias
 *
 * @inf: information
 *
 * @s: string
 *
 * Return: integer
*/
int alias_unsetting(info_type *inf, char *s)
{
	int i;
	char *ptr, ch;

	ptr = _stringcharacter(s, '=');
	if (!ptr)
		return (1);
	ch = *ptr;
	*ptr = 0;
	i = node_deletion(&(inf->alias),
			indexNode(inf->alias, node_starts(inf->alias, s, -1)));
	*ptr = ch;
	return (i);
}
