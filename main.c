/*
 * File: main.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

char **operation_code_tokens = NULL;

/**
 * main - main(...) function
 *        Entry Point for Monty Bytecode Script Interpreter
 *
 * @arg_cnt: arg_cnt
 * @arg_vec: arg_vec
 *
 * Return: If entire function and function calls succeed - (EXIT_SUCCESS)
 *         Else - (EXIT_FAILURE)
 */
int main(int arg_cnt, char **arg_vec)
{
	int EXIT_CODE;

	FILE *script_fd = NULL;

	EXIT_CODE = EXIT_SUCCESS;

	if (arg_cnt != 2)
		return (err_prog_usage());

	script_fd = fopen(arg_vec[1], "r");

	if (script_fd == NULL)
		return (err_file_open(arg_vec[1]));

	EXIT_CODE = monty_main(script_fd);

	fclose(script_fd);

	return (EXIT_CODE);
}
