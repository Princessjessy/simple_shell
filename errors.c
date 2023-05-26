#include "shell.h"

/**
 *my_exit - Functionn to Exit shell
 *@line: Command line
 *@run: Command from User
 *@argv: Arguments
 *@n: Count number of exec
 *@s: Exit
 *
 * Return: nothing
 */

void my_exit(char **line, char *run, char **argv, int n, int s)
{
	int result, b = 0;

	if (line[1] == NULL)
	{
		free(run);
		free(line);
		exit(s);
	}
	while (line[1][b])
	{
		if (my_isalpha(line[1][b++]) != 0)
		{
			my_perror(argv, n, line);
			free(run);
			free(line);
			exit(2);
		}
		else
		{
/* agrument command line */
			result = my_atoi(line[1]);
			if (result == 2)
			{
				my_perror(argv, n, line);
				free(run);
				free(line);
				exit(result);
			}
			free(run);
			free(line);
			exit(result);
		}
	}
}
