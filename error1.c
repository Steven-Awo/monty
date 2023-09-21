#include "monty.h"

/**
 * usage_error - A function that prints out the usage
 * error messages.
 * Return: EXIT_FAILURE
 */

int usage_error(void)

{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - A function that prints out the file opening
 * error messages when using w/ file name.
 * @file_name: the file name that failed to open
 * Return: EXIT_FAILURE
 */

int f_open_error(char *file_name)

{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - A function that prints out the malloc
 * error messages.
 * Return: EXIT_FAILURE
 */

int malloc_error(void)

{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * no_int_error - A function that prints out the invalid
 * m_push argument error messages.
 * @line_numb: the line number in Monty bytecodes file the
 * error occured
 * Return: EXIT_FAILURE
 */

int no_int_error(unsigned int line_numb)

{
	fprintf(stderr, "L%u: usage: push integer\n", line_numb);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - A function that prints out the unknown
 * instruct error messages.
 * @opcode: the Opcode where the error occurred.
 * @line_numb: the line number in Monty bytecodes file the
 * error occured
 * Return: EXIT_FAILURE
 */

int unknown_op_error(char *opcode, unsigned int line_numb)

{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_numb, opcode);
	return (EXIT_FAILURE);
}
