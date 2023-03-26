#include "main.h"

/**
 * printf_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */
int printf_percent(va_list list)
{
	(void)list;
	_putchar('%');
	return (1);
}
