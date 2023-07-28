#include <unistd.h>
#include <stdarg.h>

int s (const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;

    while (*format)
    {
        if (*format == 's')
        {
            char *str = va_arg(args, char *);
            int len = 0;
            while (str[len])
            {
                len++;
            }
            write(1, str, len);
            printed_chars += len;
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}