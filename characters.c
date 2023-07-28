#include <unistd.h>
#include <stdarg.h>

int characters(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
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
