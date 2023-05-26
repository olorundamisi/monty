/*
 * File: buf_parsing_and_lexing.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include <stdlib.h>

char *obtain_nxt_w(char *str, char *delims);
char **strtow(char *str, char *delims);
int is_a_delimiter(char ch, char *delims);
int obtain_w_cnt(char *str, char *delims);
int obtain_w_len(char *str, char *delims);

/**
 * strtow - String tokenizer
 *
 * @str: string to tokenize
 * @delims: Delimiters in string to delimit
 *
 * Return: tokenized string
 */

char **strtow(char *str, char *delims)
{
	int word_cnt, length_of_word, n, i = 0;
	char **wds_arr = NULL;

	if (str == NULL || !*str)
		return (NULL);
	word_cnt = obtain_w_cnt(str, delims);

	if (word_cnt == 0)
		return (NULL);
	wds_arr = malloc((word_cnt + 1) * sizeof(char *));
	if (wds_arr == NULL)
		return (NULL);
	while (i < word_cnt)
	{
		length_of_word = obtain_w_len(str, delims);
		if (is_a_delimiter(*str, delims))
		{
			str = obtain_nxt_w(str, delims);
		}
		wds_arr[i] = malloc((length_of_word + 1) * sizeof(char));
		if (wds_arr[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(wds_arr[i]); }
			free(wds_arr);
			return (NULL); }
		n = 0;
		while (n < length_of_word)
		{
			wds_arr[i][n] = *(str + n);
			n++; }
		wds_arr[i][n] = '\0';
		str = obtain_nxt_w(str, delims);
		i++; }
	wds_arr[i] = NULL;
	return (wds_arr);
}

/**
 * is_a_delimiter - Assert if input stream has a delimiter character
 * @ch: ch
 * @delims: delims
 *
 * Return: 1 (success) 0 (failure)
 */

int is_a_delimiter(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * obtain_w_len - obtain word length
 *
 * @str: string
 * @delims: delimiters
 *
 * Return: word length
 */

int obtain_w_len(char *str, char *delims)
{
	int word_length = 0, pdng = 1, i = 0;

	while (*(str + i))
	{
		if (is_a_delimiter(str[i], delims))
			pdng = 1;
		else if (pdng)
		{
			word_length++;
		}
		if (word_length > 0 && is_a_delimiter(str[i], delims))
			break;
		i++;
	}
	return (word_length);
}

/**
 * obtain_w_cnt - Obtain the word count
 *
 * @str: str
 * @delims: delims
 *
 * Return: word count
 */

int obtain_w_cnt(char *str, char *delims)
{
	int word_cnt = 0, pdng = 1, i = 0;

	while (*(str + i))
	{
		if (is_a_delimiter(str[i], delims))
			pdng = 1;
		else if (pdng)
		{
			pdng = 0;
			word_cnt++;
		}
		i++;
	}
	return (word_cnt);
}

/**
 * obtain_nxt_w - Obtain the next word in a string
 *
 * @str: string
 * @delims: delimiters
 *
 * Return: str + i
 */

char *obtain_nxt_w(char *str, char *delims)
{
	int pdng = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_a_delimiter(str[i], delims))
			pdng = 1;
		else if (pdng)
			break;
		i++;
	}
	return (str + i);
}
