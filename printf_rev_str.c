#include "main.h"
/**
 * printf_rev_str - prints a string in reverse.
 * @args: a va_list type argument.
 * @buffer: a char buffer.
 * @flags: format flags.
 * @width: width of the argument to print.
 * @precision: precision of the argument to print.
 * @size: mod of the argument to print.
 * Return: number of characters printed.
 */
int printf_rev_str(va_list args, char *buffer, flg flags,
		int width, int precision, int size)
{
	char *str;
	int i, len;

	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";

	while (str[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
		_putchar(str[len - i - 1]);

	return (len);
}
