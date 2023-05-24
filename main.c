#include "monty.h"

global_t global_state;  /* Defining global var */

/**
 * initialise_global_state - initialises global state
 * @f: input file
 */
void initialise_global_state(FILE *f)
{
	global_state.is_lifo = 1;
	global_state.line_number = 1;
	global_state.arg = NULL;
	global_state.buffer = malloc(1024);
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
	char *opcode, *line_read;
	void (*opcode_function)(stack_t **stack, unsigned int line_number);

	check_argc(argc);
	file = fopen(argv[1], "r");
	check_file(file, argv[1]);
	initialise_global_state(file);
	if (global_state.buffer == NULL)
		printf("Error: malloc failed\n"), exit(EXIT_FAILURE);
	line_read = fgets(global_state.buffer, 1024, file);
	while (line_read)
	{
		opcode = strtok(global_state.buffer, SPACE_DELIMS);
		if (opcode && opcode[0] != '#')
		{
			opcode_function = get_opc_func(opcode);
			if (!opcode_function)
			{
				fprintf(stderr, "L%i:", global_state.line_number);
				fprintf(stderr, "unknown instruction %s\n", opcode);
				free_global_state();
				exit(EXIT_FAILURE);
			}
			global_state.arg = strtok(NULL, SPACE_DELIMS);
			opcode_function(&global_state.head, global_state.line_number);
		}
		global_state.line_number++;
		line_read = fgets(global_state.buffer, 1024, file);
	}
	free_global_state();
	return (0);
}
