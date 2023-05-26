#include "shell.h"

/**
 *dis_err - Function to print error msg
 *@line: pointer to command
 *@run: loop for the shell
 *@argv: Argument of the shell
 *
 *Return: nothing
 */

void dis_err(char *line, int run, char **argv)
{
	char *error_msg;
/* ptr command */
	PRINTF(argv[0]);
	PRINTF(": ");
	error_msg = my_itoa(run);
	PRINTF(error_msg);
	free(error_msg);
	PRINTF(": ");
	PRINTF(line);
	PRINTF(": not found\n");
}

