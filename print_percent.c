#include "main.h"

/**
 * print_percent - converts double percent to % sybbol
 * @ap: argument list
 * Return: length of 1 on SUCCESS
 */
int print_percent(va_list ap)
{
	(void)ap;

	return (write_ch('%'));
}
