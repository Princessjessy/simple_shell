#include "shell.h"

/**
 * my_new - a string to a new line
 * @str: pointer to the string to be taken to a new line
 *
 * Return: Empty string
 */
char *my_new(char *str)
{
/* empty string */
	free(str);
	return ("\0");
}

/**
 * my_space -  removes whitespaces in string
 * @str: string to be modified
 *
 * Return: modified string
 */

char *my_space(char *str)
{
	int i, j = 0;
	char *tmp;

	tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}
/* modified string */
	for (i = 0; str[i] == ' '; i++)
		;
	for (; str[i + 1] != '\0'; i++)
	{
		tmp[j] = str[i];
		j++;
	}
	tmp[j] = '\0';

	if (tmp[0] == '\0' || tmp[0] == '#')
	{
		free(tmp);
		return ("\0");
	}
	return (tmp);
}

/**
 * my_hash - function that removes everything after a '#'
 * @tmp: pointer to the input buffer
 *
 * Return: nothing
 */

void my_hash(char *tmp)
{
	int b;

	for (b = 0; tmp[b] != '\0'; b++)
	{
		if (tmp[b] == '#' && tmp[b - 1] == ' ' && tmp[b + 1] == ' ')
		{
			tmp[b] = '\0';
		}
	}
}
