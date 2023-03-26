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
		{'%', printf_percent},
		{'\0', NULL},
	};

	if (!format || !format[0])
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
		if (!format[i + 1] || format[i + 1] == ' ')
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
