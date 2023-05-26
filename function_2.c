#include "shell.h"
/**
 * my_strtok -  extracts tokens from a string
 * @st: pointer to the string
 * @tk: pointer to the delimiter
 *
 * Return: pointer to the next token or NULL if none
 */

char *my_strtok(char *st, const char *tk)
{
	static char *a, *b;
	unsigned int i;

	if (st != NULL)
		b = st;
	a = b;
	if (a == NULL)
		return (NULL);
	for (i = 0; a[i] != '\0'; i++)
	{
		if (check_my_delim(a[i], tk) == 0)
			break;
	}
	if (b[i] == '\0' || b[i] == '#')
	{
		b = NULL;
		return (NULL);
	}
	a = b + i;
	b = a;
	for (i = 0; b[i] != '\0'; i++)
	{
		if (check_my_delim(b[i], tk) == 1)
			break;
	}
	if (b[i] == '\0')
		b = NULL;
	else
	{
		b[i] = '\0';
		b = b + i + 1;

		if (*b == '\0')
			b = NULL;
	}
	return (a);
}
