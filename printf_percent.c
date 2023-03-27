#include "main.h"

/**
 * printf_percent - Prints a percent symbol
 * @args: list of arguments
 * @buffer: a char buffer.
 * @flags: format flags.
 * Return: Will return the amount of characters printed.
 */
int printf_percent(va_list args, char *buffer, int flags)
{
	(void)args;
	(void)buffer;
	(void)flags;

	_putchar('%');
	return (1);
}
