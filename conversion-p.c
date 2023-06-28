#include "main.h"

/* Forward declaration */
int write_ch(char a);


/**
 * print_decimal - prints argument as decimal
 * @ap: other variadic arguments list
 * Return: number of characters printed
 */
int print_decimal(va_list ap)
{
	int num, len = 0;

	num = va_arg(ap, int);

	if (num == 0)
	{
		len += write_ch('0');
		return (len);
	}
	if (num < 0)
	{
		len += write_ch('-');
		num = -num;
	}
	len += write_unsigned_decimal((unsigned int)num);
	return (len);
}

/**
 * print_pointer - prints argument as pointer addre
 * @ap: other variadic arguments list
 * Return: number of characters printed as succe
 */
int print_pointer(va_list ap)
{
	void *ptr = va_arg(ap, void *);

	unsigned long num = (unsigned long)ptr;

	int len = 0;

	len += write_ch('0');
	len += write_ch('x');
	len += write_hexadecimal(num);
	return (len);
}

/**
 * write_ch - writes a character to standard output
 * @a: character to print
 * Return: 1 on success, -1 on error
 */
int write_ch(char a)
{
	return (write(1, &a, 1));
}

/**
 * write_hexadecimal - writes an unsigned hexadecimal value to standard output
 * @num: unsigned hexadecimal value to print
 * Return: number of characters printed
 */
int write_hexadecimal(unsigned long num)
{
	int len = 0;

	if (num >= 16)
	{
		len += write_hexadecimal(num / 16);
	}
	int remainder = num % 16;

	if (remainder < 10)
	{
		len += write_ch('0' + remainder);
	}
	else
	{
		len += write_ch('a' + (remainder - 10));
	}
	return (len);
}

