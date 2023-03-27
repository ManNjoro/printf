#include "main.h"
/**
 * _printf - a function that produces output according to the format.
 * @format: a format for the arguments to be printed.
 * @...: a list of arguments to be printed.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int printed;
	va_list args;

	if (format == NULL || format[0] == '\0')
		return (-1);

	va_start(args, format);
	printed = printf_helper(format, args);
	va_end(args);
	return (printed);
}
