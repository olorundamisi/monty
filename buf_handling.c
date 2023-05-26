/*
 * File: buf_handling.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include <stdlib.h>

unsigned int _abs(int);
char *buf_itoa(int num);
int get_uint_buf_len(unsigned int num, unsigned int base);
void fill_uint_buf(unsigned int num, unsigned int base, char *buf,
		int buf_size);

/**
 * _abs - _abs
 * @i: i
 *
 * Return: abs(i)
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * buf_itoa - buf_itoa
 * @num: num
 *
 * Return: buf_itoa(num)
 */
char *buf_itoa(int num)
{
	char *ret;
	int lgth = 0;
	long num_lxyz = 0;
	unsigned int tmp;

	tmp = _abs(num);
	lgth = get_uint_buf_len(tmp, 10);

	if (num < 0 || num_lxyz < 0)
		lgth++;

	ret = malloc(lgth + 1);
	if (!ret)
		return (NULL);

	fill_uint_buf(tmp, 10, ret, lgth);
	if (num < 0 || num_lxyz < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * get_uint_buf_len - get_uint_buf_len
 * @num: num
 * @base: base
 *
 * Return: Don't need the nullptr (null byte)
 */
int get_uint_buf_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base; }
	return (len);
}

/**
 * fill_uint_buf - fill_uint_buf
 * @num: num
 * @base: base
 * @buf: buf
 * @buf_size: size of buffer
 *
 * Return: Toujour, void.
 */
void fill_uint_buf(unsigned int num, unsigned int base,
			char *buf, int buf_size)
{
	int rem, i = buf_size - 1;

	buf[buf_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buf[i] = rem + 87;
		else
			buf[i] = rem + '0';
		num /= base;
		i--; }
}
