#include "shell.h"

/**
 *run_cmd - Funtion to parse stdin command
 *@line: string parse to command
 *Return: command
 */
char **run_cmd(char *line)
{
	char **imputs, *imput;
	int b, buf = BUF_SIZ;

	if (line[0] == ' ' && line[my_strlen(line)] == ' ')
		exit(0);
	if (!line)
		return (NULL);
	imputs = malloc(sizeof(char *) * buf);
	if (imputs == NULL)
	{
		free(imputs);
		perror("hsh");
		return (NULL);
	}
	imput = my_strtok(line, "\n\t\r\a ");
	for (b = 0; imput; b++)
	{
		imputs[b] = imput;
		imput = my_strtok(NULL, "\n\t\r\a ");
	}
	imputs[b] = NULL;
	return (imputs);
}
