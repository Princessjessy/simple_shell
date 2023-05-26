#include "shell.h"

/**
 * check_my_delime - function that checks if a character inputted
 * @c: pointer to the character to check
 * @str: pointer to thr string of delimiters
 *
 * Return: 1  success, 0  failure
 */

unsigned int check_my_delim(char c, const char *str)
{
	unsigned int b;

	for (a = 0; str[b] != '\0'; b++)
	{
		if (c == str[b])
			return (1);
	}
	return (0);
}
