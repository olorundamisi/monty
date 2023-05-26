/*
 * File: monty_math_operations.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

void mval_add(stack_t **stack, unsigned int line_num);
void mval_sub(stack_t **stack, unsigned int line_num);
void mval_div(stack_t **stack, unsigned int line_num);
void mval_mul(stack_t **stack, unsigned int line_num);
void mval_mod(stack_t **stack, unsigned int line_num);

/**
 * mval_add - Add the two values at the top of a stack or queue.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mval_add(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		assign_opcode_token_err(err_stack_too_short(line_num, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	mop_pop(stack, line_num);
}

/**
 * mval_sub - Subtract the two values at the top of a stack or queue.
 *            Second value - Top Value
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mval_sub(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		assign_opcode_token_err(err_stack_too_short(line_num, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	mop_pop(stack, line_num);
}

/**
 * mval_div - Divide the two values at the top of a stack or queue.
 *            Second value / Top Value
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mval_div(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		assign_opcode_token_err(err_stack_too_short(line_num, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		assign_opcode_token_err(err_div_by_zero(line_num));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	mop_pop(stack, line_num);
}

/**
 * mval_mul - Multiply the two values at the top of a stack or queue.
 *            Second value * Top Value
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mval_mul(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		assign_opcode_token_err(err_stack_too_short(line_num, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	mop_pop(stack, line_num);
}

/**
 * mval_mod - Calculates modulus of two values at the top of a stack or queue.
 *            Second value * Top Value
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mval_mod(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		assign_opcode_token_err(err_stack_too_short(line_num, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		assign_opcode_token_err(err_div_by_zero(line_num));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	mop_pop(stack, line_num);
}
