#include "monty.h"

int is_queue = 0;


/**
* main - main function
* @argc: argc
* @argv: argv
* Return: EXIT_FAILURE or 0
*/
int main(int argc, char **argv)
{
	char *line = NULL;
	FILE *file_ptr = NULL;
	stack_t *stack = NULL;
	instruction_t instructions[NUMBER_OF_INSTRUCTIONS];
	int line_number = 1;
	size_t buffer_size = 0;
	ssize_t line_size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	if (!file_ptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[0]);
		fclose(file_ptr);
		return (EXIT_FAILURE);
	}
	init_instructions(instructions);
	while (1)
	{
		line_size = getline(&line, &buffer_size, file_ptr);
		if (line_size == -1)
			break;

		exit_failure(NULL, NULL, line, instructions, file_ptr);
		exec_opcode_func(&stack, line, line_number, instructions);

		free(line);
		line = NULL;
		++line_number;
	}
	free_stack(stack);
	free_instructions(instructions);
	free(line);
	fclose(file_ptr);
	return (0);
}

