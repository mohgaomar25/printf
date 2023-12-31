#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * print_char - Prints a single character to stdout
 * @c: The character to be printed
 * Return: The number of characters printed
 */
int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Prints a string to stdout
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int print_str(const char *str)
{
	int printed_chars = 0;

	while (*str)
	{
		printed_chars += write(1, str, 1);
		str++;
	}
	return (printed_chars);
}

/**
 * print_int - Prints an integer to stdout
 * @n: The integer to be printed
 * Return: The number of characters printed
 */
int print_int(int n)
{
	int printed_chars = 0;

	if (n == 0)
	{
		printed_chars += print_char('0');
		return (1);
	}
	if (n < 0)
	{
		printed_chars += print_char('-');
		n = -n;
	}
	if (n / 10)
	{
		printed_chars += print_int(n / 10);
	}
	printed_chars += print_char((n % 10) + '0');
	return (printed_chars);
}

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
			printed_chars += print_char(*format);
		else
		{
			format++;
			if (*format == 'c')
				printed_chars += print_char(va_arg(args, int));
			else if (*format == 's')
				printed_chars += print_str(va_arg(args, char *));
			else if (*format == '%')
				printed_chars += print_char('%');
			else if (*format == 'd' || *format == 'i')
				printed_chars += print_int(va_arg(args, int));
			else
			{
				printed_chars += print_char('%');
				if (*format)
				printed_chars += print_char(*format);
			}
		}
		format++;
	}
	va_end(args);

	return (printed_chars);
}
