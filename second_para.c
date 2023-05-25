#include "shell.h"
/**
 * programmer - that look for the program name.
 *
 * Return: the program name in success.
 */
char *programmer(void)
{
	char *progess = NULL;
	char buffer[BUFFER_SIZE], pid[MAX_NUM], procpath[MAX_LENGHT] = "/proc/";
	int f;

	_itoa(getpid(), pid);
	_strcat(procpath, pid);
	_strcat(procpath, "/cmdline");

	fp = open(procpath, O_RDONLY);
	if (f != -1)
	{
		int b = read(fp, buffer, sizeof(progess));

		if (b != -1)
		{
			progess = malloc(nb * sizeof(char) + 1);
			strncpy(progess, buffer, b);
			progess[b] = '\0';
			close(f);
			return (progess);
		}
		close(fp);
	}
	return (NULL);
}

/**
 * error -  handle the commands errors.
 * @statis: statis value.
 * @k: the command.
 * @j: the number of command been running.
 * Description: the statis value define the error should prompt
 * Return: 1 command error 2 exit error
 */
void error(int statis, char **k, int j)
{
	char *progess = programmer();
	char arrun[MAX_NUM];

	_itoa(j, arrun);
	write(STDOUT_FILENO, progess, _strlen(progess));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, arrun, _strlen(arrun));
	write(STDOUT_FILENO, ": ", 2);

	if (statis == 1)
	{
		perror(*k);
	}
	else if (statis == 2)
	{
		char exit_errs[] = "exit: Illegal number: ";

		write(STDOUT_FILENO, exit_errs, _strlen(exit_errs));
		write(STDOUT_FILENO, s[1], _strlen(s[1]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(progess);

}
