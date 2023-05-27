#include "shell.h"

/**
 *my_strdup - double a string
 *@str: pointer to the string
 *
 *Return: duplicate
 */
char *my_strdup(char *str)
{
	size_t count;
	size_t b;
	char *st2;

	count = my_strlen(str);
	st2 = malloc(sizeof(char) * (count + 1));

	if (st2 == NULL)
		return (NULL);
	for (b = 0; b <= count; b++)
	{
		st2[b] = str[b];
	}
	return (st2);
}
/**
 *my_strncmp -  compare two strings
 *@str1: pointer to the first string
 *@str2: pointer to the second string
 *@num: value of char compared
 *
 *Return: 0 success
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
 *my_strchr - char in a string
 *@str: pointer to the string
 *@s: char in the string
 *
 *Return: pointer to the string
 */
char *my_strchr(char *str, char s)
{

	for (; *str != '\0'; str++)
	{
		if (*str == s)
		{
			return (str);
		}
	}
	return (NULL);
}
/**
 * dis_echo - Function for built-in echo function
 * @line: Pointer to command
 *
 * Return: 0  Success -1  Failure
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
