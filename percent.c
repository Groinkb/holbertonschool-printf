#include "main.h"

/**
 * percent - Print a formatted string with '%' handling.
 *
 * This function prints a formatted string with '%' handling. It is similar to
 * the printf function, but only supports printing '%' character as a literal.
 *
 * @format: The formatted string to print.
 *
 * Return: The number of characters printed (excluding the null terminator).
 */

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
				write(1, format, 1);
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
