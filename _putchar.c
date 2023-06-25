#include <unistd.h>

/**
 * write_ch - writes a character to standard output
 * @a: character to print
 * Return: 1 on success, -1 is on error appropriately.
 */
int write_ch(char a)
{
	return (write(1, &a, 1));
}
