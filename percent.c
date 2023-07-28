#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int percent(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				printed_chars++;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
		format++;
	}

	va_end(args);
	return printed_chars;
}
