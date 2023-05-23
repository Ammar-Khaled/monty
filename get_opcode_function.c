#include "monty.h"

/**
 * get_opc_func - get the function corresponding to the given opcode
 * @opcode: given opcode
 * Return: function pointer to the desired function
*/
void (*get_opc_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instruction[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
			{"div", div},
			{"mul", mul},
			{"mod", mod},
			{"pchar", pchar},
			{"pstr", pstr},
			{"rotl", rotl},
			{"rotr", rotr},
			{"stack", stack},
			{"queue", queue},
			{NULL, NULL}
		};

	for (i = 0; i < 17; i++)
	{
		if (strcmp(instruction[i].opcode, opcode) == 0)
		{
			break;
		}
	}

	return (instruction[i].f);
}
