#include "shell.h"

int token_len(char *str, char *delim);
int count_token(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * token_len - Locates the delimiter index marking the end
 *             of the first token contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the intitial token pointed to be str.
 */

int token_len(char *str, char *delim)
{
	int index1 = 0, len = 0;

	while (*(str + index1) && *(str + index1) != *delim)
	{
		len++;
		index1++;
	}

	return (len);
}

/**
 * count_tokens - Counts the number of delimited
 *                words contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */

int count_token(char *str, char *delim)
{
	int index1, token = 0, len = 0;

	for (index1 = 0; *(str + index1); index1++)
		len++;
//adding parameter//
	for (index1 = 0; index1 < len; index1++)
	{
		if (*(str + index1) != *delim)
		{
			token++;
			index1 += token_len(str + index1, delim);
		}
	}
	return (token);
}

/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */

char **_strtok(char *line, char *delim)
{
	char **ptr;
	int index1 = 0, token, t, letters, l;

	token = count_token(line, delim);
	if (token == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (token + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < token; t++)
	{
		while (line[index1] == *delim)
			index1++;

		letters = token_len(line + index1, delim);

		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (index1 -= 1; index1 >= 0; index1--)
				free(ptr[index1]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = line[index1];
			index1++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
