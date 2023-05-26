#include "shell.h"

/**
 *my_strdup - function that double a string
 *@st: pointer to the string
 *Return: duplicate
 */
char *my_strdup(char *st)
{
	size_t change;
	size_t b;
	char *st2;

	change = my_strlen(st);
	st2 = malloc(sizeof(char) * (change + 1));

	if (st2 == NULL)
		return (NULL);
	for (b = 0; b <= change; b++)
	{
		st2[b] = st[b];
	}
	return (st2);
}
/**
 *my_strncmp - function that compare two strings
 *@str1: pointer to the first string
 *@str2: pointer to the second string
 *@num: value of char compared
 *Return: 0 on success
 */
int my_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t b;

	if (!str1)
		return (-1);
	for (b = 0; b < num && str2[b]; b++)
	{
		if (str1[b] != str2[b])
			return (1);
	}
	return (0);
}
/**
 *my_strchr - function that check char in a string
 *@str: pointer to the string
 *@s: char in the string
 *Return: pointer to the string
 */
char *my_strchr(char *str, char c)
{

	for (; *str != '\0'; str++)
	{
		if (*str == c)
		{
			return (str);
		}
	}
	return (NULL);
}
/**
 * dis_echo - Function for built-in echo function
 * @line: Pointer to command
 * Return: 0 Upon Success -1 Upon Failure
 */

int dis_echo(char **line)
{
	pid_t pid;
	int result;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", line, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &result, WUNTRACED);
		} while (!WIFEXITED(result) && !WIFSIGNALED(result));
	}
	return (1);
}
