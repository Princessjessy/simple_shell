#include "shell.h"
/**
 * my_getline - read imput
 *
 * Return: input on buffer
 */
char *my_getline()
{
	int tmp, tmp2, buffsz = BUF_SIZ;
	char c = 0, *buffer, *buf;

	buffer = malloc(buffsz);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	for (tmp = 0; c != EOF && c != '\n'; tmp++)
	{
		fflush(stdin);
		tmp2 = read(STDIN_FILENO, &c, 1);
		if (tmp2 == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[tmp] = c;
		if (buffer[0] == '\n')
			return (my_new(buffer));
		if (tmp >= buffsz)
		{
			buffer = realloc(buffer, (buffsz + 2));
			if (!buffer)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[tmp] = '\0';
	buf = my_space(buffer);
	free(buffer);
	my_hash(buf);
	return (buf);
}
/**
 * make_env -  env Variables
 * @line: Array to store
 *
 * Return: nothing
 */
void make_env(char **line)
{
	int b;

	for (b = 0; environ[b]; b++)
		line[b] = my_strdup(environ[b]);
	line[b] = NULL;
}

/**
 * env_mem_free - Frees env memory array
 * @input:  Array of Environment variables
 *
 * Return: nothing
 */

void env_mem_free(char **input)
{
	int b;

	for (b = 0; input[b]; b++)
	{
		free(input[b]);
	}
}
