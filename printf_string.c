#include "main.h"
/**
 * printf_string - prints a string.
 * @args: an argument of type_valist.
 * Return: number of characters printed.
 */
int printf_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len] != '\0')
	{
		len += _putchar(str[len]);
	}

	return (len);
}
