#include "shell.h"

/**
 * num_result - function that check for spaces.
 * @num: read line.
 *
 * Return: 0 foound a character, 1 Null num.
 */

int num_result(char *num)
{
int j;

for (j = 0; num[j] != '\n'; j++)
{
if (num[j] != ' ' && num[j] != '\t')
{
return (0);
}
}
return (1);
}
/**
 * read_stdin - read a line from the stdin.
 *
 * Return: pointer points to the line.
 */
char *read_stdin(void)
{
char *numptr = NULL;
size_t m = 0;
int leng;
leng = getline(&numptr, &n, stdin);
if (leng == EOF)
{
/*end of file condition (Ctrl+D)*/
write(STDOUT_FILENO, "\n", 1);
free(numptr);
exit(EXIT_SUCCESS);
}
if (leng == -1)
{
perror("getline: ");
exit(EXIT_FAILURE);
}
if (num_result(numptr) == 1)
{
free(numptr);
/*  empty line (nothing been entred)*/
return (NULL);
}
return (numptr);
}
