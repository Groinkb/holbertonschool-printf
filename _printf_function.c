#include "main.h"
#include <string.h>

int _printf_char(va_list ap)
{
        char c = va_arg(ap, int);
        return write(1, &c, 1);
}

int _printf_string(va_list ap)
{
    char *s = va_arg(ap, char *);
    if (s == NULL)
        s = "(null)";
    return write(1, s, strlen(s));
}

int _printf_percent(va_list ap __attribute__((unused)))
{
	return write(1, "%", 1);
}

int _printf(const char *format, ...)
{
        va_list ap;
        int i = 0, j = 0, count = 0;

        print_t types[] = {
        {"c", _printf_char},
	{"s", _printf_string},
	{"%", _printf_percent},
        {NULL, NULL}
        };

        va_start(ap, format);

        while (format && format[i])
        {
                if (format[i] == '%')
                {
                        j = 0;
			i++;

                        while (types[j].type != NULL)
                        {
                                if (format[i] == types[j].type[0])
                                {
					if (types[j].type[0] == '%')
						count += types[j].f(ap);

					else
						count += types[j].f(ap);
                                }

                                j++;
                        }
                }

                else
                {
                        count += write(1, &format[i], 1);
                }
                i++;
        }

        va_end(ap);
        return (count);
}
