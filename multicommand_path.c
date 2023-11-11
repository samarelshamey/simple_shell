#include "simpleshell.h"

/**
 * check_multicommand - check multicommand
 *
 * @inf: information
 *
 * @buff: buffer
 *
 * @ptr: address
 *
 * @len: length
 *
 * @index: starting pos
 *
 * Return: nothing
*/
void check_multicommand(info_type *inf, char *buff,
		size_t *ptr, size_t index, size_t len)
{
	size_t x = *ptr;

	if (inf->commd_buf_type == AND_COMMD)
	{
		if (inf->status)
		{
			buff[index] = 0;
			x = len;
		}
	}
	if (inf->commd_buf_type == OR_COMMD)
	{
		if (!inf->status)
		{
			buff[index] = 0;
			x = len;
		}
	}
	*ptr = x;
}
/**
 * is_multicommand - check multicommand
 *
 * @inf: information
 *
 * @buff: buffer
 *
 * @ptr: address
 *
 * Return: integer
*/
int is_multicommand(info_type *inf, char *buff, size_t *ptr)
{
	size_t x = *ptr;

	if (buff[x] == '&' && buff[x + 1] == '&')
	{
		buff[x] = 0;
		x++;
		inf->commd_buf_type = AND_COMMD;
	}
	else if (buff[x] == '|' && buff[x + 1] == '|')
	{
		buff[x] = 0;
		x++;
		inf->commd_buf_type = OR_COMMD;
	}
	else if (buff[x] == ';')
	{
		buff[x] = 0;
		inf->commd_buf_type = CHAIN_COMMD;
	}
	else
		return (0);
	*ptr = x;
	return (1);
}
