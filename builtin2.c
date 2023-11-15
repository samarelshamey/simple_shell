#include "simpleshell.h"
/**
 * helpfunc - cd of the process
 *
 * @inf: information
 *
 * Return: integer
*/
int helpfunc(info_type *inf)
{
	char **arr;

	arr = inf->argv;
	_puts("help call works. Function not yet implemented\n");
	if (0)
		_puts(*arr);
	return (0);
}
/**
 * aliasfunc - alias function
 *
 * @inf: information
 *
 * Return: integer
*/
int aliasfunc(info_type *inf)
{
	list_type *node = NULL;
	int y = 0;
	char *ptr = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			alias_printing(node);
			node = node->next;
		}
		return (0);
	}
	for (y = 0; inf->argv[y]; y++)
	{
		ptr = _stringcharacter(inf->argv[y], '=');
		if (ptr)
			alias_setting(inf, inf->argv[y]);
		else
			alias_printing(node_starts(inf->alias, inf->argv[y], '='));
	}
	return (0);
}
/**
 * alias_printing - print alias string
 *
 * @n: node
 *
 * Return: integer
*/
int alias_printing(list_type *n)
{
	char *ptr = NULL, *y = NULL;

	if (n)
	{
		ptr = _stringcharacter(n->s, '=');
		for (y = n->s; y <= ptr; y++)
			_putchar(*y);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
