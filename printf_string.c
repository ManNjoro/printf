#include "main.h"

/**
 * printf_string - prints a string.
 * @args: an argument of type_valist.
 * @buffer: a char buffer.
 * @flags: format flags.
 * Return: number of characters printed.
 */
int printf_string(va_list args, char *buffer, int flags,
		int width, int precision, int size)
{
	char *str = va_arg(args, char *);
	int len = 0;

	(void)buffer;
	(void)flags; 
	(void)width; 
	(void)precision; 
	(void)size;

	if (str == NULL)
		str = "(nil)";

	while (str[len] != '\0')
	{
		_putchar(str[len]);
		len++;
	}

	return (len);
}
