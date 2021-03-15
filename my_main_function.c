#include "holberton.h"

/**
 * _printf - print a number using print_number func
 * @format: string to print.
 *
 * Return: integer.
 */

int _printf(const char *format, ...)
{
	data_t type[] = {
		{"c", print_char}, {"s", print_char_2},
		{"d", print_int}, {"i", print_int},
		{"b", print_to_binar}, {"%", print_percent},
		{"u", print_uns}, {"o", print_octal},
		{"x", print_hexa_low}, {"X", print_hexa_upper},
		{"S", print_str_non_print}, {"r", print_str_rev},
		{"R", print_rot_13}, {NULL, NULL},
	};

	int indx_type, iter = 0, pos1 = 0, pos2, count = 0;

	if (format == NULL)
		return (-1);

	va_list list;

	va_start(list, format);

	while (format && format[iter])
	{
		while (format[iter] && format[iter] != '%')
			iter++;
		pos2 = iter - 1;
		print_str(pos1, pos2, format);
		count += pos2 - pos1 + 1;
		if (format[iter])
		{
			pos1 = pos2 + 3;
			indx_type = 0;
			iter++;
			while (type[indx_type].type)
			{
				if (*type[indx_type].type == format[iter])
					count += type[indx_type].func(list);
				indx_type++;
			}
		}
		else
			break;
		iter++;
	}
	va_end(list);
	return (count);
}
