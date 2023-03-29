#include "main.h"

/**
 * get_size - determines the size to cast the argument to be printed.
 * @format: a string format for the arguments to be printed.
 * @index: an integer
 * Return: the calculated size.
 */
int get_size(const char *format, int *index)
{
	int i, size;

	i = (*index) + 1;
	size = 0;

	if (format[i] == 'l')
	{
		if (format[i + 1] == 'l')
		{
			size = SIZE_LONG;
			i++;
		}
		else
		{
			size = SIZE_INT;
		}
	}
	else if (format[i] == 'h')
	{
		size = SIZE_SHORT;
	}

	if (size == 0)
		*index = i - 1;
	else
		*index = i;

	return (size);
}
