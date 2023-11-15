#include "simpleshell.h"

/**
 * node_at_end - add node to the end
 *
 * @h: head
 *
 * @s: string
 *
 * @index: node index
 *
 * Return: list size
*/
list_type *node_at_end(list_type **h, const char *s, int index)
{
	list_type *new, *node;

	if (!h)
		return (NULL);
	node = *h;
	new = malloc(sizeof(list_type));
	if (!new)
		return (NULL);
	_memoryset((void *)new, 0, sizeof(list_type));
	new->n = index;
	if (s)
	{
		new->s = _strduplicate(s);
		if (!new->s)
		{
			free(new);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*h = new;
	return (new);
}

/**
 * string_list - list strings
 *
 * @h: head
 *
 * Return: strings
*/

char **string_list(list_type *h)
{
	list_type *n = h;
	size_t len = list_length(h), j;
	char **str;
	char *s;

	if (!h || !len)
		return (NULL);
	str = malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	for (len = 0; n; n = n->next, len++)
	{
		s = malloc(_strlength(n->s) + 1);
		if (!s)
		{
			for (j = 0; j < len; j++)
				free(str[j]);
			free(str);
			return (NULL);
		}
		s = _strcopy(s, n->s);
		str[len] = s;
	}
	str[len] = NULL;
	return (str);
}

/**
 * node_starts - check node that start with
 *
 * @n: node
 *
 * @p: prefix
 *
 * @ch: character
 *
 * Return: node
*/
list_type *node_starts(list_type *n, char *p, char ch)
{
	char *ptr = NULL;

	while (n)
	{
		ptr = startwith(n->s, p);
		if (ptr && ((ch == -1) || (*ptr == ch)))
			return (n);
		n = n->next;
	}
	return (NULL);
}

/**
 * node_deletion - delete node at specific index
 *
 * @h: head
 *
 * @i: index
 *
 * Return: integer
*/
int node_deletion(list_type **h, unsigned int i)
{
	list_type *n, *prev;
	unsigned int j = 0;

	if (!h || !*h)
		return (0);
	if (!i)
	{
		n = *h;
		*h = (*h)->next;
		free(n->s);
		free(n);
		return (1);
	}
	n = *h;
	while (n)
	{
		if (j == i)
		{
			prev->next = n->next;
			free(n->s);
			free(n);
			return (1);
		}
		j++;
		prev = n;
		n = n->next;
	}
	return (0);
}
/**
 * list_printing_string - print the strings element
 *
 * @head: head
 *
 * Return: size
*/
size_t list_printing_string(const list_type *head)
{
	size_t ind = 0;

	while (head)
	{
		_puts(head->s ? head->s : "(nil)");
		_puts("\n");
		head = head->next;
		ind++;
	}
	return (ind)
}
