#include "main.h"

/**
 * _printf - program that prints formatted output
 * @format: initial string argument to be printed
 * Return: length of formated string on SUCCESS, -1 on ERROR
 */
int _printf(const char *format, ...)
{
	int i, j, specifier_found;

	unsigned int t_len = 0;

	va_list ap;

	spec_t search[] = {{'s', print_string}, {'c', print_char},
			{'i', print_decimal}, {'d', print_decimal},
			{'\0', NULL},
		};

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	j = 0;
	while (format[j] != '\0')
	{
		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		if (format[0] == '%' && format[1] == ' ')
			return (-1);
		if (format[j] == '%' && format[j + 1] == '%')
		{
			write_ch('%');
			j += 2;
			t_len++;
			continue;
		}
		if (format[j] == '%' && format[j + 1] != '\0')
		{
			j++;
			specifier_found = 0;

			for (i = 0; search[i].format != '\0'; i++)
			{
				if (search[i].format == format[j])
				{
					t_len += search[i].conversion(ap);
					va_arg(ap, void *);
					specifier_found = 1;
					break;
				}
			}
			if (!specifier_found)
			{
				write_ch('%');
				write_ch(format[j]);
				t_len += 2;
			}
			j++;
			continue;
		}
		if (format[j] == '%' && format[j + 1] == '\0')
			return (t_len);
		write_ch(format[j]);
		j++;
		t_len++;
	}
	va_end(ap);
	return (t_len);
}
