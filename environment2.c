#include "simpleshell.h"

/**
 * getting_environ - get environment
 *
 * @inf: information
 *
 * Return: char
*/
char **getting_environ(info_type *inf)
{
	if (!inf->environ || inf->changed_env)
	{
		inf->environ = string_list(inf->env);
		inf->changed_env = 0;
	}
	return (inf->environ);
}
/**
 * getting_environ_value - getting value of environ var
 *
 * @inf: information
 *
 * @n: name
 *
 * Return: char
*/
char *getting_environ_value(info_type *inf, const char *n)
{
	list_type *node = inf->env;
	char *ptr;

	while (node)
	{
		ptr = startwith(node->s, n);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * environ_list_occupy - occuping linked list
 *
 * @inf: information
 *
 * Return: integer
*/
int environ_list_occupy(info_type *inf)
{
	list_type *node = NULL;
	size_t y;

	for (y = 0; environ[y]; y++)
		node_at_end(&node, environ[y], 0);
	inf->env = node;
	return (0);
}

