#include "shell.h"

/**
 *my_intlen - function to get the lenght of int
 *@m: value of the lenght
 *
 *Return: lenght
 */
int my_intlen(int m)
{
	int change = 0;

	while (m != 0)
	{
		change++;
		m /= 10;
	}
	return (change);
}
/**
 *my_arr_rev - function to reverse array
 *@ar: pointer to the array
 *@m: lenght of the array
 */
void my_arr_rev(char *ar, int m)
{
	char buf;
	int b;

	for (b = 0; b < (m / 2); b++)
	{
		buf = ar[b];
		ar[b] = ar[(m - 1) - b];
		ar[(m - 1) - b] = buf;
	}
}
/**
 *my_itoa - a function that convert int to char
 *@num: the int to convert
 *
 *Return: pointer to char
 */
char *my_itoa(unsigned int num)
{
	int change = 0;
	int b = 0;
	char *str;

	change = my_intlen(num);
	str = malloc(change + 2);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	while (num / 10)
	{
		str[b] = (num % 10) + '0';
		num /= 10;
		b++;
	}
	str[b] = (num % 10) + '0';
	my_arr_rev(str, change);
	str[b + 1] = '\0';
	return (str);
}
/**
 *my_isalpha - function that check for alphabet
 *@c: string to be checked
 *Return: 1 or 0
 */
int my_isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 *my_strcmp - function that compare string
 *@str1: first string
 *@str2: second string
 *
 *Return: always 0
 */
int my_strcmp(char *str1, char *str2)
{
	int b, change1, change2, tmp = 0;

	change1 = my_strlen(str1);
	change2 = my_strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (change1 != change2)
		return (1);
	for (b = 0; str1[b]; b++)
	{
		if (str1[b] != str2[b])
		{
			tmp = str1[b] - str2[b];
			break;
		}
		else
			continue;
	}
	return (tmp);
}
