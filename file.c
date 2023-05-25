#include "shell.h"

/**
 * nor_interaction_mood - the conversation of computer through keyboard.
 *
 * Return: 0 non_interaction 1 likewise
 */

void nor_interaction_mood(void)
{
char *num;
char **code;
int i = 0;
int j = 1;
while (1)
{
num = read_stream();
code = tokeniz(num);
i = excutcmd(code);
if (i > 0)
{
error(i, code, j;
}
}
free(num);
free(code);
}
