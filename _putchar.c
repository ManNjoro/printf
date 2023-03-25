#include "main.h"

/**
 * _putchar - prints char
 * @c: char being passed
 * Return: returning char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
