#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1024

#define F_NEG 1
#define F_POS 2
#define F_0 4
#define F_HASH 8
#define F_SPACE 16

int _putchar(char c);
int _printf(const char *format, ...);

int printf_char(va_list args, char *buffer, int flags);
int printf_string(va_list args, char *buffer, int flags);
int printf_binary(va_list args, char *buffer, int flags);
int printf_integer(va_list args, char *buffer, int flags);
int printf_decimal(va_list args, char *buffer, int flags);
int printf_percent(va_list args, char *buffer, int flags);
int printf_oct(va_list args, char *buffer, int flags);
int printf_unsigned_int(va_list args, char *buffer, int flags);
int printf_hex(va_list args, char *buffer, int flags);
int printf_HEX(va_list args, char *buffer, int flags);
int printf_rev_str(va_list arg, char *buffer, int flags);
int printf_pointer(va_list args, char *buffer, int flags);
int printf_rot13(va_list args, char *buffer, int flags);
int printf_exclusive_string(va_list val, char *buffer, int flags);

int printf_HEX_aux(unsigned int num);
int write_buffer(char *buf, int buf_size);
int printf_helper(const char *format, va_list args);
int get_all_flags(const char *format, int *inde);
int printf_args(const char *format, int *index,
		va_list args, char *buf, int flags);

/**
 * struct printf_f - a struct for the printf string specifiers ans
 * their corresponding functions.
 * @specifier: a character specifier.
 * @f: a function for the specifier.
 */
typedef struct printf_f
{
	char specifier;
	int (*f)(va_list args, char *buffer, int flags);
} printf_fmt;

#endif
