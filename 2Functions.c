#include "simpleshell.h"

/**
 * _atoi - convert string to integer
 *
 * @string: string
 *
 * Return: integer
*/
int _atoi(char *string)
{
	int g, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (g = 0; string[g] != '\0' && flag != 2; g++)
	{
		if (string[g] == '-')
			sign *= -1;
		if (string[g] >= '0' && string[g] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (string[g] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -res;
	else
		output = res;
	return (output);
}
/**
 * comment_remove - replace '#' with '\0'
 *
 * @buffer: string to modify
 *
 * Return: void
*/

void comment_remove(char *buffer)
{
	int g;

	for (g = 0; buffer[g] != '\0'; g++)
		if (buffer[g] == '#' && (!g || buffer[g - 1] == ' '))
		{
			buffer[g] = '\0';
			break;
		}
}
/**
 * decimal_printing - print decimal
 *
 * @input: input
 *
 * @fd: field descriptor
 *
 * Return: integer
*/
int decimal_printing(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int g, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _errputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (g = 1000000000; g > 1; g /= 10)
	{
		if (_abs_ / g)
		{
			__putchar('0' + current / g);
			count++;
		}
		current %= g;
	}
	__putchar('0' + current);
	count++;
	return (count);
}
/**
 * number_converting - converter
 *
 * @n: number
 *
 * @b: base
 *
 * @f: flag
 *
 * Return: string
*/
char *number_converting(long int n, int b, int f)
{
	static char *arr;
	static char buff[50];
	char sign = 0;
	char *p;
	unsigned long num = n;

	if (!(f & UNSIGNED_CONVERT) && n < 0)
	{
		num = -n;
		sign = '-';
	}
	arr = f && LOWERCASE_CONVERT ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';
	do {
		*--p = arr[num % b];
		num /= b;
	} while (num != 0);
	if (sign)
		*--p = sign;
	return (p);
}
