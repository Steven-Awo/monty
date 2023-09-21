#include "monty.h"

/**
 * short_stack_error - A function that prints out the function for monty
 * math error messages for stacks/queues smaller than two nodes.
 * @line_numb: the line number in Monty bytecodes file the
 * error occured
 * @op: Operation where the error occurred.
 * Return: EXIT_FAILURE
 */

int short_stack_error(unsigned int line_numb, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_numb, op);
	return (EXIT_FAILURE);
}

/**
 * pop_error - A function that prints out the pop error
 * messages for empty stacks.
 * @line_numb: the line number in Monty bytecodes file the
 * error occured
 * Return: EXIT_FAILURE
 */

int pop_error(unsigned int line_numb)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_numb);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - A function that prints out the pchar error messages
 * for empty stacks and any non-character values.
 * @line_numb: the line number in Monty bytecodes file the
 * error occured
 * @msg: The error corresponding msg to print.
 * Return: EXIT_FAILURE
 */

int pchar_error(unsigned int line_numb, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_numb, msg);
	return (EXIT_FAILURE);
}

/**
 * pint_error - A function that prints out the error messages
 * for empty stacks.
 * @line_numb: the line number in Monty bytecodes file the
 * error occured
 * Return: EXIT_FAILURE
 */

int pint_error(unsigned int line_numb)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_numb);
	return (EXIT_FAILURE);
}

/**
 * div_error - A function that prints out the division error
 * messages for the division by 0.
 * @line_numb: the line number in Monty bytecodes file the
 * error occured
 * Return: EXIT_FAILURE
 */

int div_error(unsigned int line_numb)
{
	fprintf(stderr, "L%u: division by zero\n", line_numb);
	return (EXIT_FAILURE);
}
