#include "shell.h"

/**
 *find_path -  path for command
 *@command: Pointer to command line
 *
 *Return:; 0 sucess 1 failed
 */
int find_path(char **command)
{
	char *find_p;
	char *total, *cmd;
	struct stat buf;

/* command kine ptr */
	find_p = my_getenv("PATH");
	total = my_strtok(find_p, ":");
	while (total)
	{
		cmd = create_cmd(*command, total);
		if (stat(cmd, &buf) == 0)
		{
			*command = my_strdup(cmd);
			free(cmd);
			free(find_p);
			return (0);
		}
		free(cmd);
		total = my_strtok(NULL, ":");
	}
	free(find_p);
	free(total);
	return (1);
}
