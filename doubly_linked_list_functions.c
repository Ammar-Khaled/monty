#include "monty.h"

/**
 * print_dlistint - prints all the elements of a
 * dlistint_t list
 *
 * @h: head of the list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t count = 0;

	while (current)
	{
		printf("%i\n", current->n);
		count++;
		current = current->next;
	}

	return (count);
}

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: pointer to the pointer to the list
 * @n: number to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tail;
	/* Create a new node */
	dlistint_t *new = (dlistint_t *)malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);

	new->next = NULL; /* as it will be at the end */
	new->n = n;

	if (!(*head)) /* if the new node is the first node */
	{
		*head = new;
		new->prev = NULL;
	}
	else /* Traverse the linked list until reaching the end */
	{
		tail = *head;
		while (tail->next)
			tail = tail->next;
		/* now tail points to the last node */
		new->prev = tail;
		tail->next = new;
	}

	return (new);
}


/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: head of list
 * @n: number to be added
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));
	dlistint_t *h;

	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	h = *head;

	if (h)
	{
		while (h->prev)
			h = h->prev;
	}

	new->next = h;

	if (h)
	{
		h->prev = new;
	}

	*head = new;

	return (new);
}

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the list
 */
void free_dlistint(dlistint_t *head)
{
	if (head)
	{
		while (head->next)
		{
			head = head->next;
			free(head->prev);
		}
		free(head);
	}
}
