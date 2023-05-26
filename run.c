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
 *Return: 1 success 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *my_strncpy -  copy a string
 *@dst: pointer to a string
 *@sc: pointer to second string
 *@n: integer
 *
 *Return: string copied
 */
char *my_strncpy(char *dst, char *sc, int n)
{
	int b = 0;

	while (b < n && *(sc + b))
	{
		*(dst + b) = *(sc + b);
		b++;
	}
	while (b < n)
	{
		*(dst + b) = '\0';
		b++;
	}
	return (dst);
}
/**
 *my_puts -  print a string
 *@stri: pointer to the string
 *
 *Return: void
 */
void my_puts(char *stri)
{
	int b;

	for (b = 0; stri[b] != '\0'; b++)
	{
		_putchar(stri[b]);
	}
	_putchar('\n');
}
/**
 *my_atoi - function to convert string to int
 *@st: pointer to a string
 *Return: the int value
 */
int my_atoi(char *str)
{
	int a;
	int x = 0;
	int y = -1;
	int z = 0;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (str[a] == '-')
			y = y * -1;
		if (str[a] >= '0' && str[a] <= '9')
		{
			x = x * 10;
			x -= (str[a] - '0');
			z = 1;
		}
		else if (z == 1)
			break;
	}
	x = y * x;
	return (x);
}
