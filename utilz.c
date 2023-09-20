#include "monty.h"

/**
* exit_failure - exit the program with EXIT_FAILURE stat
* @err_msg: the error msg (if NULL won't exit the program)
* @stack: stack
* @line: line
* @instructions: instructions
* @file: file
*/
void exit_failure(char *err_msg, stack_t *stack, char *line,
		instruction_t *instructions, FILE *file)
{
	static instruction_t *inst_ptr;
	static char *line_p;
	static FILE *file_p;

	if (line)
		line_p = line;
	if (instructions)
		inst_ptr = instructions;
	if (file)
		file_p = file;

	if (err_msg)
	{
		fprintf(stderr, "%s", err_msg);
		free_stack(stack);
		free_instructions(inst_ptr);
		free(err_msg);
		free(line_p);
		fclose(file_p);
		exit(EXIT_FAILURE);
	}
}

/**
* init_instructions - init the instructions array
* @instructions: instructions
*/
void init_instructions(instruction_t *instructions)
{
	instructions[0].opcode = strdup("pall");
	instructions[0].f = i_pall;
	instructions[1].opcode = strdup("pint");
	instructions[1].f = i_pint;
	instructions[2].opcode = strdup("pop");
	instructions[2].f = i_pop;
	instructions[3].opcode = strdup("swap");
	instructions[3].f = i_swap;
	instructions[4].opcode = strdup("add");
	instructions[4].f = i_add;
	instructions[5].opcode = strdup("nop");
	instructions[5].f = i_nop;
}

/**
* exec_opcode_func - execute the opcode corresponding function
* @stack: stack
* @line: line
* @line_number: line number
* @instructions: instructions
*/
void exec_opcode_func(stack_t **stack, char *line, unsigned int line_number,
						instruction_t *instructions)
{
	char *opcode = NULL, *err_msg = NULL;
	int i = 0, j = 0;

	if (!line || !instructions)
		return;
	while (*line == ' ')
		++line;
	if (*line == '#' || *line == '\n' || !*line)
		return;

	while (line[i] && line[i] != ' ' && line[i] != '\n')
		++i;
	opcode = malloc(sizeof(char) * (i + 1));
	if (!opcode)
		exit_failure(strdup("Error: malloc failed\n"), *stack, NULL, NULL, NULL);
	opcode[i] = '\0';
	for (j = 0; j < i; ++j)
		opcode[j] = line[j];

	if (!strcmp("push", opcode))
	{
		free(opcode);
		i_push(&(line[i]), stack, line_number);
		return;
	}

	for (j = 0; j < NUMBER_OF_INSTRUCTIONS; ++j)
		if (!strcmp(instructions[j].opcode, opcode))
		{
			free(opcode);
			(*(instructions[j].f))(stack, line_number);
			return;
		}
	err_msg = strdup("L");
	concat_int(&err_msg, line_number);
	_strcat(&err_msg, ": unknown instruction ");
	_strcat(&err_msg, opcode);
	_strcat(&err_msg, "\n");
	free(opcode);
	exit_failure(err_msg, *stack, NULL, NULL, NULL);
}

/**
* free_instructions - free instructions array contents
* @instructions: the instructions array
*/
void free_instructions(instruction_t *instructions)
{
	int i = 0;

	for (i = 0; i < NUMBER_OF_INSTRUCTIONS; ++i)
		free(instructions[i].opcode);
}

/**
* free_stack - free a linked list stack_t
* @stack: the head of the linked list (stack)
*/
void free_stack(stack_t *stack)
{
	stack_t *iter = NULL;

	if (!stack)
		return;
	iter = stack->next;
	free(stack);
	while (iter)
	{
		stack = iter;
		iter = stack->next;
		free(stack);
	}
}

