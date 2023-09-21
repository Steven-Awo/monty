#include <stdlib.h>
#include "monty.h"

char *get_int(int numb);
unsigned int _abs(int);
int get_numbase_len(unsigned int numb, unsigned int base);
void fill_numbase_buff(unsigned int numb, unsigned int base,
		       char *buff, int buff_size);

/**
 * get_int - A function that gets the a chr that points to
 * the new str containing int
 * @numb: the number to be convert to string
 * Return: retrn(successful) or NULL (unsuccessful)
 */

char *get_int(int numb)
{
	unsigned int tmp;
	int lengt = 0;
	long numb_l = 0;
	char *retrn;

	tmp = _abs(numb);
	lengt = get_numbase_len(tmp, 10);

	if (numb < 0 || numb_l < 0)
	{
	lengt++; /* negative sign */
	}
	retrn = malloc(lengt + 1); /* create new string */
	if (!retrn)
	{
	return (NULL);
	}
	fill_numbase_buff(tmp, 10, retrn, lengt);
	if (numb < 0 || numb_l < 0)
	{
	retrn[0] = '-';
	}
	return (retrn);
}

/**
 * _abs - A function that gets the absolute value of
 * any integer
 * @x: the integer used to get absolute value
 * Return: unsigned integer x
 */

unsigned int _abs(int x)
{
	if (x < 0)
	{
	return (-(unsigned int)x);
	}
	return ((unsigned int)x);
}

/**
 * get_numbase_len - A function that gets buffer's length needed
 * for any unsigned int
 * @numb: the number to get the length needed for
 * @base: the representation of base of number used by buffer
 * Return: lent
 */

int get_numbase_len(unsigned int numb, unsigned int base)
{
	int lent = 1;

	while (numb > base - 1)
	{
	lent++;
	numb /= base;
	}
	return (lent);
}

/**
 * fill_numbase_buff - A function that fills the buffer with the
 * right numbers up to base 36
 * @numb: the number to be convert to the string given base
 * @base: the base of number used in conversion, only works up to base 36
 * @buff: the buffer to be filled with the conversion result
 * @buff_size: the size of the buffer in bytes
 * Return: void.
 */

void fill_numbase_buff(unsigned int numb, unsigned int base,
			char *buff, int buff_size)
{
	int remm, x = buff_size - 1;

	buff[buff_size] = '\0';
	while (x >= 0)
	{
	remm = numb % base;
	if (remm > 9)
	{
	buff[x] = remm + 87;
	}
	else
	{
	buff[x] = remm + '0';
	}
	numb /= base;
	x--;
	}
}
