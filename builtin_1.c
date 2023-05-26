#include "shell.h"

/**
 *echo_handler - Builtin echo handler
 *@line: command line
 *@s: command status
 *
 *Return: 1 always
 */
int echo_handling(char **line, int s)
{
	unsigned int pid;
	char *find_path;

	pid = getppid();
	if (my_strncmp(line[1], "$?", 2) == 0)
	{
		dis_int(c);
		PRINTF("\n");
	}
	else if (my_strncmp(line[1], "$$", 2) == 0)
	{
		dis_num(pid);
		PRINTF("\n");
	}
	else if (my_strncmp(line[1], "$PATH", 5) == 0)
	{
		find_path = my_getenv("PATH");
		PRINTF(find_path);
		PRINTF("\n");
		free(find_path);
	}
	else
		return (dis_echo(line));
	return (1);
}
/**
 *echo_history - Function to keep history
 *@run: command line
 *@th: command status
 *
 *Return: Always 0
 */
int echo_histories(__attribute__((unused))char **run,
		__attribute__((unused))int th)
{
	FILE *fe;
	char *c, *imput = NULL;
	char *fname = ".display_history";
	size_t buf = 0;
	int value = 0;

	fe = fopen(fname, "r");
	if (!fe)
		return (-1);
	while ((getline(&imput, &buf, fe)) != -1)
	{
		value++;
		c = my_itoa(value);
		PRINTF(c);
		free(c);
		PRINTF(" ");
		PRINTF(imput);
	}
	if (imput != NULL)
		free(imput);
	fclose(fe);
	return (0);
}
