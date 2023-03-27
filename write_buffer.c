#include "main.h"

/**
 * write_buffer - prints the content of the buffer.
 * @buf: the buffer to be printed.
 * @size: the size of the buffer.
 * Return: the size of the buffer printed.
 */
int write_buffer(char *buf, int size)
{
	write(1, buf, size);
	return (0);
}
