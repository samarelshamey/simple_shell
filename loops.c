#include "simpleshell.h"

/**
 * builtin_finding - find builin command
 *
 * @inf: information
 *
 * Return: integer
*/
int builtin_finding(info_type *inf)
{
	builtin_struct builtins[] = {
		{"alias", aliasfunc},
		{"exit", exitfunc},
		{"cd", change_directory},
		{"env", environ},
		{"setenv", mysetting_environ},
		{"unsetenv", myunsetting_environ},
		{"help", helpfunc},
		{"history", shell_history},
		{NULL, NULL}
	};
	int y, builtin = -1;

	for (y = 0; builtins[y].t; y++)
		if (_strcompare(inf->argv[0], builtins[y].t) == 0)
		{
			inf->err_count++;
			builtin = builtins[y].f(inf);
			break;
		}
	return (builtin);
}

/**
 * command_finding - find command
 *
 * @inf: information
 *
 * Return: nothing
*/
void command_finding(info_type *inf)
{
	int y, j;
	char *p = NULL;

	inf->p = inf->argv[0];
	if (inf->linecount_f == 1)
	{
		inf->err_count++;
		inf->linecount_f = 0;
	}
	for (y = 0, j = 0; inf->argument[y]; y++)
		if (!is_delimeter(inf->argument[y], " \t\n"))
			j++;
	if (!j)
		return;
	p = path_finding(inf, getting_environ_value(inf, "PATH+"), inf->argv[0]);
	if (p)
	{
		inf->p = p;
		forkk(inf);
	}
	else
	{
		if ((interactive_mode(inf) || getting_environ_value(inf, "PATH=")
					|| inf->argv[0][0] == '/') && is_commd(inf, inf->argv[0]))
			forkk(inf);
		else if (*(inf->argument) != '\n')
		{
			inf->status = 127;
			error_printing(inf, "command not found\n");
		}
	}
}
