#include "monty.h"

/**
* i_queue - queue instruction
* @stack: stack
* @line_number: line number
*/
void i_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	is_queue = 1;
}

/**
* i_stack - stack instruction
* @stack: stack
* @line_number: line number
*/
void i_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	is_queue = 0;
}

