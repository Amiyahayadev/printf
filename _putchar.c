#include <unistd.h>

/**
 * _putchar - writes a character to standard output
 * @a: character to print
 * Return: 1 on success, -1 is on error appropriately.
 */
int _putchar(char a)
{
	return (write(1, &a, 1));
}
