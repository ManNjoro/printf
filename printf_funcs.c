#include "main.h"
/**
 * printf_char - prints a single character.
 * @args: an argument of type_valist.
 * @count_of_printed: the length of characters to print.
 * Return: number of charaters printed.
 */
int printf_char(va_list args, int count_of_printed)
{
	int c = va_arg(args, int);

	return (write(1, &c, count_of_printed));
}

/**
 * printf_string - prints a string..
 * @args: an argument of type_valist.
 * @count_of_printed: the number of characters to print.
 * Return: number of charaters printed.
 */
int printf_string(va_list args, int count_of_printed)
{
	char *str = va_arg(args, char *);
	int i = 0, len = 0;

	while (str[i++] != '\0')
		len++;

	if (len == 0)
		return (0);
	count_of_printed = len;

	return (write(1, str, count_of_printed));
}
