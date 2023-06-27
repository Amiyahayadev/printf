#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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

int write_ch(char a);
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);
int write_unsigned_decimal(unsigned int num);
int print_decimal(va_list ap);
int print_percent(va_list ap);
int print_binary(va_list ap);
/*int match_specifier(va_list ap, char specifier_char);*/

#endif /*MAIN_H*/
