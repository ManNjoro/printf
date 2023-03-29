#include "main.h"
/**
 * printf_args - a function that produces output according to the format.
 * @format: a format for the arguments to be printed
 * @index: a int.
 * @args: a list of arguments to be printed.
 * @buf: a char array.
 * @flags: format flags
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: the number of characters printed.
 */
int printf_args(const char *format, int *index, va_list args,
		char *buf, flg flags, int width, int precision, int size)
{
	int i, printed = -1;
	printf_fmt fmts[] = {
		{'c', printf_char},
		{'s', printf_string},
		{'%', printf_percent},
		{'i', printf_integer},
		{'d', printf_decimal},
		{'b', printf_binary},
		{'o', printf_oct},
		{'u', printf_unsigned_int},
		{'x', printf_hex},
		{'X', printf_HEX},
		{'p', printf_pointer},
		{'r', printf_rev_str},
		{'R', printf_rot13},
		{'S', printf_exclusive_string},
		{'\0', NULL},
	};
	for (i = 0; fmts[i].specifier; i++)
		if (fmts[i].specifier == format[*index])
			return (fmts[i].f(args, buf, flags, width, precision, size));

	return (printed);
}
