#include "main.h"
#include <unistd>
#include <stdarg.h>

/**
 * _printf - function to print strings
 * @format: the format to Hunde
 * Return: int
 */

int _print(const char *format, ...)
{
	int number_to_print = 0;
	va_list List_of_numbers;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(List_of_numbers, format);

	while (*format)
	{
		if (format == 'd')
		{

			int number_to_print = va_arg(List_of_numbers, int);

			write(1, &format, int);
		}
	}
	va_end(List_of_numbers);
	return (number_to_print);
}
