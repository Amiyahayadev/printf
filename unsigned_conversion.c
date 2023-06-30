#include "main.h"

/**
 * print_base - prints an unsigned integer argument
 * @num: variadic argument
 * @base: base to be converted to
 * Return: length of characters printed or -1 on Error
 */
int print_base(unsigned int num, int base)
{
	int str_len = 0;

	char *numArr;
	unsigned int temp, digit, len = 0, i;

	if (num == 0)
		return (write_ch('0'));

	temp = num;
	while (temp > 0)
	{
		len++;
		temp /= base;
	}
	numArr = allocate_mem(len + 1);
	if (numArr == NULL)
		return (-1);

	for (i = len - 1; num > 0; i--)
	{
		digit = num % base;
		numArr[i] = digit + '0';
		num /= base;
	}
	numArr[len] = '\0';
	for (i = 0; numArr[i] != '\0'; i++)
	{
		write_ch(numArr[i]);
		str_len++;
	}
	free(numArr);
	return (str_len);
}

/**
 * allocate_mem - creates an array of chars
 * @size: array size
 * Return: pointer to the created array
 */
char *allocate_mem(unsigned int size)
{
	char *array;

	if (size == 0)
		return (NULL);
	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	return (array);
}
/**
 * print_unsigned - prints an unsigned integer argument
 * @ap: variadic argument list
 * Return: length of characters printed or -1 on Error
 */
int print_unsigned(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);

	return (print_base(num, 10));
}


/**
 * print_octal - prints an unsigned integer argument
 * @ap: variadic argument list
 * Return: length of characters printed or -1 on Error
 */
int print_octal(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);

	return (print_base(num, 8));
}
