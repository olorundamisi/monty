/*
 * File: err_handling.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

int err_file_open(char *filename);
int err_malloc_fail(void);
int err_prog_usage(void);
int err_push_integer(unsigned int line_num);
int err_unknown_instruction(char *opcode, unsigned int line_num);

/**
 * err_file_open - Print error message on file open failure.
 * @filename: filename
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_file_open(char *filename)
{
	_F_PRINTF_(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * err_malloc_fail - Print error message that occurs due to malloc() failure
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_malloc_fail(void)
{
	_F_PRINTF_(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * err_prog_usage - Print error message that occurs during program usage.
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_prog_usage(void)
{
	_F_PRINTF_(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * err_push_integer - Print push integer error
 * @line_num: The number of the line in the Monty bytecodes file script where
 *            the error occurred.
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_push_integer(unsigned int line_num)
{
	_F_PRINTF_(stderr, "L%u: usage: push integer\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * err_unknown_instruction - Print error message that occurs to unknown
 *                           operation.
 * @opcode: Operation Code showing where the error occurred.
 * @line_num: The number of the line in the Monty bytecodes file script where
 *            the error occurred.
 *
 * Return: Always return - EXIT_FAILURE.
 */
int err_unknown_instruction(char *opcode, unsigned int line_num)
{
	_F_PRINTF_(stderr, "L%u: unknown instruction %s\n",
		line_num, opcode);
	return (EXIT_FAILURE);
}
