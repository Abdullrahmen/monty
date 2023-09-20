#include "monty.h"

void i_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *iter = NULL;

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

void i_pop(stack_t **stack, unsigned int line_number)
{}

void i_swap(stack_t **stack, unsigned int line_number)
{}

void i_add(stack_t **stack, unsigned int line_number)
{}
