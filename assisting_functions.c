#include "monty.h"

/**
 * pop_s - return the node at the beginning.
 * @head: pointer to the head.
 * Return: pointer to the node or NULL.
 */
stack_t *pop_s(stack_t **head)
{
	stack_t *tmp;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;

	return (tmp); /*remember to free it*/
}

/**
 * get_argument - return the arguments for calulations.
 * @stack: the head of the node..
 * @opcode: opcode string.
 * @line_number: line number.
 * Return: the argument.
 */
int get_argument(stack_t **stack, char *opcode, unsigned int line_number)
{
	stack_t *node;
	int tmp;

	node = pop_s(stack);

	if (node == NULL)
	{
		printf("L%d: can't %s, stack too short\n", line_number, opcode);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = node->n;
	free(node);
	return (tmp);
}
/**
 * check_argc - Function to check whether correct.
 * @argc: argument count.
 */

void check_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * check_file - check if the file is opened.
 * @file: the given file.
 * @argv: the argument to be checked.
*/
void check_file(FILE *file, char *argv)
{
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
