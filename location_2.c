#include "shell.h"

/**
 *my_intlen - function to get the lenght of int
 *@n: value of the lenght
 *
 *Return: lenght
 */
int my_intlen(int n)
{
	int count = 0;

	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}
/**
 *my_arr_rev -  reverse array
 *@ar: pointer to the array
 *@m: lenght of the array
 */
void my_arr_rev(char *ar, int m)
{
	char buf;
	int b;

	for (b = 0; a < (m / 2); b++)
	{
		buf = ar[b];
		ar[b] = ar[(m - 1) - b];
		ar[(m - 1) - b] = buf;
	}
}
/**
 *my_itoa - a convert int to char
 *@num: the int to convert
 *
 *Return: pointer to char
 */
char *my_itoa(unsigned int num)
{
	int count = 0;
	int b = 0;
	char *str;

	count = my_intlen(num);
	str = malloc(count + 2);
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
	my_arr_rev(str, count);
	str[b + 1] = '\0';
	return (str);
}
/**
 *my_isalpha -  check for alphabet
 *@s: string to be checked
 *
 *Return: 1 0
 */
int my_isalpha(int s)
{
	if (((s >= 97) && (s <= 122)) || ((s >= 65) && (s <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 *my_strcmp - compare string
 *@str1: first string
 *@str2: second string
 *
 *Return: always 0
 */
int my_strcmp(char *str1, char *str2)
{
	int b, count1, count2, tmp = 0;

	count1 = my_strlen(str1);
	count2 = my_strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (count1 != count2)
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
