#include "shell.h"

/**
 *free_me - function to free memory
 *@input: pointer to command
 *@run: pointer to line
 */
void free_me(char **input, char *run)
{
	free(input);
	free(run);
	input = NULL;
	run = NULL;
}
/**
 *mem_arr - Function to fill array
 *@prt: pointer
 *@num: int
 *@run: value of int
 *Return: filled arr
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
 *my_memcpy - function to copy memory bytes
 *@tmp: pointer to dest
 *@input: pointer
 *@num: sizw of byte to copy
 *Return: pointer to dest
 */
char *my_memcpy(char *tmp, char *input, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
	{
		tmp[i] = input[i];
	}
	return (tmp);
}
