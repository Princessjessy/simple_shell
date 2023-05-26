#include "shell.h"
/**
 *my_strcpy - function that copy source
 *@buf: pointer to the destination
 *@snc: pointer to the source
 *
 *Return: char copied
 */
char *my_strcpy(char *buf, char *snc)
{
	int b = 0;

	while (snc[b])
	{
		buf[b] = snc[b];
		b++;
	}
	buf[b] = '\0';
	return (buf);
}
/**
 *my_strcat - function that concat two string
 *@dest: pointer to the first string
 *@str: pointer to the seecond string
 *
 *Return: pointer to string
 */
char *my_strcat(char *dest, char *str)
{
	char *ct = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*str != '\0')
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = '\0';
	return (ct);
/**
 * dis_num - display integers using _putchar function
 * @num: Unsigned integer
 */
void dis_num(unsigned int num)
{
	unsigned int b = num;

	if ((b / 10) > 0)
		dis_num(b / 10);

	_putchar(b % 10 + '0');
}

/**
 * dis_int - display integers using _putchar function
 * @num: Integer
 */

void dis_int(int num)
{
	unsigned int b = num;

	if (num < 0)
	{
		_putchar('-');
		b = -b;
	}
	if ((b / 10) > 0)
		dis_num(b / 10);

	_putchar(b % 10 + '0');
}
