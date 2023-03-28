#include "main.h"

/**
 * get_width - determines the width of the characters to be printed.
 * @format: a string format for the arguments to be printed.
 * @index: an integer.
 * @args: a va_list type argument.
 * Return: width of the string to print.
 */

int get_width(const char *format, int *index, va_list args)
{
	int i, width = 0;

	for (i = (*index) + 1; format[i]; i++)
	{
		if (format[i] >= '0' && format[i] <= '9')
		{
			width *= 10;
			width += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			width = va_arg(args, int);
			i++;
			break;
		}
		else
			break;
	}
	*index = i - 1;

	return (width);
}
