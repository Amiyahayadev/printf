#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct specifier - user defined datatype for variable to hold types
 * @format: member that represents each format specifier type
 * @conversion: function pointer for appriopriate function
 */
typedef struct specifier
{
	char format;
	int (*conversion)(va_list);
} spec_t;
/*spec_t - type definition for struct specifier */

int _putchar(char a);
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);

#endif /*MAIN_H*/
