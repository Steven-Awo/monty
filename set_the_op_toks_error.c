#include "monty.h"

/**
 * set_op_tok_error - A function that sets the last element of a op_toks
 * to be the error code.
 * @error_coded: the int to stored as a string in the op_toks.
 */

void set_op_tok_error(int error_code)

{
	int toks_leng = 0, x = 0;
	char *exit_strg = NULL;
	char **new_tokens = NULL;

	toks_leng = token_arr_len();
	new_tokens = malloc(sizeof(char *) * (toks_leng + 2));
	if (!op_toks)
	{
	malloc_error();
	return;
	}
	while (x < toks_leng)
	{
	new_tokens[x] = op_toks[x];
	x++;
	}
	exit_strg = get_int(error_code);
	if (!exit_strg)
	{
	free(new_tokens);
	malloc_error();
	return;
	}
	new_tokens[x++] = exit_strg;
	new_tokens[x] = NULL;
	free(op_toks);
	op_toks = new_tokens;
}
