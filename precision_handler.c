#include "main.h"

/**
 * get_precision - calculate the precision of the argument to be printed.
 * @format: a string format for the arguments to be printed.
 * @index: a pointer to an int.
 * @args: a va_list type argument.
 *
 * Return: the precision value.
 */

int get_precision(const char *format, int *index, va_list args)
{
	int i, precision;

	i = (*index) + 1;
	precision = -1;

	if (format[i] != '.')
		return (precision);

	precision = 0;
	i++;

	for ( ; format[i]; i++)
	{
		if (format[i] >= '0' && format[i] <= '9')
		{
			precision *= 10;
			precision += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			precision = va_arg(args, int);
			i++;
			break;
		}
		else
			break;
	}
	*index = i - 1;

	return (precision);
}
