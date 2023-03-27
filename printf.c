#include "main.h"
/**
 * _printf - a function that produces output according to the format.
 * @format: a format for the arguments to be printed.
 * @...: a list of arguments to be printed.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, j, printed = 0, count, buf_size = 0;
	va_list args;
	printf_fmt fmts[] = {
		{'c', printf_char}, {'s', printf_string}, {'%', printf_percent},
		{'i', printf_integer}, {'d', printf_decimal}, {'b', printf_binary},
		{'o', printf_oct}, {'u', printf_unsigned_int}, {'x', printf_hex},
		{'X', printf_HEX}, {'p', printf_pointer}, {'r', printf_rev_str},
		{'R', printf_rot13}, {'S', printf_exclusive_string}, {'\0', NULL},
	};
	char buf[SIZE];

	if (format == NULL || format[0] == '\0')
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buf[buf_size++] = format[i];
			printed++;
			if (buf_size >= SIZE - 24)
				buf_size = write_buffer(buf, buf_size);
			continue;
		}
		buf_size = write_buffer(buf, buf_size);
		if (format[i + 1] == '\0' || format[i + 1] == ' ')
			return (-1);
		for (j = 0; fmts[j].specifier; j++)
		{
			if (fmts[j].specifier == format[i + 1])
			{
				count = fmts[j].f(args);
				printed += count;
				i++;
			}
		}
	}
	write_buffer(buf, buf_size);
	va_end(args);
	return (printed);
}
