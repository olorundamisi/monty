#ifndef __MONTY_H__
#define __MONTY_H__

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * monty: ------ FILES -------
 *        buf_handling.c
 *        buf_parsing_and_lexing.c
 *        err_handling_helper.c
 *        err_handling.c
 *        main.c
 *        monty_arr_operations.c
 *        monty_main.c
 *        monty_stack_operations.c
 *        monty_stack.c
 *        monty_str_operations.c
 *        monty.h
 *        opcode_token_handling.c
 *        stack_mem_alloc.c
 */

#ifndef _F_PRINTF_
#define _F_PRINTF_ fprintf
#endif /* _F_PRINTF_ */

#ifndef _M_STACK_
#define _M_STACK_ 0
#endif /* _M_STACK_ */

#ifndef _M_QUEUE_
#define _M_QUEUE_ 1
#endif /* _M_QUEUE_ */

#ifndef _DELIMITERS_
#define _DELIMITERS_ " \n\t\a\b"
#endif /* _DELIMITERS_ */

/* GLOBAL VARIABLE FOR OPERATION CODE TOKENS */
extern char **operation_code_tokens;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
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
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

char **strtow(char *, char *);
char *buf_itoa(int);
int chk_stack_mode(stack_t *);
int err_div_by_zero(unsigned int);
int err_file_open(char *);
int initialize_stack(stack_t **);
int contains_only_delimiters(char *, char *);
int err_malloc_fail(void);
int monty_main(FILE *script_fd);
int err_push_integer(unsigned int);
int err_pchar(unsigned int, char *);
int err_pint_empty_stack(unsigned int);
int err_pop_empty_stack(unsigned int);
int err_stack_too_short(unsigned int, char *);
int err_unknown_instruction(char *, unsigned int);
int err_prog_usage(void);
unsigned int opcode_token_len(void);
void (*match_opcode_to_function(char *))(stack_t**, unsigned int);
void free_stack(stack_t **);
void free_opcode_toks(void);
void mval_add(stack_t **, unsigned int);
void mval_div(stack_t **, unsigned int);
void mval_mod(stack_t **, unsigned int);
void mval_mul(stack_t **, unsigned int);
void m_nop(stack_t **, unsigned int);
void mop_pall(stack_t **, unsigned int);
void mstr_pchar(stack_t **, unsigned int);
void mop_pint(stack_t **, unsigned int);
void mop_pop(stack_t **, unsigned int);
void mstr_pstr(stack_t **, unsigned int);
void mop_push(stack_t **, unsigned int);
void mstk_queue(stack_t **, unsigned int);
void mstk_rotl(stack_t **, unsigned int);
void mstk_rotr(stack_t **, unsigned int);
void mstk_stack(stack_t **, unsigned int);
void mval_sub(stack_t **, unsigned int);
void mop_swap(stack_t **, unsigned int);
void assign_opcode_token_err(int error_code);

#endif /* __MONTY_H__ */
