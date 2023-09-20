#include "monty.h"

/**
* _strcat - string concat
* @s1: string 1
* @s2: string 2
*/
void _strcat(char **s1, char *s2)
{
	char *tmp = NULL;

	tmp = malloc(sizeof(char) * (strlen(*s1) + strlen(s2) + 1));
	tmp[0] = '\0';
	strcat(tmp, *s1);
	strcat(tmp, s2);
	free(*s1);
	*s1 = tmp;
}

/**
* concat_int - concat string with unsigned int
* @str: the string
* @line_number: the unsigned int
*/
void concat_int(char **str, unsigned int line_number)
{
	char *final_str = NULL;
	unsigned int degits = 0, temp = line_number, i = 0;

	while (temp)
	{
		++degits;
		temp = temp / 10;
	}
	final_str = malloc(sizeof(char) * (strlen(*str) + degits + 1));
	while ((*str)[i])
	{
		final_str[i] = (*str)[i];
		++i;
	}
	temp = line_number;
	while (temp)
	{
		final_str[i] = (temp % 10) + '0';
		temp = temp / 10;
		++i;
	}
	final_str[i] = '\0';
	free(*str);
	*str = final_str;
}

/**
* get_pushed_number - get the pushed number of line
* @line: line
* @line_number: used in errors
* @stack: stack
* Return: the number
*/
int get_pushed_number(char *line, unsigned int line_number, stack_t *stack)
{
	char *error_msg = NULL;
	int is_fail = 0;

	while (*line == ' ')
		++line;

	if (*line == '-')
	{
		if (line[1] < '0' || line[1] > '9')
			is_fail = 1;
	}
	else if (*line < '0' || *line > '9')
		is_fail = 1;

	if (is_fail)
	{
		error_msg = strdup("L");
		concat_int(&error_msg, line_number);
		_strcat(&error_msg, ": usage: push integer\n");
		exit_failure(error_msg, stack, NULL, NULL, NULL);
	}

	return (atoi(line));
}

/**
* i_push_queue - push instruction for the queue
* @stack: stack
* @n: the number
*/
void i_push_queue(stack_t **stack, int n)
{
	stack_t *head = NULL;

	head = malloc(sizeof(stack_t));
	if (!head)
		exit_failure(strdup("Error: malloc failed\n"),
					*stack, NULL, NULL, NULL);
	head->prev = NULL;
	head->next = *stack;
	head->n = n;
	(*stack)->prev = head;
	*stack = head;
}

/**
* i_push - push instruction
* @line: line
* @stack: stack
* @line_number: line number
*/
void i_push(char *line, stack_t **stack, unsigned int line_number)
{
	stack_t *iter = NULL, *prev = NULL;
	int n = 0;

	if (!line)
		return;

	n = get_pushed_number(line, line_number, *stack);
	if (!*stack)
	{
		*stack = malloc(sizeof(stack_t));
		if (!*stack)
			exit_failure(strdup("Error: malloc failed\n"),
						*stack, NULL, NULL, NULL);
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		(*stack)->n = n;
		return;
	}

	if (is_queue)
	{
		i_push_queue(stack, n);
		return;
	}
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	prev = iter;
	iter->next = malloc(sizeof(stack_t));
	iter = prev->next;
	iter->prev = prev;
	iter->next = NULL;
	iter->n = n;
}

