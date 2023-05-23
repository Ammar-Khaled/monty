#include "monty.h"

/**
 * _swap - swap two element.
 * @stack: the head node.
 * @line_number: line number.
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	int n_copy;
	char *flag;

	if (global_state.is_lifo == 1)
		flag = "stack";
	else
		flag = "queue";

	if (!stack || !(*stack))
	{
		printf("L%d: can't swap, %s too short\n", line_number, flag);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	n_copy = (*stack)->n;

	if ((*stack)->next == NULL)
	{
		printf("L%d: can't swap, %s too short\n", line_number, flag);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = n_copy;
}

/**
 * _add - add two consecutive element.
 * @stack: the head node.
 * @line_number: line number.
*/
void _add(stack_t **stack, unsigned int line_number)
{
	int n1, n2;

	n1 = get_argument(stack, "add", line_number);
	n2 = get_argument(stack, "add", line_number);

	add_node(stack, n1 + n2);
}
