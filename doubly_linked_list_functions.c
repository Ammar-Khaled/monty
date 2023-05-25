#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: pointer to the pointer to the list
 * @n: number to be added
 *
 * Return: the head of the new list, or exit with failure
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tail, *new;

	if (!head)
		return (NULL);

	new = (stack_t *)malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global_state();
		exit(EXIT_FAILURE);
	}

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

	return (*head);
}

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: head of list
 * @n: number to be added
 * Return: the head of the new list, or exit with failure
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global_state();
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;


	if (!(*head))	 /*this is the first node*/
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}

	return (*head);
}

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the list
 */
void free_dlistint(stack_t *head)
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
