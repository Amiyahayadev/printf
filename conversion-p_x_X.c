#include "main.h"

/**
 * print_pointer - prints argument as address
 * @ap: other variadic arguments list
 * Return: number of characters printed as succe
 */
int print_pointer(va_list ap)
{
	unsigned long num;

	int len = 0;

	void *ptr = va_arg(ap, void *);

	if (ptr == NULL)
	{
		char *ptr = "(nil)";

		while (ptr[len] != '\0')
		{
			write_ch(ptr[len]);
			len++;
		}
		return (len);
	}

	num = (unsigned long)ptr;

	len += write_ch('0');
	len += write_ch('x');
	len += write_longhexa(num);
	return (len);
}

/**
 * write_longhexa -  writes an unsigned hexadecimal value to standard output
 * @num: unsigned hexadecimal value to print
 * Return: number of characters printed
 */
int write_longhexa(unsigned long num)
{
	int len = 0;

	int remainder;

	if (num >= 16)
		len += write_longhexa(num / 16);

	remainder = num % 16;
	if (remainder < 10)
		len += write_ch('0' + remainder);
	else
		len += write_ch('a' + (remainder - 10));

	return (len);
}

/**
 * write_hexadecimal - converts an unsigned integer argument to base 16
 * @num: variadic argument
 * @uppercase: flag to indiate uppercase hexa values
 * @width: fixed no of characters to represent a hexadecimal conversion
 * Return: length of characters printed
 */
int write_hexadecimal(unsigned int num, int uppercase, int width)
{
	int remainder;
	int len = 0;

	if (num == 0)
		return (write_ch('0'));

	if (num >= 16)
		len += write_hexadecimal(num / 16, uppercase, width - 1);

	remainder = num % 16;
	if (width > len)
		len = width;

	if (remainder < 10)
		len += write_ch('0' + remainder);
	else
	{
		if (uppercase)
			len += write_ch('A' + (remainder - 10));
		else
			len += write_ch('a' + (remainder - 10));
	}
	return (len);
}

/**
 * print_hexadecimal - prints lowercase hexadecimal values
 * @ap: list of variadic argument
 * Return: length of characters printed
 */
int print_hexadecimal(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);

	return (write_hexadecimal(num, 0, 0));
}

/**
 * print_hexa_upper - prints uppercase hexadecimal values
 * @ap: list of variadic argument
 * Return: length of characters printed
 */
int print_hexa_upper(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);

	return (write_hexadecimal(num, 1, 0));
}

