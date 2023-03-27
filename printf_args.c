#include "main.h"
/**
 * printf_args - a function that produces output according to the format.
 * @format: a format for the arguments to be printed.
 * @args: a list of arguments to be printed.
 * Return: the number of characters printed.
 */
int printf_args(const char *format, int *index, va_list args)
{
	int i, printed = -1;
	printf_fmt fmts[] = {
		{'c', printf_char}, {'s', printf_string}, {'%', printf_percent},
		{'i', printf_integer}, {'d', printf_decimal}, {'b', printf_binary},
		{'o', printf_oct}, {'u', printf_unsigned_int}, {'x', printf_hex},
		{'X', printf_HEX}, {'p', printf_pointer}, {'r', printf_rev_str},
		{'R', printf_rot13}, {'S', printf_exclusive_string}, {'\0', NULL},
	};
	
	for (i = 0; fmts[i].specifier; i++)
	{
		if (fmts[i].specifier == format[*index])
		       return (fmts[i].f(args));
	}

	return (printed);
}