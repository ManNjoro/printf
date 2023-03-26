#include "main.h"
/**
 * printf_rev_str - prints a string in reverse.
 * @args: a va_list type argument.
 * Return: number of characters printed.
 */
int printf_rev_str(va_list args)
{
	char *str;
	int i, len;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";

	while (str[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
		_putchar(str[len - i - 1]);

	return (len);
}
