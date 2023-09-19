#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = parse_format(format, args);
	va_end(args);

	return (count);
}

/**
 * parse_format - Parse and print the format string
 * @format: Format string
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int parse_format(const char *format, va_list args)
{
	int i, count = 0;
	char c;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			c = format[i];
			if (c == 'c')
				count += print_char(args);
			else if (c == 's')
				count += print_string(args);
			else if (c == '%')
				count += _putchar('%');
			else
			{
				_putchar('%');
				_putchar(c);
				count += 2;
			
			}
			else
			{
				_putchar(format[i]);
				count++;
			}
		}
		return (count);
}

/**
 * print_char - Print a character
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * print_string - Print a string
 * @args: Arguments list
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}

/**
 * _putchar - Custom putchar function
 * @c: Character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
