#include "main.h"

/**
 * printf_binary - prints an unsigned int in binary format
 * @args: an argument of type va_list
 * @buffer: a char buffer.
 * @flags: format flags.
 * Return: number of characters printed
 */
int printf_binary(va_list args, char *buffer, int flags)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int mask = 1;
	int count = 0;

	(void) buffer;
	(void) flags;

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
