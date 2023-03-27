#include "main.h"

/**
 * printf_HEX - converts a decimal to an octal number
 * and prints it.
 * @args: an argument of type va_list.
 * @buffer: a char buffer.
 * @flags: format flags.
 * Return: number of digits in octal.
 */
int printf_HEX(va_list args, char *buffer, int flags)
{
	int i = 0, len = 0;
	int *ptr;
	unsigned int dec, tmp;

	(void)buffer;
	(void)flags;

	dec = va_arg(args, unsigned int);
	tmp = dec;

	while (tmp / 16 != 0)
	{
		tmp /= 16;
		len++;
	}
	len++;

	ptr = malloc(len * sizeof(unsigned int));

	while (i < len)
	{
		ptr[i++] = dec % 16;
		dec /= 16;
	}

	for (i = len - 1; i >= 0; i--)
	{
		if (ptr[i] > 9)
			ptr[i] += 7;
		_putchar(ptr[i] + '0');
	}

	free(ptr);

	return (len);
}
