#include <stdlib.h>

char **strtow(char *strg, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *strg, char *delims);
int get_word_count(char *strg, char *delims);
char *get_next_word(char *strg, char *delims);

/**
 * strtow - A function that takes in a string and then seperates
 * its wordss
 * @strg: the string to be seperated into wordss
 * @delims: the delimitors to be use to delimit the wordss
 * Return: word
 */

char **strtow(char *strg, char *delims)
{
	char **wordss = NULL;
	int wch, wordLeng, m, x = 0;

	if (strg == NULL || !*strg)
		return (NULL);
	wch = get_word_count(strg, delims);
	if (wch == 0)
		return (NULL);
	wordss = malloc((wch + 1) * sizeof(char *));
	if (wordss == NULL)
		return (NULL);
	while (x < wch)
	{
		wordLeng = get_word_length(strg, delims);
		if (is_delim(*strg, delims))
			strg = get_next_word(strg, delims);
		wordss[x] = malloc((wordLeng + 1) * sizeof(char));
		if (wordss[x] == NULL)
		{
			while (x >= 0)
			{
			x--;
			free(wordss[x]);
			}
			free(wordss);
			return (NULL);
		}
		m = 0;
		while (m < wordLeng)
		{
			wordss[x][m] = *(strg + m);
			m++;
		}
		wordss[x][m] = '\0';
		strg = get_next_word(strg, delims);
		x++;
	}
	wordss[x] = NULL;
	return (wordss);
}

/**
 * is_delim - A function that checks if the stream has a delimitor
 * char
 * @ch: the character to be delimit in the stream
 * @delims: the null terminated array of delimitors pointer
 * Return: 1 (successful) or 0 (unsuccessful)
 */

int is_delim(char ch, char *delims)

{
	int x = 0;

	while (delims[x])
	{
	if (delims[x] == ch)
	{
	return (1);
	}
	x++;
	}
	return (0);
}

/**
 * get_word_length - A function that gets the word's length of the
 * cur word in the strng
 * @strg: the string to used to get word length from the current word
 * @delims: the delimitors to be use to delimit the wordss
 * Return: word length of current word
 */

int get_word_length(char *strg, char *delims)

{
	int wLeng = 0, pendingg = 1, x = 0;

	while (*(strg + x))
	{
	if (is_delim(strg[x], delims))
	{
	pendingg = 1;
	}
	else if (pendingg)
	{
	wLeng++;
	}
	if (wLeng > 0 && is_delim(strg[x], delims))
	{
	break;
	}
	x++;
	}
	return (wLeng);
}

/**
 * get_word_count - A function that gets the count of a word of a
 * string
 * @strg: the string to gets the word count from
 * @delims: the delimitors to be use to delimit the wordss
 * Return: wch
 */

int get_word_count(char *strg, char *delims)

{
	int wch = 0, pendingg = 1, x = 0;

	while (*(strg + x))
	{
	if (is_delim(strg[x], delims))
	{
	pendingg = 1;
	}
	else if (pendingg)
	{
	pendingg = 0;
	wch++;
	}
	x++;
	}
	return (wch);
}

/**
 * get_next_word - A function that gets the next word in the string
 * @strg: the string to get the next word from
 * @delims: the delimitors to be use to delimit the wordss
 * Return: first char of the next word
 */

char *get_next_word(char *strg, char *delims)

{
	int pendingg = 0;
	int x = 0;

	while (*(strg + x))
	{
	if (is_delim(strg[x], delims))
	{
	pendingg = 1;
	}
	else if (pendingg)
	{
	break;
	}
	x++;
	}
	return (strg + x);
}
