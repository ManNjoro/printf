#include "main.h"

/**
 * get_size - determines the size to cast the argument to be printed.
 * @format: a string format for the arguments to be printed.
 * @index: an integer
 * Return: the calculated size.
 */
int get_size(const char *format, int *index)
{
	int i, len_mod;

	i = (*index) + 1;
	len_mod = 0;

	if (format[i] == 'l')
		len_mod = LONG_INT;
	else if (format[i] == 'h')
		len_mod = SHORT_INT;

	if (len_mod == 0)
		*index = i - 1;
	else
		*index = i;

	return (len_mod);
}
