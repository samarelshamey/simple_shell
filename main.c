#include "simpleshell.h"

/**
 * main - entry point
 *
 * @argc: argument count
 *
 * @argv: argument vector
 *
 * Return:  integer
*/
int main(int argc, char **argv)
{
	int fd = 2;
	info_type inf[] = {INFO_INITIATE};

	asm("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_errputs(argv[0]);
				_errputs(": 0: Can't open file ");
				_errputs(argv[1]);
				_errputchar('\n');
				_errputchar(BUFF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inf->readfd = fd;
	}
	environ_list_occupy(inf);
	readhistory(inf);
	shell_loop(inf, argv);
	return (EXIT_SUCCESS);
}
