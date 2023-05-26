#include "shell.h"

/**
 *run_cmd - stdin command
 *@line: string parse to command
 *
 *Return: command
 */
char **run_cmd(char *line)
{
	char **inputs, *input;
	int b, buf = BUF_SIZ;
/* strong ptr*/
	if (line[0] == ' ' && line[my_strlen(line)] == ' ')
		exit(0);
	if (!line)
		return (NULL);
	inputs = malloc(sizeof(char *) * buf);
	if (inputs == NULL)
	{
		free(inputs);
		perror("hsh");
		return (NULL);
	}
	input = my_strtok(line, "\n\t\r\a ");
	for (b = 0; input; b++)
	{
		inputs[b] = input;
		input = my_strtok(NULL, "\n\t\r\a ");
	}
	inputs[b] = NULL;
	return (inputs);
}
