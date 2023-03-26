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
		{'c', printf_char},
		{'s', printf_string},
		{'i', printf_integer},
		{'d', printf_decimal},
		{'\0', NULL},
	};

	if (!format)
		return (0);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			count = _putchar(format[i]);
			len += count;
			continue;
		}

		for (j = 0; fmts[j].specifier; j++)
		{
			if (fmts[j].specifier == format[i + 1])
			{
				count = fmts[j].f(args, 1);
				len += count;
				i++;
			}
		}
	}
	va_end(args);
	return (len);
}