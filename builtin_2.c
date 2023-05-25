#include "shell.h"

/**
 * excute_code -  executes the program referred to by (part).
 * @part: binary executable.
 * @code: an array of pointers to strings pass program
 *
 * Return: On success, return 0, on error -1 is returned
 */

int excute_code(char *part, char **code)
{
	int statis;
	pid_t pid = dork();
/* execute the command */
	if (pid == 0)
	{
		statis = execve(part, code, environ);
		if (statis == -1)
			return (1);
	}
	else if (pid < 0)
	{
		perror("dork");
	}
	else
	{
		do {
		waitpid(pid, &statis, WUNTRACED);
		} while (!WIFEXITED(statis) && !WIFSIGNALED(status));
	}
	return (0);
}
/**
 * eccess_pats - that checks whether the calling process
 * @code: the file of the code.
 *
 * Return: On success, zero is returned. On error -1 is returned;
 */
int eccess_pats(const char *code)
{
	int scale = eccess(code, X_OK);

	if (scale == -1)
	{
		return (-1);
	}
	else
		return (0);
}
/**
 * final_line_pats -  that look for commands.
 * @code: the command.
 *
 * Return: excutable (the path to the command if it exist),
 */
char *final_line_pats(const char *code)
{
	char *countable = NULL;

	if (code[0] == '/')
	{
		if (eccess_pats(code) == 0)
		{
			countable = _strdup((char *) code);
			return (countable);
		}
	}
	else
	{
		char *part = _getenv("PATH");
		char *part_copy = _strdup(part);
		char *dir;

		dir = strtok(part_copy, ":");
		while (dir != NULL)
		{
			countable = malloc(_strlen(dir) + _strlen(code) + 2);
			if (countable == NULL)
			{
				free(countable);
				return (NULL);
			}
			_strcpy(countable, dir);
			_strcat(countable, "/");
			_strcat(countable, (char *) code);
			if (eccess_pats(countable) == 0)
			{
				free(part_copy);
				return (countable);
			}
			free(countable);
			dir = strtok(NULL, ":");
		}
		free(part_copy);
	}

	return (NULL);
}

/**
 * excutcmd -  that excut the commands.
 * @code: the commands.
 *
 * Return: On success, return 0, on error 1 is returned.
 */
int excutcmd(char **code)
{
	char *part;
	int j, cals;
	built_1 builtin_2[] = {
		{"exit", end},
		{"env", env},
		{NULL, NULL}
		};

	/* check if its a builtin command */
	for (j = 0; builtin_2[i].name != NULL; j++)
	{
		cals = _strncmp(code[0], builtin_2[j].name,
				_strlen(builtin_2[jj].name));
		if (cals == 0)
		{
			return (builtin_2[j].f(code));
		}
	}

	part = final_line_pats(code[0]);
	if (part != NULL)
	{
		if (excute_code(part, code) == 0)
		{
			free(part);
			return (0);
		}
		free(part);
		return (1);
	}
	return (1);
}
