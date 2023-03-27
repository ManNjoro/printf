#include "main.h"

/**
 * get_all_flags - determines the number of active flags.
 * @format: string format for printing arguments.
 * @index: an int parameter.
 * Return: all flags.
 */
int get_all_flags(const char *format, int *index)
{
	int i, j, flags = 0;
	const char *FLAGS = "-+0# ";
	const int _FLAGS[] = { F_NEG, F_POS, F_0, F_HASH, F_SPACE, 0 };

	for (i = *index + 1; format[i]; i++)
	{
		for (j = 0; FLAGS[j]; j++)
		{
			if (format[i] == FLAGS[j])
			{
				flags |= _FLAGS[j];
				break;
			}

		}
		if (_FLAGS[j] == 0)
			break;
	}
	*index = i - 1;

	return (flags);
}
