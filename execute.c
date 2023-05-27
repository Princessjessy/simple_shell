#include "shell.h"

/**
 *handle_signal - handle ctrl c
 *@check: parse in line
 *
 *Return: newline 
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
