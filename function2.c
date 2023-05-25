#include "shell.h"

/**
 * _sridup -  pointer to a newly allocated space of the string given as a parameter.
 * @sri: string given as a parameter.
 *
 * Return: NULL if str = NULL and On success returns a pointer to
 */

char *_sridup(char *sri)
{
	char *newstr;
	int leng;
	int j;


	if (sri == NULL)
	{
		return (NULL);
	}
	else
	{
		leng = srileng(sri);
		newstr = malloc((sizeof(char) * leng) + 1);
		if (newstr == NULL)
		{
			free(newstr);
			return (NULL);
		}
		for (j = 0; j < leng; j++)
			newstr[j] = sri[j];
		newstr[leng] = '\0';
	}
	return  (newstr);
}

/**
 * _strine - function that returns the length of a string.
 * @c: string.
 * 
 * Return: length of a string
 */
int _strine(const char *c)
{
	int leng = 0;

	while (c[leng] != '\0')
		leng++;
	return (leng);
}

/**
 * _strncode - function that compares two strings tell a specific index.
 * @sri1: first string
 * @sri2: second string
 * @n: index
 * Return: return 0 if strings are equal, and -1 if its not.
 */
int _strncode(const char *sri1, const char *sri2, int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		if (sri1[i] == sri2[i])
		{
			continue;
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}
/**
 * _strcmds - function appends the src string to the dest string
 * @test: first string
 * @snc: second string
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcmds(char *test, char *snc)
{
	int j = 0;
	int r = _strlen(test);

	while (*(snc + j) != '\0')
	{
		*(test + (r + j)) = *(snc + j);
		j++;
	}
	*(test + (r + j)) = '\0';
	return (test);
}
/**
 * *_strcopy -  copies the string pointed to by src including the
 * terminating null byte (\0), to the buffer pointed to by dest.
 * @test: copy to
 * @snc: copy from
 * Return: the pointer to dest
 */
char *_strcopy(char *test, char *snc)
{
	int j = -1;

	do {
		j++;
		*(test + j) = *(snc + j);
	} while (*(snc + j) != '\0');
	return (test);
}
