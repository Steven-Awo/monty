#include "monty.h"
#include <string.h>
#include <stdlib.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);
size_t getline(char **lineptr, size_t *n, FILE *stream);
/**
 * free_tokens - A function that frees up the global op_toks
 * array of strings.
 * Return: void
 */

void free_tokens(void)
{
	size_t x = 0;

	if (op_toks == NULL)
	{
	return;
	}
	for (x = 0; op_toks[x]; x++)
	{
	free(op_toks[x]);
	}
	free(op_toks);
}

/**
 * token_arr_len - A function that gets the length of the
 * current op_toks.
 * Return: toks_len (successful)
 */

unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
	{
	toks_len++;
	}
	return (toks_len);
}

/**
 * is_empty_line - A function that checks if the line read by
 * getline only holds or contains delimiters.
 * @line: the line pointer.
 * @delims: the delimiter characters string.
 * Return: 1 (true) or 0 (false).
 */

int is_empty_line(char *line, char *delims)
{
	int x, y;

	for (x = 0; line[x]; x++)
	{
	for (y = 0; delims[y]; y++)
	{
	if (line[x] == delims[y])
	{
	break;
	}
	}
	if (delims[y] == '\0')
	{
	return (0);
	}
	}
	return (1);
}

/**
 * get_op_func - A function that matches an opcode to its
 * corresponding function.
 * @opcode: The opcode to be match.
 * Return: void.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"stackk", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};
	int x;

	for (x = 0; op_funcs[x].opcode; x++)
	{
	if (strcmp(opcode, op_funcs[x].opcode) == 0)
		return (op_funcs[x].f);
	}
	return (NULL);
}

/**
 * run_monty - A primary function that execute the Monty bytecodes script.
 * @script_fid: the File descriptor used for an open Monty bytecodes
 * script.
 * Return: EXIT_SUCCESS (successful) or respective error (failure).
 */
int run_monty(FILE *script_fid)
{
	stack_t *stackk = NULL;
	char *line = NULL;
	size_t lengh = 0, exit_statuss = EXIT_SUCCESS, len;
	unsigned int line_numb = 0, prev_tok_length = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stackk) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while ((len = getline(&line, &lengh, script_fid)) != (size_t)-1)
	{
		line_numb++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stackk);
			return (malloc_error());
		} else if (op_toks[0][0] == '#') /* comment line */
		{	free_tokens();
			continue;
		} op_func = get_op_func(op_toks[0]);
		exit_statuss = !op_func ? (free(stackk), unknown_op_error(op_toks[0],
					line_numb)) : 0;
		prev_tok_length = token_arr_len();
		op_func(&stackk, line_numb);
		if (token_arr_len() != prev_tok_length)
		{
			if (op_toks && op_toks[prev_tok_length])
				exit_statuss = atoi(op_toks[prev_tok_length]);
			else
				exit_statuss = EXIT_FAILURE;
			free_tokens();
			break;
		} free_tokens();
	}
	free_stack(&stackk);
	if (line && *line == 0)
	{	free(line);
		return (malloc_error());
	} free(line);
	return (exit_statuss);
}
