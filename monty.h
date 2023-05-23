#ifndef _MONTY_H_
#define _MONTY_H_

#define SPACE_DELIMS " \t\n"

/* standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global structure of some information
 * to keep track the state of the data structure
 * @is_lifo: 1 if stack, 0 if queue
 * @buffer: buffer to hold the input line
 * @line_number: the current line number
 * @arg: the argument of the opcode
 * @head: the head of the doubly-linked list
 * @file: file pointer to the input file
*/
typedef struct global_s
{
	int is_lifo;
	char *buffer;
	int line_number;
	char *arg;
	stack_t *head;
	FILE *file;
} global_t;

extern global_t global_state;

void(*get_opc_func(char *opcode))(stack_t **stack, unsigned int line_number);

/* assisting_functions */
stack_t *pop_s(stack_t **stack);
int get_argument(stack_t **stack, char *opcode, unsigned int line_number);

/* opcode functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
/*
// void _sub(stack_t **stack, unsigned int line_number);
// void _div(stack_t **stack, unsigned int line_number);
// void _mul(stack_t **stack, unsigned int line_number);
// void _mod(stack_t **stack, unsigned int line_number);
*/
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);

/* doubly linked list functions */

size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

#endif
