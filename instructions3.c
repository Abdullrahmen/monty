#include "monty.h"


/**
* i_pchar - pchar instruction
* @stack: stack
* @line_number: line number
*/
void i_pchar(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *iter = NULL;

	if (!*stack)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't pchar, stack empty\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	if (iter->n < 0 || iter->n > 127)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't pchar, value out of range\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	printf("%c\n", iter->n);
}

/**
* i_pstr - pstr instruction
* @stack: stack
* @line_number: line number
*/
void i_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *iter = NULL;

	(void)line_number;
	if (!*stack)
	{
		printf("\n");
		return;
	}
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	while (iter)
	{
		if (iter->n <= 0 || iter->n > 127)
			break;
		printf("%c", iter->n);
		iter = iter->prev;
	}
	printf("\n");
}

/**
* i_rotl - rotl instruction
* @stack: stack
* @line_number: line number
*/
void i_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = NULL;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;

	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/**
* i_rotr - rotr instruction
* @stack: stack
* @line_number: line number
*/
void i_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *old_head = NULL, *last = NULL;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;

	old_head = *stack;
	*stack = old_head->next;
	(*stack)->prev = NULL;

	last = *stack;
	while (last->next)
		last = last->next;

	last->next = old_head;
	old_head->prev = last;
	old_head->next = NULL;
}

