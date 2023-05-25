#include "shell.h"

/**
 * main - run the program.
 *
 * Return: 0 always.
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interaction_mood();
	}
	else
	{
		nor_interaction_mood();
	}
	return (0);
}
