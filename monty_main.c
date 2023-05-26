/*
 * File: monty_main.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

/**
 * monty_main - Master function that executes, loops and interprets through a
 *              Monty bytecodes file script.
 * @script_fd: File descriptor for the Monty bytecodes script to execute and
 *             interpret.
 *
 * Return: If function is successful - (EXIT_SUCCESS)
 *         Else - Print the appropriate error code.
 */
int monty_main(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_num = 0, length_of_previous_token = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (initialize_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_num++;
		operation_code_tokens = strtow(line, _DELIMITERS_);
		if (operation_code_tokens == NULL)
		{
			if (contains_only_delimiters(line, _DELIMITERS_))
				continue;
			free_stack(&stack);
			return (err_malloc_fail()); }
		else if (operation_code_tokens[0][0] == '#')
		{
			free_opcode_toks();
			continue; }
		op_func = match_opcode_to_function(operation_code_tokens[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = err_unknown_instruction(operation_code_tokens[0], line_num);
			free_opcode_toks();
			break; }
		length_of_previous_token = opcode_token_len();
		op_func(&stack, line_num);
		if (opcode_token_len() != length_of_previous_token)
		{
			if (operation_code_tokens &&
					operation_code_tokens[length_of_previous_token])
				exit_status =
					atoi(operation_code_tokens[length_of_previous_token]);
			else
				exit_status = EXIT_FAILURE;
			free_opcode_toks();
			break; }
		free_opcode_toks(); }
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (err_malloc_fail()); }

	free(line);
	return (exit_status);
}
