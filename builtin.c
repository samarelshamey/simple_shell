#include "simpleshell.h"

/**
 * exitfunc - exit the shell
 * @inf: information
 *
 * Return: integer
*/
int exitfunc(info_type *inf)
{
	int exit;

	if (inf->argv[1])
	{
		exit = _erroratoi(inf->argv[1]);
		if (exit == -1)
		{
			inf->status = 2;
			error_printing(inf, "Illegal number: ");
			_errputs(inf->argv[1]);
			_errputchar('\n');
			return (1);
		}
		inf->errn = _erroratoi(inf->argv[1]);
		return (-2);
	}
	inf->errn = -1;
	return (-2);
}
/**
 * shell_history - show history list
 *
 * @inf: information
 *
 * Return: integer
*/
int shell_history(info_type *inf)
{
	list_printing(inf->history);
	return (0);
}
/**
 * change_directory - change current directory
 *
 * @inf: information
 *
 * Return: integer
*/
int change_directory(info_type *inf)
{
	int cd;
	char *s, *direct, buff[1024];

	s = getcwd(buff, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inf->argv[1])
	{
		direct = getting_environ_value(inf, "HOME=");
		if (!direct)
			cd = chdir((direct = getting_environ_value(inf, "PWD=")) ? direct : "/");
		else
			cd = chdir(direct);
	}
	else if (_strcompare(inf->argv[1], "-") == 0)
	{
		if (!getting_environ_value(inf, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(getting_environ_value(inf, "OLDPWD=")), _putchar('\n');
		cd = chdir((direct = getting_environ_value(inf, "OLDPWD=")) ? direct : "/");
	}
	else
		cd = chdir(inf->argv[1]);
	if (cd == -1)
	{
		error_printing(inf, "can't cd to ");
		_errputs(inf->argv[1]), _errputchar('\n');
	}
	else
	{
		setting_environ(inf, "OLDPWD", getting_environ_value(inf, "PWD="));
		setting_environ(inf, "PWD", getcwd(buff, 1024));
	}
	return (0);
}
