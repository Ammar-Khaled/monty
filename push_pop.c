#include "monty.h"

/**
 * _push - add element to a stack, queue.
 * @stack: the head node of the stack.
 * @line_number: the number of the line in the monty file.
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int num, i, valid = 1;

	if (global_state.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_global_state();
		exit(EXIT_FAILURE);
	}

	/* assert that `arg` is a valid integer */
	if (global_state.arg[0] != '-' && !isdigit(global_state.arg[0]))
		valid = 0;

	for (i = 1; global_state.arg[i]; i++)
	{
		if (!isdigit(global_state.arg[i]))
		{
			valid = 0;
			break;
		}
	}

	if (!valid)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_global_state();
		exit(EXIT_FAILURE);
	}

	num = atoi(global_state.arg);

	if (global_state.is_lifo == 1)
		add_dnodeint(stack, num);
	else
		add_dnodeint_end(stack, num);
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
