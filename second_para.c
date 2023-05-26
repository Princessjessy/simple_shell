#include "shell.h"

/**
 *free_me - free memory
 *@input: pointer to command
 *@run: pointer to line
 *
 *Return: nothing
 */
void free_me(char **input, char *run)
{
	free(input);
	free(run);
	input = NULL;
	run = NULL;
}
/**
 *mem_arr -  fill array
 *@prt: pointer
 *@num: int
 *@run: value of int
 *
 *Return: array
 */
void *mem_arr(void *prt, int num, unsigned int run)
{
	unsigned int i = 0;
	char *j = prt;

	while (i < run)
	{
		*j = num;
		j++;
		i++;
	}
	return (prt);
}
/**
 *my_memcpy - copy memory bytes
 *@tmp: pointer to dest
 *@input: pointer
 *@num: sizw of byte to copy
 *
 *Return: pointer to dest
 */
char *my_memcpy(char *tmp, char *input, unsigned int num)
{
	unsigned int b;

	for (b = 0; b < num; b++)
	{
		tmp[b] = input[b];
	}
	return (tmp);
}
