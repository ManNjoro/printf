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
int printf_integer(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	long int n = get_num(args, size);
	long int num, last = n % 10, digit, exp = 1;
	int pos = 0, i = 0;

	(void)width;
	(void)precision;
	n = n / 10;
	num = n;
	if (last < 0)
	{
		buffer[pos++] = '-';
		num *= -1;
		n *= -1;
		last *= -1;
		i++;
	}
	else
	{
		if (flags.pos)
			buffer[pos++] = '+';
		else if (flags.pos)
			buffer[pos++] = ' ';
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
			buffer[pos++] = digit + '0';
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	buffer[pos++] = last + '0';
	return (write(1, buffer, pos));
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
int printf_decimal(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	long int n = get_num(args, size);
	long int num, last = n % 10, digit;
	int pos = 0, exp = 1, i = 0;

	(void)width;
	(void)precision;
	n = n / 10;
	num = n;
	if (last < 0)
	{
		buffer[pos++] = '-';
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	else
	{
		if (flags.pos)
		{
			buffer[pos++] = '+';
		}
		else if (flags.space)
			buffer[pos++] = ' ';
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
			buffer[pos++] = digit + '0';
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	buffer[pos++] = last + '0';
	return (write(1, buffer, pos));
}

/**
 * get_num - determines the type of the argument and cast it.
 * @args: a va_list type variable.
 * @size: an int
 * Return: the num with its appropriate type.
 */
long int get_num(va_list args, int size)
{
	long int val;

	if (size == LONG_INT)
		val = va_arg(args, long int);
	else if (size == SHORT_INT)
		val = (short int)va_arg(args, int);
	else
		val = va_arg(args, int);
	return (val);
}
