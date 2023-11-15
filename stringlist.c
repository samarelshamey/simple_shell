#include "simpleshell.h"

/**
 * node_addition - add node
 *
 * @h: head
 *
 * @s: string
 *
 * @n: index
 *
 * Return: list size
*/

list_type *node_addition(list_type **h, const char *s, int n)
{
	list_type *new;

	if (!h)
		return (NULL);
	new = malloc(sizeof(list_type));
	if (!new)
		return (NULL);
	_memoryset((void *)new, 0, sizeof(list_type));
	new->n = n;
	if (s)
	{
		new->s = _strduplicate(s);
		if (!new->s)
		{
			free(new);
			return (NULL);
		}
	}
	new->next = *h;
	*h = new;
	return (new);
}

/**
 * list_length - list length
 *
 * @head: head
 *
 * Return: list size
*/

size_t list_length(const list_type *head)
{
	size_t index = 0;

	while (head)
	{
		head = head->next;
		index++;
	}
	return (index);
}

/**
 * list_printing - print list
 *
 * @head: head
 *
 * Return: list size
*/
size_t list_printing(const list_type *head)
{
	size_t index = 0;

	while (head)
	{
		_puts(number_converting(head->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->s ? head->s : "(nil)");
		_puts("\n");
		head = head->next;
		index++;
	}
	return (index);
}

/**
 * indexNode - get index of node
 *
 * @h: head
 *
 * @n: node
 *
 * Return: node index
*/
ssize_t indexNode(list_type *h, list_type *n)
{
	size_t index = 0;

	while (h)
	{
		if (h == n)
			return (index);
		h = h->next;
		index++;
	}
	return (-1);
}
/**
 * freeing_list - free all nodes
 *
 * @ptr: head pointer
 *
 * Return: nothing
*/
void freeing_list(list_type **ptr)
{
	list_type *nod, *nextn, *h;

	if (!ptr || !*ptr)
		return;
	h = *ptr;
	nod = h;
	while (nod)
	{
		nextn = nod->next;
		free(nod->s);
		free(nod);
		nod = nextn;
	}
	*ptr = NULL;
}
