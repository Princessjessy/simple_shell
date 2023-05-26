#include "shell.h"

/**
 *handle_signal - Function to handle ctrl C
 *@result: parse in line
 */
void handle_signal(int result)
{
	if (result == SIGINT)
	{
		PRINTF("\n($) ");
	}
}

/**
 *prompt - function to display prompt
 */
void prompt(void)
{
	PRINTF("($) ");
}
