#include "main.h"

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
 * write_hexadecimal - writes an unsigned hexadecimal value to standard output
 * @num: unsigned hexadecimal value to print
 * Return: number of characters printed
 */
int write_hexadecimal(unsigned long num)
{
	int len = 0;

	if (num >= 16)
		len += write_hexadecimal(num / 16);

	int remainder = num % 16;

	if (remainder < 10)
		len += write_ch('0' + remainder);
	else
		len += write_ch('a' + (remainder - 10));

	return (len);
}

int write_hexadecimal(unsigned int num, int uppercase)
{
    int remainder;
    int len = 0;

    if (num == 0)
        return write_ch('0');

    if (num >= 16)
        len += write_hexadecimal(num / 16, uppercase);

    remainder = num % 16;

    if (remainder < 10)
        len += write_ch('0' + remainder);
    else
    {
        if (uppercase)
            len += write_ch('A' + (remainder - 10));
        else
            len += write_ch('a' + (remainder - 10));
    }

    return len;
}

int print_hexadecimal(va_list ap)
{
    unsigned int num = va_arg(ap, unsigned int);
    return write_hexadecimal(num, 0);
}

int print_hexa_upper(va_list ap)
{
    unsigned int num = va_arg(ap, unsigned int);
    return write_hexadecimal(num, 1);
}
