#include "shell.h"

char *errors_126(char **args);
char *errors_127(char **args);

/**
 * error_126 - Creates an error message for permission denied failures.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */

char *errors_126(char **args)
{
	char *errors, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
	errors = malloc(sizeof(char) * (len + 1));
	if (!errors)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(errors, name);
	_strcat(errors, ": ");
	_strcat(errors, hist_str);
	_strcat(errors, ": ");
	_strcat(errors, args[0]);
	_strcat(errors, ": Permission denied\n");

	free(hist_str);
	return (errors);
}

/**
 * error_127 - Creates an error message for command not found failures.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */

char *errors_127(char **args)
{
	char *errors, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 16;
	errors = malloc(sizeof(char) * (len + 1));
	if (!errors)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(errors, name);
	_strcat(errors, ": ");
	_strcat(errors, hist_str);
	_strcat(errors, ": ");
	_strcat(errors, args[0]);
	_strcat(errors, ": not found\n");

	free(hist_str);
	return (errors);
}
