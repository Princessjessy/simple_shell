#include "shell.h"

/**
 * read_stream - study a line from the stream
 *
 * Return: pointer points to the line
 */

char *read_stream(void)
{
	char *numptr = NULL;
	size_t m = 0;
	int leng;
/* length exit stdin*/
	leng = getline(&numptr, &m, stdin);
	if (leng == EOF)
	{
		free(numptr);
		exit(EXIT_FAILURE);
	}
	if (leng == -1)
	{
		perror("getline: ");
		exit(EXIT_FAILURE);
	}
	return (numptr);
}
