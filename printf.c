#include "main.h"
/**
 * _printf - a function that produces output according to the format.
 * @format: a format for the arguments to be printed.
 * @...: a list of arguments to be printed.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, j, len = 0, count;
	va_list args;
	printf_fmt fmts[] = {
		{'c', printf_char}, {'s', printf_string},
		{'%', printf_percent}, {'i', printf_integer},
		{'d', printf_decimal}, {'b', printf_binary},
		{'o', printf_oct}, {'u', printf_unsigned_int},
		{'x', printf_hex}, {'X', printf_HEX},
		{'p', printf_pointer}, {'r', printf_rev_str},
		{'R', printf_rot13}, {'S', printf_exclusive_string},
		{'\0', NULL},
	};

	if (format == NULL || format[0] == '\0')
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			count = _putchar(format[i]);
			len += count;
			continue;
		}
		if (format[i + 1] == '\0' || format[i + 1] == ' ')
			return (-1);
		for (j = 0; fmts[j].specifier; j++)
		{
			if (fmts[j].specifier == format[i + 1])
			{
				count = fmts[j].f(args);
				if (count == -1)
					return (-1);
				len += count;
				i++;
			}
		}
	}
	va_end(args);
	return (len);
}
