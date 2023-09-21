#include "monty.h"

void m_push(stack_t **stackk, unsigned int line_numb);
void m_pall(stack_t **stackk, unsigned int line_numb);
void m_pint(stack_t **stackk, unsigned int line_numb);
void m_pop(stack_t **stackk, unsigned int line_numb);
void m_swap(stack_t **stackk, unsigned int line_numb);

/**
 * m_push - A function that pushes to a stack_t linked list a value.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working
 * line number of.
 */
void m_push(stack_t **stackk, unsigned int line_numb)
{
	stack_t *tmpp, *neww;
	int x;

	neww = malloc(sizeof(stack_t));
	if (neww == NULL)
	{
	set_op_tok_error(malloc_error());
	return;
	}
	if (op_toks[1] == NULL)
	{
	set_op_tok_error(no_int_error(line_numb));
	return;
	}
	for (x = 0; op_toks[1][x]; x++)
	{
	if (op_toks[1][x] == '-' && x == 0)
		continue;
	if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
	{
	set_op_tok_error(no_int_error(line_numb));
	return;
	}}
	neww->n = atoi(op_toks[1]);
	if (check_mode(*stackk) == STACK) /* STACK mode insert at front */
	{
	tmpp = (*stackk)->next;
	neww->prev = *stackk;
	neww->next = tmpp;
	if (tmpp)
		tmpp->prev = neww;
	(*stackk)->next = neww;
	}
	else /* QUEUE mode insert at end */
	{
	tmpp = *stackk;
	while (tmpp->next)
		tmpp = tmpp->next;
	neww->prev = tmpp;
	neww->next = NULL;
	tmpp->next = neww;
	}
}

/**
 * m_pall - A function that prints out a stack_t linked list top value.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working
 * line number of.
 */
void m_pall(stack_t **stackk, unsigned int line_numb)
{
	stack_t *tmpp = (*stackk)->next;

	while (tmpp)
	{
	printf("%d\n", tmpp->n);
	tmpp = tmpp->next;
	}
	(void)line_numb;
}

/**
 * m_pint - A function that prints the stack_t linked list top value.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working
 * line number of.
 */

void m_pint(stack_t **stackk, unsigned int line_numb)

{
	if ((*stackk)->next == NULL)
	{
	set_op_tok_error(pint_error(line_numb));
	return;
	}
	printf("%d\n", (*stackk)->next->n);
}


/**
 * m_pop - A function that removes the stack_t linked list top value
 * element of a.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working
 * line number of.
 */

void m_pop(stack_t **stackk, unsigned int line_numb)
{
	stack_t *next = NULL;

	if ((*stackk)->next == NULL)
	{
	set_op_tok_error(pop_error(line_numb));
	return;
	}
	next = (*stackk)->next->next;
	free((*stackk)->next);
	if (next)
	{
	next->prev = *stackk;
	}
	(*stackk)->next = next;
}

/**
 * m_swap - A function that swaps in the stack_t linked list the
 * top two value elements of a.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working
 * line number of.
 */

void m_swap(stack_t **stackk, unsigned int line_numb)
{
	stack_t *tmpp;

	if ((*stackk)->next == NULL || (*stackk)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_numb, "swap"));
	return;
	}
	tmpp = (*stackk)->next->next;
	(*stackk)->next->next = tmpp->next;
	(*stackk)->next->prev = tmpp;
	if (tmpp->next)
	{
	tmpp->next->prev = (*stackk)->next;
	}
	tmpp->next = (*stackk)->next;
	tmpp->prev = *stackk;
	(*stackk)->next = tmpp;
}
