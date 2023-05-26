#include "shell.h"

/**
 *builtin_val - Check Builtin cmd
 *@line: command line
 *
 *Return: O  Success  1  failure
 */
int builtin_val(char **line)
{
	builtincmd functions[] = {
		{"cd", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int b = 0;
/* built_in check */
	if (*line == NULL)
		return (-1);
	while ((functions + b)->cmd)
	{
		if (my_strcmp(line[0], (functions + b)->cmd) == 0)
			return (0);
		b++;
	}
	return (-1);
}
/**
 *process_builtin - Handle builtin
 *@line: Command line
 *@c: Command struture
 *
 *Return: 0 success 1  failure
 */

int process_builtin(char **line, int c)
{
	builtincmd run_builtin[] = {
		{"cd", ch_dir},
		{"env", print_env},
		{"echo", echo_handler},
		{"history", echo_history},
		{NULL, NULL}
	};
	int b = 0;

	while ((run_builtin + b)->cmd)
	{
/* built_in handling */
		if (my_strcmp(line[0], (run_builtin + b)->cmd) == 0)
		{
			return ((run_builtin + b)->func(line, c));
		}
		b++;
	}
	return (-1);
}
