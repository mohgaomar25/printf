#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;

va_start(args, format);

while (*format)
{
if (*format != '%')
 /* Print the character */
printed_chars += write(1, format, 1);
else
{
format++;
if (*format == '\0') // Handle trailing '%'
break;

switch (*format)
{
case 'c':
printed_chars += write(1, &va_arg(args, int), 1);
break;
case 's':
{
char *str = va_arg(args, char *);
if (!str) str = "(null)";
while (*str) printed_chars += write(1, str++, 1);
}
break;
case '%':
printed_chars += write(1, "%", 1);
break;
default:
/* Print '%' as default */
printed_chars += write(1, "%", 1);
/* Print the unknown format specifier */
if (*format) printed_chars += write(1, format, 1);
}
}
/* Move to the next character in the format string */
format++; 
}

va_end(args);
return printed_chars;
}
