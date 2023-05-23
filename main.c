#include "monty.h"

/**
 * initialise_global_state - initialises global state
 * @f: input file
 */
void initialise_global_state(FILE *f)
{
	global_state.is_lifo = 1;
	global_state.line_number = 1;
	global_state.arg = NULL;
	global_state.buffer = NULL;
	global_state.file = f;
	global_state.head = NULL;
}

/**
 * free_global_state - free the global state attributes
 */
void free_global_state(void)
{
	free(global_state.arg);
	free(global_state.buffer);
	fclose(global_state.file);
	free_dlistint(global_state.head);
}

/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 if Success, EXIT_FAILURE otherwise
*/
int main(int argc, char *argv[])
{
	FILE *file;
	size_t n_read, buf_size = 256;
	char *opcode;
	void (*opcode_function)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	initialise_global_state(file);
	n_read = getline(&global_state.buffer, &buf_size, file);
	while (n_read == -1)
	{
		opcode = strtok(global_state.buffer, SPACE_DELIMS);
		if (opcode && opcode[0] != '#')
		{
			opcode_function = get_opc_func(opcode);
			if (!opcode_function)
			{
				dprintf(2, "L%i:", global_state.line_number);
				dprintf(2, "unknown instruction %s\n", opcode);
				free_global_state();
				exit(EXIT_FAILURE);
			}
			global_state.arg = strtok(NULL, SPACE_DELIMS);
			opcode_function(&global_state.head, global_state.line_number);
		}
		global_state.line_number++;
		n_read = getline(&global_state.buffer, &buf_size, file);
	}
	free_global_state();
	return (0);
}
