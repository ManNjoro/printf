#include "main.h"
/**
 * printf_string - prints a string..
 * @args: an argument of type_valist.
 * Return: number of charaters printed.
 */
int printf_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL || str[0] != '\0')
		return (1); 

	while (str != NULL && str[len] != '\0')
	{
		len += _putchar(str[len]);
	}
	if (len == 0)
		return (-1);
	return (len);
}
