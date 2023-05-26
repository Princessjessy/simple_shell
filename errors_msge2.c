#include "shell.h"

/**
 *exec_cmd - Function to Execute command
 *@imput: Pointer to command
 *@run: pointer to recieved cmd
 *@c: line execute
 *@argv: Shell Argument
 *
 *Return: 1 failed  0  execute
 */
int exec_cmd(char **imput, char *run, int c, char **argv)
{
	int result;
	pid_t pid;

	if (!*imput)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (my_strncmp(*imput, "./", 2) != 0 && my_strncmp(*imput, "/", 1) != 0)
		{
			find_path(imput);
		}
		if (access(imput[0], R_OK) != 0)
		{
			dis_err(input[0], s, argv);
			free_me(input, run);
			exit(127);
		}
		if (execve(*imput, imput, environ) == -1)
			return (2);
		else
			return (0);
	}
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
