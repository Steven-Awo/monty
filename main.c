#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - the function for entry point for the Monty Interpreter
 * @argc: the arguments count passed to the program
 * @argv: an array pointer to the char pointers to arguments
 * Return: EXIT_SUCCESS(successful) or EXIT_FAILURE (unsuccessful)
 */

int main(int argc, char **argv)

{
	FILE *script_fid = NULL;
	int exit_code_ = EXIT_SUCCESS;

	if (argc != 2)
	{
	return (usage_error());
	}
	script_fid = fopen(argv[1], "r");
	if (script_fid == NULL)
	{
	return (f_open_error(argv[1]));
	}
	exit_code_ = run_monty(script_fid);
	fclose(script_fid);
	free(op_toks);
	return (exit_code_);
}
