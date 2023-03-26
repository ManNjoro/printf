#include "main.h"
/**
 * printf_string - prints a string.
 * @args: an argument of type_valist.
 * Return: number of characters printed.
 */
int printf_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len;

	if (str == NULL)
		str = "(null)";

	for (len = 0; str[len] != '\0'; len++)
		_putchar(str[len]);
	return (len);
}
