#include "shell.h"

/**
 *my_getenv - Function to get eniron
 *@env: pointer to environ
 *
 *Return: NULL
 */
char *my_getenv(char *env)
{
	size_t env_len, total_len;
	char *total;
	int i, j, k;

	env_len = my_strlen(env);
	for (i = 0; environ[i]; i++)
	{
		if (my_strncmp(env, environ[i], env_len) == 0)
		{
			total_len = my_strlen(environ[i]) - env_len;
			total = malloc(sizeof(char) * total_len);
			if (total == NULL)
			{
				free(total);
				perror("unable to alloc");
				return (NULL);
			}
			j = 0;
			for (k = env_len + 1; environ[i][k]; k++, j++)
			{
				total[j] = environ[i][k];
			}
			total[j] = '\0';
			return (total);
		}
	}
	return (NULL);
}
/**
 *create_cmd -  create command
 *@input: Pointer to commandd
 *@total: pointer to Directory
 *
 *Return: path or NULL on failure
 */
char *create_cmd(char *input, char *total)
{
	char *token;
	size_t run;
/* create command */
	run = my_strlen(total) + my_strlen(input) + 2;
	token = malloc(sizeof(char) * run);
	if (!token)
	{
		free(token);
		return (NULL);
	}
	memset(token, 0, run);

	token = my_strcat(token, total);
	token = my_strcat(token, "/");
	token = my_strcat(token, input);

	return (token);
}
