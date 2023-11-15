#include "simpleshell.h"

/**
 * forkk - fork thread to exec command
 *
 * @inf: information
 *
 * Return: nothing
*/
void forkk(info_type *inf)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return;
	}
	if (child == 0)
	{
		if (execve(inf->p, inf->argv, getting_environ(inf)) == -1)
		{
			info_freeing(inf, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(inf->status));
		if (WIFEXITED(inf->status))
		{
			inf->status = WEXITSTATUS(inf->status);
			if (inf->status == 126)
				error_printing(inf, "Permission denied\n");
		}
	}
}
/**
 * shell_loop - shell loop
 *
 * @inf: information
 *
 * @argv: argument vector
 *
 * Return: integer
*/
int shell_loop(info_type *inf, char **argv)
{
	int builtin = 0;
	ssize_t i = 0;

	while (i != -1 && builtin != -2)
	{
		info_clearance(inf);
		if (interactive_mode(inf))
			_puts("$ ");
		_errputchar(BUFF_FLUSH);
		i = gettinginput(inf);
		if (i != -1)
		{
			info_setting(inf, argv);
			builtin = builtin_finding(inf);
			if (builtin == -1)
				command_finding(inf);
		}
		else if (interactive_mode(inf))
			_putchar('\n');
		info_freeing(inf, 0);
	}
	writehistory(inf);
	info_freeing(inf, 1);
	if (!interactive_mode(inf) && inf->status)
		exit(inf->status);
	if (builtin == -2)
	{
		if (inf->errn == -1)
			exit(inf->status);
		exit(inf->errn);
	}
	return (builtin);
}
