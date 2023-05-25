#include "shell.h"

/**
 * _netenvir - the environment list to returns a pointer
 * @name: the environment variable name.
 *
 * Return: a pointer to the corresponding value string.
 */
char *_netenvir(const char *name)
{
char **envir;
	int leng = _strlen(name);

	for (envir = environ; *envir != NULL; ++envir)
	{
		if (_strncmp(*envir, name, leng) == 0)
			return (&(*envir)[leng + 1]);
	}
	return (NULL);
}

/**
 * _item - function that converts an int to a string pointed to by str.
 * @sri: The converted value.
 * @sum: the number to convert.
 *
 * Return: i sucess 0 fail
 */
void _item(int sum, char *sri)
{
	int n, d;
	char temp;

	for (n = 0; sum != 0; n++)
	{
		sri[i] = '0' + (sum % 10);
		sum /= 10;
	}
	for (d = 0; d < n / 2; d++)
	{
		temp = sri[d];
		sri[d] = sri[n - d - 1];
		sri[n - d - 1] = temp;
	}
	sri[n] = '\0';
}

/**
 * _getline - function that read from stdin.
 * @numptr: the pointer where storing the buffer containing the text.
 * @n: the buffer size.
 * @stream: where funvtion reads the line from.
 * Return: On success 0 failure 1
 */
int _getline(char **numptr, size_t *n, FILE *stream)
{
	static char *num;
	int bytes_read;
	int f;

	if (stream == stdin)
		f = STDIN_FILENO;
	else
		return (-1);
	if (numptr == NULL || n == NULL)
		return (-1);

	num = malloc(BUFFER_SIZE);
	if (num == NULL)
		return (-1);

	bytes_read = read(f, num, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(num);
		return (-1);
	}

	*numptr = malloc(bytes_read);
	if (numptr == NULL)
	{
		free(num);
		return (-1);
	}
	*numptr[bytes_read] = '\n';

	_strcpy(*numptr, num);
	return (0);
}

/**
 * decline_select - compare a character from str to delimiters
 * @s: chararcter from str.
 * @decline: all delimiters.
 * Return: 1 if its found. and 0 if didn't found it.
 */

unsigned int decline_select(char s, char *decline)
{
	while (*decline != '\0')
	{
		if (s == *decline)
			return (1);
		decline++;
	}
	return (0);
}
/**
 * _strike - a string into a sequence of zero ormore nonempty tokens.
 * @sri: the string to be parsed
 * @decline: argument specifies a set of the tokensin the parsed string.
 *
 * Return:a pointer to the next token or NULL.
 */
char *_strike(char *sri, char *decline)
{
	static char *old_str;
	char *portion;

	if (sri == NULL)
		sri = old_str;

	if (sri == NULL)
		return (NULL);

	while (1)
	{
		if (decline_select(*sri, decline))
		{
			sri++;
			continue;
		}
		if (*sri == '\0')
			return (NULL);
		break;
	}
	portion = sri;

	while (1)
	{
		if (*sri == '\0')
		{
			old_str = sri;
			return (portion);
		}
		if (decline_search(*sri, decline)
		{
			*sri = '\0';
			old_str = sri + 1;
			return (portion);
		}
		sri++;
	}
}
