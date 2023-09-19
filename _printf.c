#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;
int num = 0;

va_start(args, format);

while (*format)
{
if (*format != '%')
{
printed_chars += print_char(*format);
}
else
{
format++;
switch (*format)
{
case 'c':
printed_chars += print_char(va_arg(args, int));
break;
case 's':
printed_chars += print_str(va_arg(args, char *));
break;
case '%':
printed_chars += print_char('%');
break;
case 'i':
int num = va_arg(args, int);
/* You can use a separate function to print integers*/
printed_chars += print_int(num);
break;
default:
printed_chars += print_char('%');
if (*format)
{
printed_chars += print_char(*format);
}
}
}
format++;
}

va_end(args);

return (printed_chars);
}
