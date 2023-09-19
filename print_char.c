#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a single character to stdout
 * @c: The character to be printed
 * Return: The number of characters printed
 */
static int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Prints a string to stdout
 * @str: The string to be printed
 * Return: The number of characters printed
 */
static int print_str(const char *str)
{
	int printed_chars = 0;

	while (*str)
	{
		printed_chars += write(1, str, 1);
		str++;
	}
	return (printed_chars);
}
