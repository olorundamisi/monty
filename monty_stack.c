/*
 * File: monty_stack.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

void mstk_rotl(stack_t **stack, unsigned int line_num);
void mstk_rotr(stack_t **stack, unsigned int line_num);
void mstk_stack(stack_t **stack, unsigned int line_num);
void mstk_queue(stack_t **stack, unsigned int line_num);

/**
 * mstk_rotl - The opcode rotr rotates the stack to the top.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mstk_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *first, *last;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	first = (*stack)->next;
	last = (*stack)->next;
	while (last->next != NULL)
		last = last->next;

	first->next->prev = *stack;
	(*stack)->next = first->next;
	last->next = first;
	first->next = NULL;
	first->prev = last;

	(void)line_num;
}

/**
 * mstk_rotr - The opcode rotr rotates the stack to the bottom.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mstk_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *first, *last;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	first = (*stack)->next;
	last = (*stack)->next;
	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	(*stack)->next = last;
	last->prev = *stack;
	last->next = first;
	first->prev = last;

	(void)line_num;
}

/**
 * mstk_stack - Convert a queue to a stack.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mstk_stack(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = _M_STACK_;
	(void)line_num;
}

/**
 * mstk_queue - Convert a stack to a queue.
 * @stack: A pointer to the top/bottom node of a stack or queue.
 * @line_num: The number of the current being interpreted in the Monty
 *            bytecodes file.
 */
void mstk_queue(stack_t **stack, unsigned int line_num)
{
	(*stack)->n = _M_QUEUE_;
	(void)line_num;
}
