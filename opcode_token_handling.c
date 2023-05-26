/*
 * File: opcode_token_handling.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

int contains_only_delimiters(char *line, char *delimiters);
unsigned int opcode_token_len(void);
void (*match_opcode_to_function(char *opcode))(stack_t**, unsigned int);
void free_opcode_toks(void);
void assign_opcode_token_err(int error_code);

/**
 * contains_only_delimiters - Check if line read from getline only contains
 *					delimiters.
 * @line: A pointer to the line.
 * @delimiters: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Else - 0.
 */
int contains_only_delimiters(char *line, char *delimiters)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delimiters[j]; j++)
		{
			if (line[i] == delimiters[j])
				break; }
		if (delimiters[j] == '\0')
		{
			return (0); }
	}

	return (1);
}

/**
 * free_opcode_toks - Free `extern char **operation_code_tokens` operation
 *						code tokens - type char ** -> array of char *
 */
void free_opcode_toks(void)
{
	size_t i = 0;

	if (operation_code_tokens == NULL)
		return;

	for (i = 0; operation_code_tokens[i]; i++)
		free(operation_code_tokens[i]);

	free(operation_code_tokens);
}

/**
 * match_opcode_to_function - Match opcode to function.
 * @opcode: The opcode to match to function.
 *
 * Return: A pointer to the corresponding function.
 */
void (*match_opcode_to_function(char *opcode))(stack_t**, unsigned int)
{
	instruction_t opcode_func_dict[] = {
		{"add", mval_add},
		{"div", mval_div},
		{"mod", mval_mod},
		{"mul", mval_mul},
		{"nop", m_nop},
		{"pall", mop_pall},
		{"pchar", mstr_pchar},
		{"pint", mop_pint},
		{"pop", mop_pop},
		{"pstr", mstr_pstr},
		{"push", mop_push},
		{"queue", mstk_queue},
		{"rotl", mstk_rotl},
		{"rotr", mstk_rotr},
		{"stack", mstk_stack},
		{"sub", mval_sub},
		{"swap", mop_swap},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcode_func_dict[i].opcode; i++)
	{
		if (strcmp(opcode, opcode_func_dict[i].opcode) == 0)
			return (opcode_func_dict[i].f);
	}

	return (NULL);
}

/**
 * opcode_token_len - Return length of current opcode token.
 *
 * Return: The length of current opcode token (integer).
 */
unsigned int opcode_token_len(void)
{
	unsigned int token_length = 0;

	while (operation_code_tokens[token_length])
		token_length++;
	return (token_length);
}

/**
 * assign_opcode_token_err - Assign an error code to the last element of
 *								operation_code_tokens.
 * @error_code: Error code (int) to store in operation_code_tokens (string).
 */
void assign_opcode_token_err(int error_code)
{
	char **new_tokens = NULL;
	char *exit_string = NULL;

	int token_length;
	int i;

	token_length = 0;
	i = 0;

	token_length = opcode_token_len();
	new_tokens = malloc(sizeof(char *) * (token_length + 2));
	if (!operation_code_tokens)
	{
		err_malloc_fail();
		return;
	}

	while (i < token_length)
	{
		new_tokens[i] = operation_code_tokens[i];
		i++;
	}

	exit_string = buf_itoa(error_code);
	if (!exit_string)
	{
		free(new_tokens);
		err_malloc_fail();
		return;
	}
	new_tokens[i++] = exit_string;
	new_tokens[i] = NULL;

	free(operation_code_tokens);

	operation_code_tokens = new_tokens;
}
