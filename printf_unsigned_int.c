#include "main.h"
/**
 * printf_unsigned_int - prints an unsigned int.
 * @args: an argument of ytpe va_list.
 * @buffer: a char buffer.
 * @flags: format flags.
 * Return: numbers of characters printed.
 */
int printf_unsigned_int(va_list args, char *buffer, int flags)
{
	unsigned int _num;
	int i, unit, num, digit, expo;

	(void)buffer;
	(void)flags;
	_num = va_arg(args, unsigned int);
	i = 1;
	unit = _num % 10;
	_num /= 10;
	expo = 1;

	if (unit < 0)
	{
		_putchar('-');
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
			_putchar(digit + '0');
			num -= (digit * expo);
			expo /= 10;
			i++;
		}
	}
	_putchar(unit + '0');

	return (i);
}
