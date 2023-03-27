#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1024

int _putchar(char c);
int select_specifier(const char *format, va_list args, int count_of_printed);
int _printf(const char *format, ...);
int printf_char(va_list args);
int printf_string(va_list args);
int printf_binary(va_list args);
int printf_integer(va_list args);
int printf_decimal(va_list args);
int printf_percent(va_list args);
int printf_oct(va_list args);
int printf_unsigned_int(va_list args);
int printf_hex(va_list args);
int printf_HEX(va_list args);
int printf_rev_str(va_list arg);
int printf_pointer(va_list args);
int printf_rot13(va_list args);
int printf_HEX_aux(unsigned int num);
int printf_exclusive_string(va_list val);

int write_buffer(char *buf, int buf_size);


/**
 * struct printf_f - a struct for the printf string specifiers ans
 * their corresponding functions.
 * @specifier: a character specifier.
 * @f: a function for the specifier.
 */
typedef struct printf_f
{
	char specifier;
	int (*f)(va_list args);
} printf_fmt;

#endif
