#include "main.h"

/**
 * printf_oct - converts a decimal to an octal number
 * and prints it.
 * @args: an argument of type va_list.
 * @buffer: a char buffer.
 * @flags: format flags.
 * Return: number of digits in octal.
 */
int printf_oct(va_list args, char *buffer, int flags)
{
	int i = 0, len = 0;
	int *ptr;
	unsigned int dec, tmp;

	dec = va_arg(args, unsigned int);
	tmp = dec;

	(void)buffer;
	(void)flags;

	while (tmp / 8 != 0)
	{
		tmp /= 8;
		len++;
	}
	len++;

	ptr = malloc(len * sizeof(int));

	while (i < len)
	{
		ptr[i++] = dec % 8;
		dec /= 8;
	}

	for (i = len - 1; i >= 0; i--)
		_putchar(ptr[i] + '0');

	free(ptr);

	return (len);
}
