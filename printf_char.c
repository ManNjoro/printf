#include "main.h"

/**
 * printf_char - prints a single character.
 * @args: an argument of type_valist.
 * Return: number of characters printed.
 */
int printf_char(va_list args)
{
	int c = va_arg(args, int);

	_putchar(c);
	return (1);
}
