#include "main.h"

/**
 * _printf - program that prints formatted output
 * @format: initial string argument to be printed
 * Return: length of formated string on SUCCESS, -1 on ERROR
 */
int _printf(const char *format, ...)
{
	int j;

	unsigned int t_len = 0, ret;

	va_list ap;

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
			/* call match spcifier funciton*/
			ret = match_specifier(ap, format[j]);
			t_len += ret;
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
/**
 * match_specifier -  helper function for printf
 * Description - searches for valid specifier and calls appropriate funtion
 * @ap: variadic argument list
 * @specifier_char: format specifier to be searched
 * Return: length of written characters
 */
int match_specifier(va_list ap, char specifier_char)
{
	int i, specifier_found;

	unsigned int t_len;

	spec_t search[] = {{'s', print_string}, {'c', print_char},
	{'i', print_decimal}, {'d', print_decimal}, {'x', print_hexadecimal},
	{'b', print_binary}, {'%', print_percent}, {'p', print_pointer},
	{'u', print_unsigned}, {'X', print_hexa_upper}, {'\0', NULL}, };

	specifier_found = 0;
	for (i = 0; search[i].format != '\0'; i++)
	{
		if (search[i].format == specifier_char)
		{
			t_len = search[i].conversion(ap);
			specifier_found = 1;
			break;
		}
	}
	if (!specifier_found)
	{
		write_ch('%');
		write_ch(specifier_char);
		t_len += 2;
	}
	return (t_len);
}
