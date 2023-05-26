#include "shell.h"

/**
 *builtin_val - Check Builtin cmd
 *@line: command line
 *
 *Return: O on Success 1 on failure
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
 *@s: Command status
 *
 *Return: 0 success  1  failure
 */
int process_builtin(char **line, int s)
{
	builtincmd run_builtin[] = {
		{"cd", ch_dir},
		{"env", print_env},
		{"echo", echo_handling},
		{"history", echo_histories},
		{NULL, NULL}
	};
	int b = 0;

	while ((run_builtin + b)->cmd)
	{

		if (my_strcmp(line[0], (run_builtin + b)->cmd) == 0)
		{
			return ((run_builtin + b)->func(line, s));
		}
		b++;
	}
	return (-1);
}
