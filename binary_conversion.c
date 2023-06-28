#include "main.h"

/**
 * print_binary - Entry poiint of binary conversion
 * @ap: other needed argumennt for binary conversioons
 * Return: alwways successs 1
 */
int print_binary(va_list ap)
{
	unsigned int binary, num;
	char *biString;
	int i, binLen = 0, len = 0;

	num = va_arg(ap, unsigned int);

	if (num == 0)
	{
		write_ch('0');
		return (1);
	}

	binary = num;
	while (binary > 0)
	{
		binLen++;
		binary /= 2;
	}

	biString = malloc((binLen + 1) * sizeof(char));
	if (biString == NULL)
		return (-1);

	for (i = binLen - 1; num > 0; i--)
	{
		biString[i] = (num % 2) + '0';
		num /= 2;
	}
	biString[binLen] = '\0';
	for (i = 0; biString[i] != '\0'; i++)
	{
		write_ch(biString[i]);
		len++;
	}
	free(biString);
	return (len);
}


