#include "shell.h"

int num_len(int num);
char *_itoa(int num);
int create_errors(char **args, int err);

/**
 * num_len - Counts the digit length of a number.
 * @num: The number to measure.
 *
 * Return: The digit length.
 */

int num_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}

/**
 * _itoa - Converts an integer to a string.
 * @num: The integer.
 *
 * Return: The converted string.
 */

char *_itoa(int num)
{
	char *buffer;
	int len = num_len(num);
	unsigned int num1;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);

	buffer[len] = '\0';

	if (num < 0)
	{
		num1 = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = num;
	}

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buffer);
}


/**
 * create_error - Writes a custom error message to stderr.
 * @args: An array of arguments.
 * @err: The error value.
 *
 * Return: The error value.
 */

int create_errors(char **args, int err)
{
	char *errors;

	switch (err)
	{
	case -1:
		errors = errors_env(args);
		break;
	case 1:
		errors = errors_1(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			errors = errors_2_exit(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			errors = errors_2_syntax(args);
		else
			errors = errors_2_cd(args);
		break;
	case 126:
		errors = errors_126(args);
		break;
	case 127:
		errors = errors_127(args);
		break;
	}
	write(STDERR_FILENO, errors, _strlen(errors));

	if (errors)
		free(errors);
	return (err);

}
