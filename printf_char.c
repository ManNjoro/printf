#include "main.h"
/**
 * printf_char - prints a single character.
 * @args: an argument of type_valist.
 * Return: number of charaters printed.
 */
int printf_char(va_list args)
{
	int c = va_arg(args, int);

	return (_putchar(c));
}
