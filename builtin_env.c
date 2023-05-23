#include "shell.h"

int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);

/**
 * shellby_env - Prints the current environment.
 * @args: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 * abdool and ebube
 * Return: If an error occurs - -1.
 *	   Otherwise - 0.
 *
 * Description: Prints one variable per line in the
 *              format 'variable'='value'.
 */

int shellby_env(char **args, char __attribute__((__unused__)) **front)
{
	int index1;
	char nc = '\n';

	if (!environm)
		return (-1);

	for (index1 = 0; environm[index1]; index1++)
	{
		write(STDOUT_FILENO, environm[index1], _strlen(environm[index1]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}

/**
 * shellby_setenv - Changes or adds an environmental variable to the PATH.
 * @args: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 * Description: args[1] is the name of the new or existing PATH variable.
 *              args[2] is the value to set the new or changed variable to.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */

int shellby_setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **new_environ, *new_value;
	size_t size;
	int index1;

	if (!args[ 0] || !args[1])
		return (create_error(args, -1));

	new_value = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_value)
		return (create_error(args, -1));
	_strcpy(new_value, args[0]);
	_strcat(new_value, "=");
	_strcat(new_value, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}
	for (size = 0; environm[size]; size++)
		;

	new_environm = malloc(sizeof(char *) * (size + 2));
	if (!new_environm)
	{
		free(new_value);
		return (c   reate_error(args, -1));
	}

	for (index1 = 0; environm[index1]; index1++)
		new_environm[index1] = environm[index1];

	free(environm);
	environ = new_environm;
	environm[index1] = new_value;
	environm[index1 + 1] = NULL;

	return (0);
}

/**
 * shellby_unsetenv - Deletes an environmental variable from the PATH.
 * @args: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 * Description: args[1] is the PATH variable to remove.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */

int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var, **new_environm;
	size_t size;
	int index1, index2;

	if (!args[0])
		return (create_error(args, -1));
	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);

	for (size = 0; environm[size]; size++)
		;

	new_environm = malloc(sizeof(char *) * size);
	if (!new_environm)
		return (create_error(args, -1));

	for (index1 = 0, index2 = 0; environm[index1]; index1++)
	{
		if (*env_var == environm[index1])
		{
			free(*env_var);
			continue;
		}
		new_environm[index2] = environm[index1];
		index2++;
	}
	free(environn);
	environm = new_environm;
	environm[size - 1] = NULL;

	return (0);
}
