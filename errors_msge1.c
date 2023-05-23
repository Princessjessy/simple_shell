#include "shell.h"

char *errors_env(char **args);
char *errors_1(char **args);
char *errors_2_exit(char **args);
char *errors_2_cd(char **args);
char *errors_2_syntax(char **args);
/**
 * error_env - Creates an error message for shellby_env errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */

char *errors_env(char **args)
{
	char *errors, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	args--;
	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(errors, name);
	_strcat(errors, ": ");
	_strcat(errors, hist_str);
	_strcat(errors, ": ");
	_strcat(errors, args[0]);
	_strcat(errors, ": Unable to add/remove from environment\n");

	free(hist_str);
	return (errors);
}

/**
 * error_1 - Creates an error message for shellby_alias errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */

char *errors_1(char **args)
{
	char *errors;
	int len;

	len = _strlen(name) + _strlen(args[0]) + 13;
	errors = malloc(sizeof(char) * (len + 1));
	if (!errors)
		return (NULL);

	_strcpy(errors, "alias: ");
	_strcat(errors, args[0]);
	_strcat(errors, " not found\n");

	return (errors);
}

/**
 * error_2_exit - Creates an error message for shellby_exit errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */

char *errors_2_exit(char **args)
{
	char *errors, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
	errors = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(errors, name);
	_strcat(errors, ": ");
	_strcat(errors, hist_str);
	_strcat(errors, ": exit: Illegal number: ");
	_strcat(errors, args[0]);
	_strcat(errors, "\n");

	free(hist_str);
	return (errors);
}

/**
 * error_2_cd - Creates an error message for shellby_cd errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */

char *errors_2_cd(char **args)
{
	char *errors, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
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
	if (args[0][0] == '-')
		_strcat(errors, ": cd: Illegal option ");
	else
		_strcat(errors, ": cd: can't cd to ");
	_strcat(errors, args[0]);
	_strcat(errors, "\n");

	free(hist_str);
	return (errors);
}

/**
 * error_2_syntax - Creates an error message for syntax errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *errors_2_syntax(char **args)
{
	char *errors, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 33;
	errors = malloc(sizeof(char) * (len + 1));
	if (!errors)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(errors, name);
	_strcat(errors, ": ");
	_strcat(errors, hist_str);
	_strcat(errors, ": Syntax error: \"");
	_strcat(errors, args[0]);
	_strcat(errors, "\" unexpected\n");

	free(hist_str);
	return (errors);
}
