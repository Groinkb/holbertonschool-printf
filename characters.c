#include <unistd.h>
#include <stdarg.h>

/**
 * characters - Print characters from a formatted string.
 *
 * This function prints characters from a formatted string. It takes a variable
 * number of arguments and supports printing individual characters using the
 * format specifier '%c'.
 *
 * @format: The formatted string to print.
 *
 * Return: The number of characters printed (excluding the null terminator).
 */
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
	return (printed_chars);
}
