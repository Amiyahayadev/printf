#include "main.h"

/**
 * custom_string - Converts non-printable characters in a string to hexa
 * representation and prints the new formatted string
 * @ap: variadic argument list
 * Return: length of printed string or -1
 */
int custom_string(va_list ap)
{
	char *c_str = va_arg(ap, char *);

	int len = 0;

	if (c_str == NULL)
		return (put_str("(null)"));

	while (*c_str)
	{
		if (*c_str < 32 || *c_str >= 127)
		{
			len += put_str("\\x");
			len += write_ch('0');
			len += write_hexadecimal(*c_str, 1, 2);
		}
		else
			len += write_ch(*c_str);
		c_str++;
	}
	return (len);
}

/**
 * put_str - prints a string
 * @str: string to print
 * Return: length of written string
 */
int put_str(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		write_ch(str[len]);
		len++;
	}
	return (len);
}
