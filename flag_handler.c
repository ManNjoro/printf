#include "main.h"
/**
 * get_all_flags - determines the number of active flags.
 * @format: string format for printing arguments.
 * @index: an int parameter.
 * Return: all flags.
 */
flg get_all_flags(const char *format, int *index)
{
	int i = *index + 1;
	flg flags = {0, 0, 0, 0, 0};

	while (format[i])
	{
		if (format[i] == 32)
			flags.space = 1;
		else if (format[i] == '+')
			flags.pos = 1;
		else if (format[i] == '-')
			flags.neg = 1;
		else if (format[i] == '#')
			flags.hash = 1;
		else if (format[i] == '0')
			flags.zero = 1;
		else
			break;
		i++;
	}
	*index = i - 1;
	return (flags);
}
