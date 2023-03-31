#include "main.h"

/**
 * printf_char - prints a single character.
 * @args: an argument of type_valist.
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: number of characters printed.
 */
int printf_char(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	char c = va_arg(args, int);
	int pos = 0;

	(void)(flags);
	(void)(precision);
	(void)(size);

	buffer[pos++] = c;
	return (print_buffer(buffer, pos, width));
}
