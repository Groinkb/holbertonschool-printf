#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * percent - Custom print function that prints formatted output to the standard output,
 *           handling double percent signs "%%" and printing other characters as is.
 *
 * @format: A pointer to a format string containing the text to be printed, along with
 *          optional format specifiers.
 * @...   : Variable arguments list, corresponding to the format specifiers in the
 *          format string. Currently, no format specifiers are supported.
 *
 * Return: The number of characters printed to the standard output.
 *
 * Note: This function behaves like a simpler version of printf and is mainly intended
 *       for demonstration purposes or when advanced formatting is not required. It
 *       supports the "%%" format specifier to print a single percent sign. All other
 *       characters in the format string are printed as is.
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
