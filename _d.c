#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int d (const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    const char *str;

    va_start(args, format);

    for (str = format; str && *str != '\0'; str++)
    {
        if (*str == '%')
        {
            if (*(str + 1) == '%')
            {
                _putchar('%');
                printed_chars++;
                str++;
            }
            else if (*(str + 1) == 'd')
            {
                int num = va_arg(args, int);
                char buffer[20];
                snprintf(buffer, sizeof(buffer), "%d", num);
                for (char *p = buffer; *p != '\0'; p++)
                {
                    _putchar(*p);
                    printed_chars++;
                }
                str++;
            }
            else
            {
                _putchar(*str);
                printed_chars++;
            }
        }
        else
        {
            _putchar(*str);
            printed_chars++;
        }
    }

    va_end(args);

    return printed_chars;
}