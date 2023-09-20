#include "monty.h"

/**
* i_nop - nop instruction
* @stack: stack
* @line_number: line number
*/
void i_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
* i_sub - sub instruction
* @stack: stack
* @line_number: line number
*/
void i_sub(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *tmp = NULL;

	if (!*stack || !(*stack)->next)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't sub, stack too short\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->n = tmp->n - tmp->next->n;
	free(tmp->next);
	tmp->next = NULL;
}

/**
* i_div - div instruction
* @stack: stack
* @line_number: line number
*/
void i_div(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *tmp = NULL;

	if (!*stack || !(*stack)->next)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't div, stack too short\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	if (tmp->next->n == 0)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": division by zero\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	
	}
	tmp->n = tmp->n / tmp->next->n;
	free(tmp->next);
	tmp->next = NULL;
}


/**
* i_mul - mul instruction
* @stack: stack
* @line_number: line number
*/
void i_mul(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *tmp = NULL;

	if (!*stack || !(*stack)->next)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't mul, stack too short\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->n = tmp->n * tmp->next->n;
	free(tmp->next);
	tmp->next = NULL;
}


/**
* i_mod - mod instruction
* @stack: stack
* @line_number: line number
*/
void i_mod(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *tmp = NULL;

	if (!*stack || !(*stack)->next)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't mod, stack too short\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	if (tmp->next->n == 0)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": division by zero\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	
	}
	tmp->n = tmp->n % tmp->next->n;
	free(tmp->next);
	tmp->next = NULL;
}

