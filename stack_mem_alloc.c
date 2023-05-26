/*
 * File: stack_mem_alloc.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "monty.h"

int chk_stack_mode(stack_t *stack);
void free_stack(stack_t **stack);
int initialize_stack(stack_t **stack);

/**
 * chk_stack_mode - Check the mode of the stack_t linked list
 *					Stack Mode - _M_STACK_ (0).
 *					Queue Mode - _M_QUEUE_ (1).
 * @stack: A pointer to the top node - if STACK
 *		   A pointer to the bottom node - if QUEUE
 *
 * Return: If in stack mode - _M_STACK_ - 0.
 *         If in queue mode - _M_QUEUE_ - 1.
 *         Else - 2.
 */
int chk_stack_mode(stack_t *stack)
{
	if (stack->n == _M_STACK_)
		return (_M_STACK_);
	else if (stack->n == _M_QUEUE_)
		return (_M_QUEUE_);
	return (2);
}

/**
 * initialize_stack - Initialize a stack of type `stack_t`
 * @stack: A pointer to an unitialized stack of type `stack_t`
 *
 * Return: If function/function call fails - EXIT_FAILURE.
 *         Else - EXIT_SUCCESS.
 */
int initialize_stack(stack_t **stack)
{
	stack_t *stk;

	stk = malloc(sizeof(stack_t));
	if (stk == NULL)
		return (err_malloc_fail());

	stk->n = _M_STACK_;
	stk->prev = NULL;
	stk->next = NULL;

	*stack = stk;

	return (EXIT_SUCCESS);
}

/**
 * free_stack - Free a stack of type `stack_t`
 * @stack: A pointer to the top node - if STACK
 *		   A pointer to the bottom node - if QUEUE
 */
void free_stack(stack_t **stack)
{
	stack_t *stk = *stack;

	while (*stack)
	{
		stk = (*stack)->next;

		free(*stack);

		*stack = stk;
	}
}
