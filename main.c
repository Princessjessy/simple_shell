#include "shell.h"

/**
 *main - Shell main function
 *@argc: Count arguments
 *@argv: Argument array
 *
 *Return: return command
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *run, **line, **parse;
	int value = 0, i, k = 1, c = 0;
/* agrument command  */
	if (argv[1])
	signal(SIGINT, handle_signal);
	while (k)
	{
/* interactive mood */
		value++;
		if (isatty(STDIN_FILENO))
			prompt();
		run = my_getline();
		if (run[0] == '\0')
			continue;
		dis_history(run);
		parse = sep_handler(run);
		for (i = 0; parse[i] != NULL; i++)
		{
			line = run_cmd(parse[i]);
			if (my_strcmp(line[0], "exit") == 0)
			{
				free(parse);
				my_exit(line, run, argv, k, c);
				/* exit command */
			}
			else if (builtin_val(line) == 0)
			{
				c = process_builtin(line, c);
				free(line);
				continue;
			}
			else
				c = exec_cmd(line, run, c, argv);
			free(line);
		}
		free(run);
		free(parse);
		wait(&c);
	}
	return (c);
}
