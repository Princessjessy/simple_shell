#include "shell.h"

/**
 * check_my_delim - function that checks if a character inputted
 * by user matches any character
 * @s: pointer to the character to check
 * @str: pointer to thr string of delimiters
 *
 * Return: 1  success, 0  failure
 */

unsigned int check_my_delim(char s, const char *str)
{
	unsigned int b;

	for (b = 0; str[b] != '\0'; b++)
	{
		if (s == str[b])
			return (1);
	}
	return (0);
}

