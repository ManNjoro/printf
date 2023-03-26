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

	if (str[0] == '\0')
		return (-1);

	while (str[len] != '\0')
	{
		_putchar(str[len]);
		len++;
	}

	return (len);
}
