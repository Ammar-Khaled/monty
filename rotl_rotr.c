#include "monty.h"

/**
 * _rotl - rotates the stack to the top.
 * @stack: head of the doubly-linked list
 * @line_number: current line number
 *
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	(void)line_number;

	if (!stack || !*stack)
		return;

	if (!(*stack)->next)
		return;

	top = pop_s(stack);
	add_dnodeint_end(stack, top->n);

	free(top);
}

/**
 * _rotr - rotates the stack to the bottom.
 * @stack: head of the doubly-linked list
 * @line_number: current line number
 *
 * Description:The last element of the stack becomes the top element of it
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *pre_tail;

	(void)line_number;

	tail = pre_tail = *stack;

	if (tail->next)
		tail = tail->next;

	while (tail->next)
	{
		tail = tail->next;
		pre_tail = pre_tail->next;
	}

	add_dnodeint(stack, tail->n);
	
	free(tail);
	pre_tail->next = NULL;
}
