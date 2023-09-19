#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: The number of characters written.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_char - Print a character.
 * @args: The va_list containing the character argument.
 * @printed_chars: The pointer to the count of printed characters.
 */
void print_char(va_list args, int *printed_chars)
{
char c = va_arg(args, int);
*printed_chars += _putchar(c);
}

/**
 * print_string - Print a string.
 * @args: The va_list containing the string argument.
 * @printed_chars: The pointer to the count of printed characters.
 */
void print_string(va_list args, int *printed_chars)
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)";
while (*str)
*printed_chars += _putchar(*str++);
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;

va_start(args, format);

while (*format)
{
if (*format != '%')
{
printed_chars += _putchar(*format);
}
else
{
format++;
if (*format == '\0')
break;

switch (*format)
{
case 'c':
print_char(args, &printed_chars);
break;
case 's':
print_string(args, &printed_chars);
break;
case '%':
printed_chars += _putchar('%');
break;
default:
printed_chars += _putchar('%');
printed_chars += _putchar(*format);
}
}
format++;
}

va_end(args);
return (printed_chars);
}
