/*
 * File: monty_str_operations.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

void m_nop(stack_t **stack, unsigned int line_num);
void mstr_pchar(stack_t **stack, unsigned int line_num);
void mstr_pstr(stack_t **stack, unsigned int line_num);

/**
 * m_nop - The opcode nop doesn’t do anything.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void m_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * mstr_pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mstr_pchar(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		assign_opcode_token_err(err_pchar(line_num, "stack empty"));
		return; }
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		assign_opcode_token_err(err_pchar(line_num,
					     "value out of range"));
		return; }

	printf("%c\n", (*stack)->next->n);
}

/**
 * mstr_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mstr_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *stk = (*stack)->next;

	while (stk && stk->n != 0 && (stk->n > 0 && stk->n <= 127))
	{
		printf("%c", stk->n);
		stk = stk->next; }

	printf("\n");

	(void)line_num;
}
