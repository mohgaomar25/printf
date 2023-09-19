#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>

static int print_char(int c);
static int print_str(const char *str);
static int print_int(int n);
int _printf(const char *format, ...);

#endif /* MAIN_H */
