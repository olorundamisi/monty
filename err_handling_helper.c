/*
 * File: err_handling_helper.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

int err_div_by_zero(unsigned int line_num);
int err_pchar(unsigned int line_num, char *message);
int err_pint_empty_stack(unsigned int line_num);
int err_pop_empty_stack(unsigned int line_num);
int err_stack_too_short(unsigned int line_num, char *op);

/**
 * err_div_by_zero - Print error message for "division by 0".
 * @line_num: The number of the line in the Monty bytecodes file script where
 *            the error occurred.
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_div_by_zero(unsigned int line_num)
{
	_F_PRINTF_(stderr, "L%u: division by zero\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * err_pchar - Print error messages for `pchar`
 *               Can print error messages for empty stacks and
 *               Error messages for non-character values.
 * @line_num: The number of the line in the Monty bytecodes file script where
 *            the error occurred.
 * @message: The error message that corresponds to print.
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_pchar(unsigned int line_num, char *message)
{
	_F_PRINTF_(stderr, "L%u: can't pchar, %s\n", line_num, message);
	return (EXIT_FAILURE);
}

/**
 * err_pint_empty_stack - For empty stacks, print pint error messages
 * @line_num: The number of the line in the Monty bytecodes file script where
 *            the error occurred.
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_pint_empty_stack(unsigned int line_num)
{
	_F_PRINTF_(stderr, "L%d: can't pint, stack empty\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * err_pop_empty_stack - For empty stacks, print pop error messages
 * @line_num: The number of the line in the Monty bytecodes file script where
 *            the error occurred.
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_pop_empty_stack(unsigned int line_num)
{
	_F_PRINTF_(stderr, "L%u: can't pop an empty stack\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * err_stack_too_short - Print math function error for shorter than two nodes.
 * @line_num: The number of the line in the Monty bytecodes file script where
 *            the error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_stack_too_short(unsigned int line_num, char *op)
{
	_F_PRINTF_(stderr, "L%u: can't %s, stack too short\n", line_num, op);
	return (EXIT_FAILURE);
}
