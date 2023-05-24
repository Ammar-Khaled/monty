#include "monty.h"

/**
 * _sub - sub two top elements (second top - top) => new top.
 * @stack: the head node.
 * @line_number: line number.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int n1, n2;

	n1 = get_argument(stack, "sub", line_number);
	n2 = get_argument(stack, "sub", line_number);

	*stack = add_dnodeint(stack, n2 - n1);  /*may needn't store return value*/
}

/**
 * _div - divide two top elements (second top / top) => new top.
 * @stack: the head node.
 * @line_number: line number.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int n1, n2;

	n1 = get_argument(stack, "div", line_number);
	if (n1 == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_global_state();
		exit(EXIT_FAILURE);
	}
	n2 = get_argument(stack, "div", line_number);

	*stack = add_dnodeint(stack, n2 / n1);  /*may needn't store return value*/
}
