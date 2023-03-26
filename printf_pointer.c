#include "main.h"
/**
 * unsigned_long_int_to_hex - converts an unsigned long int
 * to a hex and prints it.
 * @num: an unsigned long int argument.
 * Return: number of characters printed.
 */
int unsigned_long_int_to_hex(unsigned long int num)
{
	unsigned long int tmp;
	int len = 0, i = 0;
	long int *res;

	tmp = num;

	while (tmp / 16)
	{
		tmp /= 16;
		len++;
	}
	len++;

	res = malloc(len * sizeof(long int));

	while (i < len)
	{
		res[i++] = num % 16;
		num /= 16;
	}

	for (i = len - 1; i >= 0; i--)
	{
		if (res[i] > 9)
			res[i] += 39;
		_putchar(res[i] + '0');
	}

	free(res);
	return (len);
}

/**
 * printf_pointer - prints the address of a pointer as
 * hexadecimal.
 * @args: an argument of type va_list.
 * Return: number of characters printed.
 */
int printf_pointer(va_list args)
{
	int len = 0;
	long int val;
	char *arg;

	arg = va_arg(args, void*);

	_putchar('0');
	_putchar('x');

	val = (unsigned long int) arg;
	len = unsigned_long_int_to_hex(val);

	return (len + 2);
}
