#include "monty.h"

/**
 * m_rotl - A function that rotates the value at the top to the bottom
 * of a stack_t linked list.
 * @stackk: the topp mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 */

void m_rotl(stack_t **stackk, unsigned int line_numb)

{
	stack_t *topp, *bttm;

	if ((*stackk)->next == NULL || (*stackk)->next->next == NULL)
	{
	return;
	}
	topp = (*stackk)->next;
	bttm = (*stackk)->next;
	while (bttm->next != NULL)
	{
	bttm = bttm->next;
	}
	topp->next->prev = *stackk;
	(*stackk)->next = topp->next;
	bttm->next = topp;
	topp->next = NULL;
	topp->prev = bttm;
	(void)line_numb;
}

/**
 * m_rotr - A function that rotates the value at the bottom to the
 * top of a stack_t linked list.
 * @stackk: the topp mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 */

void m_rotr(stack_t **stackk, unsigned int line_numb)
{
	stack_t *topp, *bttm;

	if ((*stackk)->next == NULL || (*stackk)->next->next == NULL)
	{
	return;
	}
	topp = (*stackk)->next;
	bttm = (*stackk)->next;
	while (bttm->next != NULL)
	{
	bttm = bttm->next;
	}
	bttm->prev->next = NULL;
	(*stackk)->next = bttm;
	bttm->prev = *stackk;
	bttm->next = topp;
	topp->prev = bttm;
	(void)line_numb;
}

/**
 * m_stack - A function that converts from a queue to a stackk.
 * @stackk: the topp mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 */

void m_stack(stack_t **stackk, unsigned int line_numb)

{
	(*stackk)->n = STACK;
	(void)line_numb;
}

/**
 * m_queue - A function that converts from a stackk to a queue.
 * @stackk: the topp mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 */

void m_queue(stack_t **stackk, unsigned int line_numb)

{
	(*stackk)->n = QUEUE;
	(void)line_numb;
}
