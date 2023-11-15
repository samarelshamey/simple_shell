#include "simpleshell.h"

/**
 * environment - print current environment
 *
 * @inf: information
 *
 * Return: integer
*/
int environment(info_type *inf)
{
	list_printing_string(inf->env);
	return (0);
}

/**
 * setting_environ - set environment
 *
 * @inf: information
 *
 * @v: env variable
 *
 * @val: value
 *
 * Return: integer
*/
int setting_environ(info_type *inf, char *v, char *val)
{
	char *buffer = NULL;
	list_type *node;
	char *ptr;

	if (!v || !val)
		return (0);
	buffer = malloc(_strlength(v) + _strlength(val) + 2);
	if (!buffer)
		return (1);
	_strcopy(buffer, v);
	_strconcat(buffer, "=");
	_strconcat(buffer, val);
	node = inf->env;
	while (node)
	{
		ptr = startwith(node->s, v);
		if (ptr && *ptr == '=')
		{
			free(node->s);
			node->s = buffer;
			inf->changed_env = 1;
			return (0);
		}
		node = node->next;
	}
	node_at_end(&(inf->env), buffer, 0);
	free(buffer);
	inf->changed_env = 1;
	return (0);
}
/**
 * unsetting_environ - unset environment
 *
 * @inf: information
 *
 * @v: variable
 *
 * Return: integer
*/
int unsetting_environ(info_type *inf, char *v)
{
	list_type *node = inf->env;
	size_t y = 0;
	char *ptr;

	if (!node || !v)
		return (0);
	while (node)
	{
		ptr = startwith(node->s, v);
		if (ptr && *ptr == '=')
		{
			inf->changed_env = node_deletion(&(inf->env), y);
			y = 0;
			node = inf->env;
			continue;
		}
		node = node->next;
		y++;
	}
	return (inf->changed_env);
}
/**
 * mysetting_environ - initiate new environ
 *
 * @inf: information
 *
 * Return: integer
*/
int mysetting_environ(info_type *inf)
{
	if (inf->argc != 3)
	{
		_errputs("Invalid number of arguements\n");
		return (1);
	}
	if (setting_environ(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}
/**
 * myunsetting_environ - remove environ
 *
 * @inf: information
 *
 * Return: integer
*/
int myunsetting_environ(info_type *inf)
{
	int y;

	if (inf->argc == 1)
	{
		_errputs("Too few arguments.\n");
		return (1);
	}
	for (y = 0; y <= inf->argc; y++)
		unsetting_environ(inf, inf->argv[y]);
	return (0);
}
