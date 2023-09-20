#ifndef MONTY_H_
#define MONTY_H_
#define NUMBER_OF_INSTRUCTIONS 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int is_queue;

/**** Stractures *****/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 h  @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/***** Functions *****/
/* utilz.c */
void exit_failure(char *err_msg, stack_t *stack, char *line, instruction_t *instructions, FILE *file);
void init_instructions(instruction_t *instructions);
void exec_opcode_func(stack_t **stack, char *line, unsigned int line_number, instruction_t *instructions);
void free_stack(stack_t *stack);
void free_instructions(instruction_t *instructions);


void _strcat(char **s1, char *s2);
void concat_int(char **str, unsigned int line_number);


/* instructions1.c */
void i_push(char *line, stack_t **stack, unsigned int line_number);
void i_pall(stack_t **stack, unsigned int line_number);
void i_pint(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H_ */

