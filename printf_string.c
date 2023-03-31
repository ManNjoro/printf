#include "main.h"

/**
 * printf_string - prints a string.
 * @args: an argument of type_valist.
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: number of characters printed.
 */
int printf_string(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	char *str = va_arg(args, char *);
	int pos = 0, i = 0;

	(void)flags;
	(void)precision;
	(void)size;

	if (str == NULL)
		str = "(nil)";

	while (str[pos])
		buffer[pos++] = str[i++];
	return (print_buffer(buffer, pos, width));
}
