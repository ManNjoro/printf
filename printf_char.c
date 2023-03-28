#include "main.h"

/**
 * printf_char - prints a single character.
 * @args: an argument of type_valist.
 * @buffer: a char buffer.
 * @flags: format flags.
 * Return: number of characters printed.
 */
int printf_char(va_list args, char *buffer, int flags,
		int width, int precision, int size)
{
	int c = va_arg(args, int);

	(void)(buffer);
	(void)(flags);
	(void)(width);
	(void)(precision);
	(void)(size);

	_putchar(c);
	return (1);
}
