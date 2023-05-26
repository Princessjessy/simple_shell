#include "shell.h"

/**
*my_getline - function that reads input by user
* Return: the input by user on a buffer
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
	for (tmp = 0; s != EOF && c != '\n'; tmp++)
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
			return (my_ent(buffer));
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
 * make_env - Creates env Variables
 * @line: Array to store
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
 * @imput:  Array of Environment variables
 */

void env_mem_free(char **imput)
{
	int b;

	for (b = 0; imput[b]; b++)
	{
		free(imput[b]);
	}
}
