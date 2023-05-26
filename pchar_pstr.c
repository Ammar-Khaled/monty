#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: head of the doubly-linked list
 * @line_number: current line number
 *
 * Description: The integer stored at the top of the stack
 * is treated as the ascii value of the character to be printed
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int top;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = (*stack)->n;
	if (top < 1 || top > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top);
}

/**
 * _pstr - prints the string starting at the top of the stack.
 * @stack: head of the doubly-linked list
 * @line_number: current line number
 *
 * Description:The integer stored in each element of the stack
 * is treated as the ascii value of the character to be printed
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	(void)line_number;
	cur = *stack;
	while (cur)
	{
		if (cur->n < 1 || cur->n > 255)
			break;
		printf("%c", cur->n);
		cur = cur->next;
	}
	printf("\n");
}
