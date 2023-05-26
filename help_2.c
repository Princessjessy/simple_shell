#include "shell.h"

/**
 *my_strcpy - copy source
 *@buf: pointer to the destination
 *@sc: pointer to the source
 *
 *Return: char copied
 */
char *my_strcpy(char *buf, char *sc)
{
	int b = 0;

	while (sc[b])
	{
		buf[b] = sc[b];
		b++;
	}
	buf[b] = '\0';
	return (buf);
}
/**
 *my_strcat -  concat two string
 *@dest: pointer to the first string
 *@sr: pointer to the seecond string
 *
 *Return: pointer to string
 */
char *my_strcat(char *dest, char *sr)
{
	char *ct = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*sr != '\0')
	{
		*dest = *sr;
		dest++;
		sr++;
	}
	*dest = '\0';
	return (ct);
}
/**
 * dis_num - integers using _putchar function
 * @num: Unsigned integer
 *
 * Return: nothing
 */
void dis_num(unsigned int num)
{
	unsigned int b = num;

	if ((b / 10) > 0)
		dis_num(b / 10);

	_putchar(b % 10 + '0');
}

/**
 * dis_int -  integers using _putchar function
 * @num: Integer
 *
 * Return: nothing 
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
