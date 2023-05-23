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
			{"push", _push},
			{"pall", _pall},
			{"pint", _pint},
			{"pop", _pop},
			{"swap", _swap},
			{"add", _add},
			{"nop", _nop},
			/*
			// {"sub", _sub},
			// {"div", _div},
			// {"mul", _mul},
			// {"mod", _mod},
			*/
			{"pchar", _pchar},
			{"pstr", _pstr},
			{"rotl", _rotl},
			{"rotr", _rotr},
			{"stack", _stack},
			{"queue", _queue},
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
