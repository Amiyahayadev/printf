#include "main.h"

/**
 * write_ch - writes a character to standard output
 * @a: character to print
 * Return: 1 on success, -1 is on error appropriately.
 */
int write_ch(char a)
{
        return (write(1, &a, 1));
}

/**
 * print_char - prints argument as character
 * @ap: variadic arguments list
 * Return: length of character printed
 */
int print_char(va_list ap)
{
	return (write_ch(va_arg(ap, int)));
}

/**
 * print_string - prints argument as a string literal
 * @ap: variadic arguments list
 * Return: length of string printed
 */
int print_string(va_list ap)
{
	int len;

	char *s = va_arg(ap, char *);

	if (s == NULL)
		s = "(null)";
	len = 0;

	while (*s != '\0')
	{
		write_ch(*s);
		s++;
		len++;
	}
	return (len);
}
/**
 * print_decimal - writes integers to std ouput
 * @ap: variadic argument list
 * Return: length on SUCCESS
 */
int print_decimal(va_list ap)
{
	int num, len = 0;

	num = va_arg(ap, int);
	if (num == 0)
	{
		write_ch('0');
		len++;
		return (len);
	}
	if (num < 0)
	{
		write_ch('-');
		num = -(num);
		len++;
	}
	len += write_unsigned_decimal(num);
	return (len);
}

/**
 * write_unsigned_decimal - helper function that prints multidigit
 * positive number recursively
 * @num: number to print
 * Return: length of printed digits
 */
int write_unsigned_decimal(unsigned int num)
{
	int len = 0;

	if (num >= 10)
	{
		len += write_unsigned_decimal(num / 10);
	}
	write_ch('0' + (num % 10));
	len++;
	return (len);
}
