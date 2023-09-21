#include "monty.h"
#include <string.h>

/**
 * free_stack - A function that frees up a stack_t stack.
 * @stackk: the pointer to either the top (stackk) or
 * bottom (queue) of the stack_t.
 */

void free_stack(stack_t **stackk)

{
	stack_t *tmp = *stackk;

	while (*stackk)
	{
	tmp = (*stackk)->next;
	free(*stackk);
	*stackk = tmp;
	}
}

/**
 * init_stack - A function that initialiates a stack_t stack with the
 * beginning stackk and the ending queue nodes.
 * @stackk: the unitialized stack_t stackk pointer.
 * Return: EXIT_SUCCESS (successful) or EXIT_FAILURE (unsuccessful)
 */

int init_stack(stack_t **stackk)
{
	stack_t *z;

	z = malloc(sizeof(stack_t));
	if (z == NULL)
	{
	return (malloc_error());
	}
	z->n = STACK;
	z->prev = NULL;
	z->next = NULL;
	*stackk = z;
	return (EXIT_SUCCESS);
}

/**
 * check_mode - A function that checks if the stack_t linked list is in the
 * stackk or queue mode.
 * @stackk: the top (stackk) or bottom (queue) of a stack_t
 * linked list pointer.
 * Return: stackk mode - STACK (0).
 * queue mode - QUEUE (1).
 * Otherwise - 2.
 */

int check_mode(stack_t *stackk)
{

	if (stackk->n == STACK)
	{
	return (STACK);
	}
	else if (stackk->n == QUEUE)
	{
	return (QUEUE);
	}
	return (2);
}
