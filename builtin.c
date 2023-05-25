#include "shell.h"
#include <ctype.h>

/**
 * over -  process termination and exit the program write exit status on success
 * @code: normal process.
 *
 * Return: On Success nothing in failure error
 */

int over(char **code)
{
	if (code[1] != NULL)
	{
		int n = atoi(codde[1]);

		if (n == 0 && *code[1] != '0')
			return (2);
		free(code);
		exit(n);
	}
	free(code);
	exit(EXIT_SUCCESS);
}
/**
 * env - function that Display environment variables.
 * @code: the env command.
 * Return: 0 àn success.
 */
int env(char **code)
{
	int j;
	char *env_var;
	char *vars[] = {"USER", "LANGUAGE", "SESSION", "COMPIZ_CONFIG_PROFILE",
		"SHLVL", "HOME", "C_IS", "DESKTOP_SESSION",
		"LOGNAME", "TERM", "PATH", "DISPLAY", NULL};

	for (j = 0; vars[j] != NULL; j++)
	{
		env_var = _getenv(vars[i]);
		if (env_var != NULL)
		{
			write(STDOUT_FILENO, vars[i], _strlen(vars[i]));
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, env_var, _strlen(env_var));
			write(STDOUT_FILENO, "\n", 1);

		}
	}
	*code = NULL;
	return (0);
}
