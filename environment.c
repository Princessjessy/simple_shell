#include "shell.h"

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */

char **_copyenv(void)
{
	char **new_environm;
	size_t size;
	int index1;

	for (size = 0; environm[size]; size++)
		;

	new_environm = malloc(sizeof(char *) * (size + 1));
	if (!new_environm)
		return (NULL);

	for (index1 = 0; environm[index1]; index1++)
	{
		new_environm[index1] = malloc(_strlen(environm[index1]) + 1);

		if (!new_environm[index1])
		{
			for (index1--; index1 >= 0; index1--)
				free(new_environm[index1]);
			free(new_environm);
			return (NULL);
		}
		_strcpy(new_environm[index1], environm[index1]);
	}
	new_environm[index1] = NULL;

	return (new_environm);
}

/**
 * free_env - Frees the the environment copy.
 */

void free_env(void)
{
	int index1;

	for (index1 = 0; environm[index1]; index1++)
		free(environm[index1]);
	free(environm);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */

char **_getenv(const char *var)
{
	int index1, len;

	len = _strlen(var);
	for (index1 = 0; environm[index1]; index1++)
	{
		if (_strncmp(var, environm[index1], len) == 0)
			return (&environm[index1]);
	}

	return (NULL);
}
