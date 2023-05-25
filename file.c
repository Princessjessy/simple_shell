#include "shell.h"
/**
 * nor_interaction_mood - the program in the non interactive mode.
 * @progname: program name.
 *
 * Return: newline character
 */
void nor_interaction_mood(char *progname)
{
	char *line;
	char **cmds;
	int err_check = 0;
	int running = 1;
/* newline character */
	while (1)
	{
		line = read_stream();
		cmds = tokeniz(line);
		err_check = excutcmd(cmds);
		if (err_check > 0)
		{
			error(progname, err_check, cmds, running);
		}
	}
	free(line);
	free(cmds);
}
