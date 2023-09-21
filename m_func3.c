#include "monty.h"

/**
 * m_nop - A function that does nothing for the Monty
 * opcode 'nop'.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 */

void m_nop(stack_t **stackk, unsigned int line_numb)

{
	(void)stackk;
	(void)line_numb;
}

/**
 * m_pchar - A function that prints the chr if the a stack_t linked
 * list at the top value node.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 */

void m_pchar(stack_t **stackk, unsigned int line_numb)

{
	if ((*stackk)->next == NULL)
	{
	set_op_tok_error(pchar_error(line_numb, "stackk empty"));
	return;
	}
	if ((*stackk)->next->n < 0 || (*stackk)->next->n > 127)
	{
	set_op_tok_error(pchar_error(line_numb,
				"value out of range"));
	return;
	}
	printf("%c\n", (*stackk)->next->n);
}

/**
 * m_pstr - A function that prints out the string that is contained
 * in a stack_t linked list.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 */

void m_pstr(stack_t **stackk, unsigned int line_numb)

{
	stack_t *tmpp = (*stackk)->next;

	while (tmpp && tmpp->n != 0 && (tmpp->n > 0 && tmpp->n <= 127))
	{
	printf("%c", tmpp->n);
	tmpp = tmpp->next;
	}
	printf("\n");
	(void)line_numb;
}
