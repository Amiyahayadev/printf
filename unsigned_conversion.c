#include "main.h"

/**
 * print_unsigned - prints an unsigned integer argument
 * @ap: variadic argument list
 * Return: length of characters printed or -1 on Error
 */
int print_unsigned(va_list ap)
{
	int str_len = 0;

	char *numArr;
	unsigned int num, temp, len = 0, i;

	num = va_arg(ap, unsigned int);
	if (num == 0)
		return (write_ch('0'));

	temp = num;
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	numArr = allocate_mem(len + 1);
	if (numArr == NULL)
		return (-1);

	for (i = len - 1; num > 0; i--)
	{
		numArr[i] = (num % 10) + '0';
		num /= 10;
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
