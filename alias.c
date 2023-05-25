#include "shell.h"
/**
 * signal_handling - function that terminal signals.
 * @signal_num: signal number.
 *
 * Return: newline character
 */
void signal_handling(int signal_num)
{
	(void)signal_num;
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}
/**
 * interaction_mood - the program in interactive mode.
 * @progname: program name.
 *
 * Return: 0 sucess 1 fail
 */
void interaction_mood(char *progname)
{
	char *line;
	char **cmds;
	int err_check = 0;
	int running = 1;

	signal(SIGINT, signal_handler);
	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
		line = read_stdin();
		if (line != NULL)
		{
			cmds = tokeniz(line);
			err_check = excutcmd(cmds);
			if (err_check > 0)
			{
				error(progname, err_check, cmds, running);
			}
			free(line);
			free(cmds);
		}
		running++;
	}
	free(line);
}
