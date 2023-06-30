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
int match_specifier(va_list ap, char specifier_char);
int print_pointer(va_list ap);
int write_longhexa(unsigned long num);
int write_hexadecimal(unsigned int num, int uppercase, int width);
int print_hexadecimal(va_list ap);
int print_hexa_upper(va_list ap);
int print_unsigned(va_list ap);
int print_base(unsigned int num, int base);
int print_octal(va_list ap);
char *allocate_mem(unsigned int size);
int custom_string(va_list ap);
int put_str(char *str);

#endif /*MAIN_H*/
