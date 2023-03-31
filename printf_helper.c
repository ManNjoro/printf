#include "main.h"
/**
 * printf_helper - a function that produces output according to the format.
 * @format: a format for the arguments to be printed.
 * @args: a list of arguments to be printed.
 * Return: the number of characters printed.
 */
int printf_helper(const char *format, va_list args)
{
	int i, printed = 0, count, buf_size = 0;
	int width = 0, precision = 0, size = 0;
	flg flags;
	char buf[SIZE];

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
		if (format[i + 1] == '\0')
			return (-1);
		flags = get_all_flags(format, &i);
		width = get_width(format, &i, args);
		precision = get_precision(format, &i, args);
		size = get_size(format, &i);
		i++;
		count = printf_args(format, &i, args, buf, flags, width, precision, size);
		if (count == -1)
			return (-1);
		printed += count;
	}
	write_buffer(buf, buf_size);

	return (printed);
}
