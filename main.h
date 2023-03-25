#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int printf_char(va_list args, int count_of_printed);
int printf_string(va_list args, int count_of_printed);
int printf_integer(va_list args, int count_of_printed);
int select_specifier(const char *format, va_list args, int count_of_printed);
int printf_binary(unsigned int num, int count_of_printed);
int _printf(const char *format, ...);
int printf_hex(unsigned int num, int count_of_printed, int uppercase);
int printf_octal(unsigned int num, int count_of_printed);
int printf_unsigned(unsigned int num, int count_of_printed);
int printf_reverse(va_list args, int count_of_printed);
int printf_pointer(va_list args, int count_of_printed);

#endif
