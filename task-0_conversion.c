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

