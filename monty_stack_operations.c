/*
 * File: mstk_stack_operations.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

void mop_push(stack_t **stack, unsigned int line_num);
void mop_pall(stack_t **stack, unsigned int line_num);
void mop_pint(stack_t **stack, unsigned int line_num);
void mop_pop(stack_t **stack, unsigned int line_num);
void mop_swap(stack_t **stack, unsigned int line_num);

/**
 * mop_push - Push a value to a stack.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mop_push(stack_t **stack, unsigned int line_num)
{
	stack_t *temp_stk;
	stack_t *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		assign_opcode_token_err(err_malloc_fail());
		return; }
	if (operation_code_tokens[1] == NULL)
	{
		assign_opcode_token_err(err_push_integer(line_num));
		return; }
	for (i = 0; operation_code_tokens[1][i]; i++)
	{
		if (operation_code_tokens[1][i] == '-' && i == 0)
			continue;
		if (operation_code_tokens[1][i] < '0' ||
			operation_code_tokens[1][i] > '9')
		{
			assign_opcode_token_err(err_push_integer(line_num));
			return; } }
	new->n = atoi(operation_code_tokens[1]);
	if (chk_stack_mode(*stack) == _M_STACK_)
	{
		temp_stk = (*stack)->next;
		new->prev = *stack;
		new->next = temp_stk;
		if (temp_stk)
			temp_stk->prev = new;
		(*stack)->next = new;
	}
	else
	{
		temp_stk = *stack;
		while (temp_stk->next)
			temp_stk = temp_stk->next;
		new->prev = temp_stk;
		new->next = NULL;
		temp_stk->next = new; }
}

/**
 * mop_pall - Print the all values on a stack. Starting from top to bottom.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mop_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next; }
	(void)line_num;
}

/**
 * mop_pint - The opcode pint prints the value at the top of the stack.
 *            It is followed by a new line.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mop_pint(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		assign_opcode_token_err(err_pint_empty_stack(line_num));
		return; }

	printf("%d\n", (*stack)->next->n);
}


/**
 * mop_pop - Remove the top element of the stack.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mop_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		assign_opcode_token_err(err_pop_empty_stack(line_num));
		return; }

	next = (*stack)->next->next;
	free((*stack)->next);

	if (next)
		next->prev = *stack;

	(*stack)->next = next;
}

/**
 * mop_swap - Swap the top two elements of the stack.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mop_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		assign_opcode_token_err(err_stack_too_short(line_num, "swap"));
		return; }

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;

	if (tmp->next)
		tmp->next->prev = (*stack)->next;

	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
