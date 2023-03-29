#include "main.h"

/**
 * printf_oct - converts a decimal to an octal number
 * and prints it.
 * @args: an argument of type va_list.
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: number of digits in octal.
 */
int printf_oct(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	int i = 0, len = 0, pos = 0;
	int *ptr;
	unsigned long int _num, tmp;

	_num = get_unsigned_num(args, size);
	tmp = _num;
	(void)width;
	(void)precision;
	if (flags.hash)
		buffer[pos++] = '0';
	while (tmp / 8 != 0)
	{
		tmp /= 8;
		len++;
	}
	len++;
	ptr = malloc(len * sizeof(int));
	while (i < len)
	{
		ptr[i++] = _num % 8;
		_num /= 8;
	}

	for (i = len - 1; i >= 0; i--)
		buffer[pos++] = ptr[i] + '0';

	free(ptr);

	return (write(1, buffer, pos));
}
