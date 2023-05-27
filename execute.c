#include "shell.h"

/**
 *handle_signal -  handle ctrl C
 *@check: in line
 *
 * Return: newline character
 */
void handle_signal(int check)
{
/* newline character */
	if (check == SIGINT)
	{
		PRINTF("\n($) ");
	}
}

/**
 *prompt -  display prompt
 */
void prompt(void)
{
	PRINTF("($) ");
}
