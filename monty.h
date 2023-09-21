#ifndef _MONTY_H_
#define _MONTY_H_

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct stack_s - A function that doubly linked list
 * representation of a stackk (or queue)
 * @n: integer
 * @prev: points to the previous element of the stackk (or queue)
 * @next: points to the next element of the stackk (or queue)
 * Description: doubly linked list node structure
 * for stackk, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - A function that opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stackk, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stackk, unsigned int line_numb);
} instruction_t;

extern char **op_toks;

void free_stack(stack_t **stackk);

int init_stack(stack_t **stackk);

int check_mode(stack_t *stackk);

void free_tokens(void);

unsigned int token_arr_len(void);

int run_monty(FILE *script_fid);

void set_op_tok_error(int error_code);

void m_push(stack_t **stackk, unsigned int line_numb);

void m_pall(stack_t **stackk, unsigned int line_numb);

void m_pint(stack_t **stackk, unsigned int line_numb);

void m_pop(stack_t **stackk, unsigned int line_numb);

void m_swap(stack_t **stackk, unsigned int line_numb);

void m_add(stack_t **stackk, unsigned int line_numb);

void m_nop(stack_t **stackk, unsigned int line_numb);

void m_sub(stack_t **stackk, unsigned int line_numb);

void m_div(stack_t **stackk, unsigned int line_numb);

void m_mul(stack_t **stackk, unsigned int line_numb);

void m_mod(stack_t **stackk, unsigned int line_numb);

void m_pchar(stack_t **stackk, unsigned int line_numb);

void m_pstr(stack_t **stackk, unsigned int line_numb);

void m_rotl(stack_t **stackk, unsigned int line_numb);

void m_rotr(stack_t **stackk, unsigned int line_numb);

void m_stack(stack_t **stackk, unsigned int line_numb);

void m_queue(stack_t **stackk, unsigned int line_numb);

/* THE CUSTOM STANDARD LIBRARY FUNCTIONS */

char **strtow(char *strg, char *delims);

int is_delim(char ch, char *delims);

char *get_int(int n);

/* THE ERROR MESSAGES & CODES */

int usage_error(void);

int malloc_error(void);

int f_open_error(char *file_name);

int unknown_op_error(char *opcode, unsigned int line_numb);

int no_int_error(unsigned int line_numb);

int pop_error(unsigned int line_numb);

int pint_error(unsigned int line_numb);

int short_stack_error(unsigned int line_numb, char *op);

int div_error(unsigned int line_numb);

int pchar_error(unsigned int line_numb, char *message);

int get_word_length(char *strg, char *delims);

int get_word_count(char *strg, char *delims);

char *get_next_word(char *strg, char *delims);
#endif
