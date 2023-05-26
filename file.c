#include "shell.h"

/**
 *exec_cmd - Function to Execute command
 *@input: Pointer to command
 *@run: pointer to recieved cmd
 *@c: line execute
 *@argv: Shell Arguments
 *
 *Return: 1  fail  0  execute
 */
int exec_cmd(char **input, char *run, int c, char **argv)
{
	int result;
	pid_t pid;

	if (!*input)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (my_strncmp(*input, "./", 2) != 0 && my_strncmp(*input, "/", 1) != 0)
		{
			find_path(input);
		}
		if (access(input[0], R_OK) != 0)
		{
			dis_err(input[0], c, argv);
			free_me(input, run);
			exit(127);
		}
		if (execve(*input, input, environ) == -1)
			return (2);
		else
			return (0);
	}
/* agrument command line */
	wait(&result);
	if (WIFEXITED(result))
	{
		if (WEXITSTATUS(result) == 127)
			return (127);
		else if (WEXITSTATUS(result) == 0)
			return (0);
		else if (WEXITSTATUS(result) == 2)
			return (2);
	}
	return (127);
}
