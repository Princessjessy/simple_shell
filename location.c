#include "shell.h"

/**
 *my_calloc - memory allocator
 *@value: size of memory
 *
 *Return: pointer
 */
void *my_calloc(unsigned int value)
{
	unsigned int b;
	char *tmp;

	if (value == 0)
		return (NULL);
	tmp = malloc(value);
	if (!tmp)
		return (NULL);
	for (b = 0; b < value; b++)
	{
		tmp[b] = '\0';
	}
	return (tmp);
}
/**
 *my_realloc - memory allocator
 *@point: pointer value
 *@old_c: current memory size
 *@new_c: new memory size
 *
 *Return: pointer new memory allocated
 */
void *my_realloc(void *point, unsigned int old_c, unsigned int new_c)
{
	void *output;

	if (new_c == old_c)
		return (point);
	if (new_c == 0 && point)
	{
		free(point);
		return (NULL);
	}
	output = malloc(new_c);
	if (!output)
	{
		free(output);
		return (NULL);
	}
	if (!point)
	{
		mem_arr(output, '\0', new_c);
		free(point);
	}
	else
	{
		my_memcpy(output, point, old_c);
		free(point);
	}
	return (output);
}
