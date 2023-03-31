#include "main.h"
/**
 * printf_hex - converts a decimal to an octal number
 * and prints it.
 * @args: an argument of type va_list.
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: number of digits in octal.
 */
int printf_hex(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	int i = 0, pos = 0, len = 0;
	unsigned long int _num, tmp;
	int *ptr;

	(void)precision;
	_num = get_unsigned_num(args, size);
	tmp = _num;
	if (flags.hash && _num > 0)
	{
		buffer[pos++] = '0';
		buffer[pos++] = 'x';
	}
	while (tmp / 16 != 0)
	{
		tmp /= 16;
		len++;
	}
	len++;
	ptr = malloc(len * (sizeof(unsigned int)));
	while (i < len)
	{
		ptr[i++] = _num % 16;
		_num /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (ptr[i] > 9)
			ptr[i] += 39;
		buffer[pos++] = ptr[i] + '0';
	}
	free(ptr);
	return (print_buffer(buffer, pos, width));
}
