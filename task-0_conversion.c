#include "main.h"

/**
 * print_char - prints argument as character
 * @ap: variadic arguments list
 * Return: length of character printed
 */
int print_char(va_list ap)
{
	int len = 0;
	char c = va_arg(ap, int);

	_putchar(c);
	len = 1;
	return (len);
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

	while (*s != '\0)
	{
		_putchar(*s);
		s++;
		len++;
	}
	return (len);
}

