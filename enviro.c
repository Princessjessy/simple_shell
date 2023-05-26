#include "shell.h"
/**
 * my_strtok - function that extracts tokens from a string
 * @st: pointer to the string
 * @tk: pointer to the delimiter
 * Return: pointer to the next token or NULL if none
 */

char *my_strtok(char *st, const char *tk)
{
	static char *t, *c;
	unsigned int b;

	if (st != NULL)
		c = st;
	t = c;
	if (t == NULL)
		return (NULL);
	for (b = 0; t[b] != '\0'; b++)
	{
		if (check_my_delime(t[b], tk) == 0)
			break;
	}
	if (c[b] == '\0' || c[b] == '#')
	{
		c = NULL;
		return (NULL);
	}
	t = c + b;
	c = t;
	for (b = 0; c[b] != '\0'; b++)
	{
		if (check_my_delime(t[b], tk) == 1)
			break;
	}
	if (c[b] == '\0')
		c = NULL;
	else
	{
		c[b] = '\0';
		c = c + b + 1;

		if (*c == '\0')
			c = NULL;
	}
	return (t);
}
