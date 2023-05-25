#include "shell.h"

/**
 * sigmode -  signal ctrl+c
 * @signal_dig: The signal number
 * Return: newline character
 */

void sigmode(int signal_dig)
{
	(void)signal_dig;
	/* newline character*/
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}
/**
 * interaction_mood - the interaction of computer through keyboard.
 * Return: if 1 interaction mood 0 likewise.
 */
void interaction_mood(void)
{
	char *num;
	char **code;
	int i = 0;
	int j = 1;

	signal(SIGINT, sigmode);
	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
		num = read_stdin();
		if (num != NULL)
		{
			/* errors in command*/
			code = tokeniz(num);
			i = excutcmd(code);
			if (i > 0)
			{
				error(i, code, j);
			}
			free(num);
			free(code);
		}
		j++;
	}
	free(num);
}
