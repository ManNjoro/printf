#include "main.h"
long int get_num(va_list args, int size);
/**
 * printf_integer - prints integer
 * @args: argument to print
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: number of characters printed
 */
int printf_integer(va_list args, char *buffer, int flags,
		int width, int precision, int size)
{
	int n = get_num(args, size);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	n = n / 10;
	num = n;
	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');
	return (i);
}

/**
 * printf_decimal - prints decimal
 * @args: argument to print
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: number of characters printed
 */
int printf_decimal(va_list args, char *buffer, int flags,
		int width, int precision, int size)
{
	int n = get_num(args, size);
	int num, last = n % 10, digit;
	int  i = 1;
	int exp = 1;

	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	n = n / 10;
	num = n;
	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');
	return (i);
}

long int get_num(va_list args, int size)
{
	long int val;

	if (size == LONG_INT)
		val = va_arg(args, long);
	else if (size == SHORT_INT)
		val = (short)va_arg(args, int);
	else
		val = va_arg(args,int);

	return val;
}
