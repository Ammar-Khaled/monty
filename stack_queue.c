#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO).
 * @stack: head of the doubly-linked list
 * @line_number: current line number
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	global_state.is_lifo = 1;
	/* unused parameters */
	(void)stack;
	(void)line_number;
}

/**
 * _queue - sets the format of the data to a queue (FIFO).
 * @stack: head of the doubly-linked list
 * @line_number: current line number
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	global_state.is_lifo = 0;
	/* unused parameters */
	(void)stack;
	(void)line_number;
}
