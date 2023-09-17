#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
	char c;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1); /* Print the character */
			printed_chars++;
		}
		else
		{
			format++; /* Move past '%' */
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					printed_chars++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						write(1, str, 1);
						str++;
						printed_chars++;
					}
					break;
				case '%':
					write(1, "%", 1);
					printed_chars++;
					break;
				default:
					write(1, "%", 1); /* Print '%' as default */
					printed_chars++;
					if (*format)
					{
						write(1, format, 1); /* Print the unknown format specifier */
						printed_chars++;
					}
			}
		}
		format++; /* Move to the next character in the format string */
	}

	va_end(args);

	return printed_chars;
}
