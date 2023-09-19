#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_int - Prints an integer to stdout
 * @n: The integer to be printed
 * Return: The number of characters printed
 */
static int print_int(int n)
{
	int printed_chars = 0;

 /* Handle negative numbers*/
	if (n < 0)
	{
		printed_chars += print_char('-');
		n = -n;
	}

	/* Handle digits one by one*/
	if (n / 10)
	{
		printed_chars += print_int(n / 10);
	}
	printed_chars += print_char((n % 10) + '0');

	return (printed_chars);
}