#include "main.h"
/**
 * printf_unsigned_int - prints an unsigned int.
 * @args: an argument of ytpe va_list.
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: numbers of characters printed.
 */
int printf_unsigned_int(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	unsigned long int _num;
	int i, unit, num, digit, expo, pos = 0;

	(void)flags;
	(void)precision;
	_num = get_unsigned_num(args, size);
	i = 1;
	unit = _num % 10;
	_num /= 10;
	expo = 1;
	if (unit < 0)
	{
		buffer[pos++] = '-';
		_num *= -1;
		unit *= -1;
		i++;
	}
	num = _num;
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			expo *= 10;
			num /= 10;
		}
		num = _num;
		while (expo > 0)
		{
			digit = num / expo;
			buffer[pos++] = digit + '0';
			num -= (digit * expo);
			expo /= 10;
			i++;
		}
	}
	buffer[pos++] = unit + '0';
	return (print_buffer(buffer, pos, width));
}
/**
 * get_unsigned_num - determines the type of the argument and cast it.
 * @args: a va_list type variable.
 * @size: an int
 * Return: the num with its appropriate type.
 */
unsigned long int get_unsigned_num(va_list args, int size)
{
	unsigned long int val;

	if (size == LONG_INT)
		val = va_arg(args, unsigned long int);
	else if (size == SHORT_INT)
		val = (unsigned short int)va_arg(args, int);
	else
		val = va_arg(args, unsigned int);

	return (val);
}
