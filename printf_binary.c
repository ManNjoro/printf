#include "main.h"

/**
 * printf_binary - prints an unsigned int in binary format
 * @args: an argument of type va_list
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: number of characters printed
 */
int printf_binary(va_list args, char *buffer, int flags,
		int width, int precision, int size)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int mask = 1;
	int count = 0;

	(void)buffer;
	(void)flags;
	(void)size;
	(void)precision;
	(void)width;

	while (mask <= num / 2)
		mask *= 2;

	while (mask > 0)
	{
		if (num & mask)
			count += _putchar('1');
		else
			count += _putchar('0');

		mask /= 2;
	}

	return (count);
}
