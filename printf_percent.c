#include "main.h"

/**
 * printf_percent - Prints a percent symbol
 * @args: list of arguments
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: Will return the amount of characters printed.
 */
int printf_percent(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	(void)args;
	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	return (_putchar('%'));
}
