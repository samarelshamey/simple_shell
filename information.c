#include "simpleshell.h"

/**
 * info_setting - struct initializer
 *
 * @inform: information
 *
 * @argv: argument vector
 *
 * Return: nothing
*/
void info_setting(info_type *inform, char **argv)
{
	int y = 0;

	inform->fname = argv[0];
	if (inform->argument)
	{
		inform->argv = stringtow(inform->argument, " \t");
		if (!inform->argv)
		{
			inform->argv = malloc(sizeof(char *) * 2);
			if (inform->argv)
			{
				inform->argv[0] = _strduplicate(inform->argument);
				inform->argv[1] = NULL;
			}
		}
		for (y = 0; inform->argv && inform->argv[y]; y++)
			;
		inform->argc = y;

		alias_replacement(inform);
		variable_replacement(inform);
	}
}
/**
 * info_clearance - clear information
 *
 * @inf: information
 *
 * Return: nothing
*/
void info_clearance(info_type *inf)
{
	inf->argument = NULL;
	inf->argv = NULL;
	inf->argc = 0;
	inf->p = NULL;
}

/**
 * info_freeing - free information
 *
 * @inf: information
 *
 * @total: all info
*/
void info_freeing(info_type *inf, int total)
{
	freestring(inf->argv);
	inf->argv = NULL;
	inf->p = NULL;
	if (total)
	{
		if (inf->env)
			freeing_list(&(inf->env));
		if (inf->alias)
			freeing_list(&(inf->alias));
		if (!inf->commd_buff)
			free(inf->argument);
		if (inf->history)
			freeing_list(&(inf->history));
		freepointer((void **)inf->commd_buff);
		freestring(inf->environ);
		inf->environ = NULL;
		if (inf->readfd > 2)
			close(inf->readfd);
		_putchar(BUFF_FLUSH);
	}
}
