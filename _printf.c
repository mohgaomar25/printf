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
          printed_chars += print_int(va_arg(args, int));
          break;
	  
	 /*case 'i':
          printed_chars += print_char(va_arg(args, int));
	  break;*/
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
