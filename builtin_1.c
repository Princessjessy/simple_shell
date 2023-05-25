#include "shell.h"

/**
 * tokenis -   a string into a sequence of token on specified delimiter.
 * @num: the commands number.
 *
 * Return: commands as tokens and NULL if it fails.
 */
char **tokenis(char *num)
{
	int len = 0;
	int weight = 16;
	char **odd;
	char *token;
/* string sequence */
	odd = malloc(weight * sizeof(char *));
	if (odd == NULL)
	{
		free(odd);
		return (NULL);
	}
/* command line */
	token = _strtok(num, " \n");
	while (token != NULL)
	{
		odd[len] = token;
		len++;

		if (len >= weight)
		{
			weight += weight;
			odd = realloc(odd, weight * sizeof(char *));
			if (odd == NULL)
			{
				free(odd);
				return (NULL);
			}
		}
		token = _strtok(NULL, " \n");
	}

	odd[len] = NULL;
	return (odd);
}
