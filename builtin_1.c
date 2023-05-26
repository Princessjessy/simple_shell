#include "shell.h"

/**
 *echo_handler - Builtin echo handler
 *@line: command line
 *@c: command structure
 *
 *Return: 1 sucessful
 */
int echo_handler(char **line, int c)
{
	unsigned int pid;
	char *find_path;
/* builtin command line */
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
 *@ch: command struture
 *
 *Return:  0 sucessful
 */
int echo_history(__attribute__((unused))char **run,
		__attribute__((unused))int ch)
{
	FILE *fi;
	char *c, *input = NULL;
	char *fname = ".display_history";
	size_t buf = 0;
	int value = 0;
/* input file */
	fi = fopen(fname, "r");
	if (!fi)
		return (-1);
	while ((getline(&input, &buf, fi)) != -1)
	{
		value++;
		c = my_itoa(value);
		PRINTF(c);
		free(c);
		PRINTF(" ");
		PRINTF(input);
	}
	if (input != NULL)
		free(input);
	fclose(fi);
	return (0);
}
