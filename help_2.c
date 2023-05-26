#include "shell.h"

/**
 *my_strlen - function to count string lenght
 *@str: string pointer
 *
 *Return: lenght
 */

int my_strlen(char *str)
{
	int b;

	for (b = 0; str[b] != '\0'; b++)
	{
		continue;
	}
	return (b);
}
/**
 *_putchar - writes the character c to stdout
 *@c: The character to print
 *
 *Return: On success 1.
 */
int _putchar(char s)
{
	return (write(1, &s, 1));
}
/**
 *my_strncpy - function to copy a string
 *@dest: pointer to a string
 *@snc: pointer to second string
 *@n: integer
 *
 *Return: string copied
 */
char *my_strncpy(char *dest, char *snc, int n)
{
	int b = 0;

	while (b < n && *(snc + b))
	{
		*(dest + b) = *(snc + b);
		b++;
	}
	while (b < n)
	{
		*(dest + b) = '\0';
		b++;
	}
	return (dest);
}
/**
 *my_puts - function to print a string
 *@str: pointer to the string
 *
 *Return: void
 */
void my_puts(char *str)
{
	int b;

	for (b = 0; str[b] != '\0'; b++)
	{
		_putchar(str[b]);
	}
	_putchar('\n');
}
/**
 *my_atoi - function to convert string to int
 *@st: pointer to a string
 *
 *Return: the int value
 */
int my_atoi(char *str)
{
	int j;
	int u = 0;
	int v = -1;
	int w = 0;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] == '-')
			v = v * -1;
		if (str[j] >= '0' && str[j] <= '9')
		{
			u = u * 10;
			u -= (str[j] - '0');
			w = 1;
		}
		else if (w == 1)
			break;
	}
	u = v * u;
	return (u);
}
