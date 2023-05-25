#include "shell.h"
/**
 * line_check - function that check for spaces.
 * @line: read line.
 *
 * Return: 0 foound a character, 1 Null line.
 */
int line_check(char *line)
{
	int j;

	for (j = 0; line[j] != '\n'; j++)
	{
		if (line[j] != ' ' && line[j] != '\t')
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
	char *lineptr = NULL;
	size_t n = 0;
	int len;

	len = getline(&lineptr, &n, stdin);
	if (len == EOF)
	{
		/* in case of “end of file” condition (Ctrl+D)*/
		write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	if (len == -1)
	{
		perror("getline: ");
		exit(EXIT_FAILURE);
	}

	if (line_check(lineptr) == 1)
	{
		free(lineptr);
		/* in case of empty line (nothing been entred)*/
		return (NULL);
	}

	return (lineptr);
}
