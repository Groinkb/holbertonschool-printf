#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct print
{
    char *type;
    int(*f)(va_list arg);
} print_t;

int _printf(const char *format, ...);
int _printf_char(va_list ap);
int _printf_string(va_list ap);
int _printf_percent(va_list ap);

#endif
