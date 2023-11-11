#include "simpleshell.h"

/**
 * freepointer - free a pointer
 *
 * @pointer: address of pointer
 *
 * Return: integer
*/

int freepointer(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
/**
 * _memoryset - fill memory
 *
 * @s: pointer
 *
 * @byte: bytes to fill with
 *
 * @num: amount of bytes
 *
 * Return: pointer
*/
char *_memoryset(char *s, char byte, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		s[i] = byte;
	return (s);
}

/**
 * _realloc - reallocates memory
 *
 * @pointer: pointer
 *
 * @oldsize: old size
 *
 * @newsize: new size
 *
 * Return: pointer
*/

void *_realloc(void *pointer, unsigned int oldsize, unsigned int newsize)
{
	char *p;

	if (!pointer)
		return (malloc(newsize));
	if (!newsize)
		return (free(pointer), NULL);
	if (newsize == oldsize)
		return (pointer);
	p = malloc(newsize);
	if (!p)
		return (NULL);
	oldsize = oldsize < newsize ? oldsize : newsize;
	while (oldsize--)
		p[oldsize] = ((char *)pointer)[oldsize];
	free(pointer);
	return (p);
}
/**
 * freestring - free string
 *
 * @p: string of strings
 *
 * Return: nothing
*/
void freestring(char **p)
{
	char **s = p;

	if (!p)
		return;
	while (*p)
		free(*p++);
	free(s);
}
