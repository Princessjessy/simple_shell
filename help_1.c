#include "shell.h"
/**
 *free_me - function to free memory
 *@imput: pointer to command
 *@run: pointer to line
 *
 *Return: nothing
 */
void free_me(char **imput, char *run)
{
	free(imput);
	free(run);
	imput = NULL;
	run = NULL;
}
/**
 *mem_arr - Function to fill array
 *@prt: pointer
 *@num: int
 *@run: value of int
 *
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
 *@imput: pointer
 *@num: sizw of byte to copy
 *
 *Return: pointer to dest
 */
char *my_memcpy(char *tmp, char *imput, unsigned int num)
{
	unsigned int b;

	for (b = 0; b < num; b++)
	{
		tmp[b] = imput[b];
	}
	return (tmp);
}
