#include "monty.h"

/**
 * _push - add element to a stack, queue.
 * @stack: the head node of the stack.
 * @line_number: the number of the line in the monty file.
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (global_state.arg == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (global_state.is_lifo == 1)
		*stack = add_dnodeint(stack, atoi(global_state.arg));
	else if (global_state.is_lifo == 0)
		node = add_dnodeint_end(stack, atoi(global_state.arg));

	if (node == NULL || *stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * _pop - remove an element from a stack, queue.
 * @stack: the head node of the stack.
 * @line_number: the number of the line in the monty file.
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *flag;

	node = pop_s(stack);

	if (global_state.is_lifo == 1)
		flag = "stack";
	else
		flag = "queue";

	if (node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty %s\n", line_number, flag);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	free(node);
}
