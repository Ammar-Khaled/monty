#include "monty.h"

/**
 * _pall - print all the element of the stack.
 * @stack: the head node.
 * @line_number: line number.
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	(void) line_number;

	if (!stack)
		return;
	h = *stack;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pint - print the top elemnent in the stack.
 * @stack: the head node of the stack.
 * @line_number: line number.
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
