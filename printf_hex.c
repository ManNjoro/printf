#include "main.h"
/**
 * printf_hex - converts a decimal to an octal number
 * and prints it.
 * @args: an argument of type va_list.
 * Return: number of digits in octal.
 */
int printf_hex(va_list args)
{
	int i = 0, len = 0;
	int *ptr;
	unsigned int dec, tmp;

	dec = va_arg(args, unsigned int);
	tmp = dec;

	while (tmp / 16 != 0)
	{
		tmp /= 16;
		len++;
	}
	len++;
	ptr = malloc(len * sizeof(int));
	while (i < len)
	{
		ptr[i++] = dec % 16;
		dec /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (ptr[i] > 9)
			ptr[i] += 39;
		_putchar(ptr[i] + '0');
	}
	free(ptr);
	return (len);
}
