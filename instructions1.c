#include "monty.h"

/**
* i_pall - pall instruction
* @stack: stack
* @line_number: line number
*/
void i_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *iter = NULL;

	(void)line_number;
	if (!*stack)
		return;
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	while (iter)
	{
		printf("%d\n", iter->n);
		iter = iter->prev;
	}

}

/**
* i_pint - pint instruction
* @stack: stack
* @line_number: line number
*/
void i_pint(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *iter = NULL;

	if (!*stack)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't pint, stack empty\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	printf("%d\n", iter->n);
}

/**
* i_pop - pop instruction
* @stack: stack
* @line_number: line number
*/
void i_pop(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *iter = NULL;

	if (!*stack)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't pop an empty stack\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	iter = *stack;
	if (iter->next)
	{
		while (iter->next->next)
			iter = iter->next;
		free(iter->next);
		iter->next = NULL;
	}
	else
	{
		free(iter);
		*stack = NULL;
	}
}

/**
* i_swap - swap instruction
* @stack: stack
* @line_number: line number
*/
void i_swap(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *tmp = NULL, *tmp2 = NULL;

	if (!*stack || !(*stack)->next)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't swap, stack too short\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->prev->next = tmp2;
	tmp2->prev = tmp->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	tmp->next = NULL;
}

/**
* i_add - add instruction
* @stack: stack
* @line_number: line number
*/
void i_add(stack_t **stack, unsigned int line_number)
{
	char *err_msg = NULL;
	stack_t *tmp = NULL;

	if (!*stack || !(*stack)->next)
	{
		err_msg = strdup("L");
		concat_int(&err_msg, line_number);
		_strcat(&err_msg, ": can't add, stack too short\n");
		exit_failure(err_msg, *stack, NULL, NULL, NULL);
	}
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->n = tmp->next->n + tmp->n;
	free(tmp->next);
	tmp->next = NULL;
}


