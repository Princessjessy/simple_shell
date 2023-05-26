#include "shell.h"

/**
 *ch_dir - Function to change directories
 *@line: Command line
 *@s: command status.
 *
 *Return: 0  success 1 fails
 */
int ch_dir(char **line, __attribute__((unused))int s)
{
	int change = -1;
	char cwd[PATH_MAX];

	if (line[1] == NULL)
		change = chdir(getenv("HOME"));
	else if (my_strcmp(line[1], "-") == 0)
		change = chdir(getenv("OLDPWD"));
	else
		change = chdir(line[1]);

	if (change == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (change != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 *print_env - Function to print env
 *@line: Line command
 *@c: command status
 *
 *Return: 0 everytime
 */
int print_env(__attribute__((unused)) char **line,
		__attribute__((unused)) int c)
{
	int vau;
	size_t b;

	for (b = 0; environ[b] != NULL; b++)
	{
		vau = my_strlen(environ[b]);
		write(1, environ[b], vau);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);

