#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1024

#define LONG_INT 4
#define SHORT_INT 2

/**
 * struct flag - represents the format flags.
 * @pos: '+'
 * @space: ' '
 * @hash: '#'
 * @zero: '0'
 * @neg: '-'
 */
typedef struct flag
{
	int pos;
	int space;
	int hash;
	int zero;
	int neg;
} flg;

int _putchar(char c);
int _printf(const char *format, ...);

int printf_char(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_string(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_binary(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_integer(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_decimal(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_percent(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_oct(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_unsigned_int(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_hex(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_HEX(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_rev_str(va_list arg, char *buffer, flg flags,
		int width, int precision, int size);
int printf_pointer(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_rot13(va_list args, char *buffer, flg flags,
		int width, int precision, int size);
int printf_exclusive_string(va_list val, char *buffer, flg flags,
		int width, int precision, int size);

int printf_HEX_aux(unsigned int num);
int write_buffer(char *buf, int buf_size);
int printf_helper(const char *format, va_list args);
int printf_args(const char *format, int *index, va_list args,
		char *buf, flg flags, int width, int precision, int size);


flg get_all_flags(const char *format, int *index);
int get_precision(const char *format, int *index, va_list args);
int get_width(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
unsigned long int get_unsigned_num(va_list args, int size);

/**
 * struct printf_f - a struct for the printf string specifiers ans
 * their corresponding functions.
 * @specifier: a character specifier.
 * @f: a function for the specifier.
 */
typedef struct printf_f
{
	char specifier;
	int (*f)(va_list args, char *buffer, flg flags,
			int width, int precision, int size);
} printf_fmt;

#endif
