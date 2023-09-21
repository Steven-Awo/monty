#include "monty.h"

/**
 * m_add - A function that adds to the two top values of the stack_t
 * linked list.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 * Description: The result is then stored in the node of the second
 * value and then it replaces the top value.
 */

void m_add(stack_t **stackk, unsigned int line_numb)
{
	if ((*stackk)->next == NULL || (*stackk)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_numb, "add"));
	return;
	}
	(*stackk)->next->next->n += (*stackk)->next->n;
	m_pop(stackk, line_numb);
}

/**
 * m_sub - A function that subtracts the top's second value from the top
 * first value of the stack_t linked list.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 * Description: The result is then stored in the node of the second
 * value and then it replaces the top value.
 */

void m_sub(stack_t **stackk, unsigned int line_numb)

{
	if ((*stackk)->next == NULL || (*stackk)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_numb, "sub"));
	return;
	}
	(*stackk)->next->next->n -= (*stackk)->next->n;
	m_pop(stackk, line_numb);
}

/**
 * m_div - A function that divides the top's second value from the top
 * first value of the stack_t linked list.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 * Description: The result is then stored in the node of the second
 * value and then it replaces the top value.
 */

void m_div(stack_t **stackk, unsigned int line_numb)

{
	if ((*stackk)->next == NULL || (*stackk)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_numb, "div"));
	return;
	}
	if ((*stackk)->next->n == 0)
	{
	set_op_tok_error(div_error(line_numb));
	return;
	}
	(*stackk)->next->next->n /= (*stackk)->next->n;
	m_pop(stackk, line_numb);
}

/**
 * m_mul - A function that multiplies the top's second value from
 * the top first value of the stack_t linked list.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 * Description: The result is then stored in the node of the second
 * value and then it replaces the top value.
 */

void m_mul(stack_t **stackk, unsigned int line_numb)
{
	if ((*stackk)->next == NULL || (*stackk)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_numb, "mul"));
	return;
	}
	(*stackk)->next->next->n *= (*stackk)->next->n;
	m_pop(stackk, line_numb);
}

/**
 * m_mod - A function that computes the modulus of the top's second
 * value from the top's first value of the stack_t linked list.
 * @stackk: the top mode node pointer of a stack_t linked list.
 * @line_numb: the Monty bytecodes file of the present working.
 * Description: The result is then stored in the node of the second
 * value and then it replaces the top value.
 */

void m_mod(stack_t **stackk, unsigned int line_numb)

{
	if ((*stackk)->next == NULL || (*stackk)->next->next == NULL)
	{
	set_op_tok_error(short_stack_error(line_numb, "mod"));
	return;
	}
	if ((*stackk)->next->n == 0)
	{
	set_op_tok_error(div_error(line_numb));
	return;
	}
	(*stackk)->next->next->n %= (*stackk)->next->n;
	m_pop(stackk, line_numb);
}
