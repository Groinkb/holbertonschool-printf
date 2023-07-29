#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*
 * This function prints formatted output to the standard output, similar to printf,
 * but only supports the %d format specifier for integers. It takes a format string
 * and a variable number of arguments and prints the formatted output to the console.
 *
 * Parameters:
 *   format: A pointer to a format string containing the text to be printed, along with
 *           optional format specifiers.
 *   ...   : Variable arguments list, corresponding to the format specifiers in the
 *           format string. Currently, only integers are supported (%d).
 *
 * Returns:
 *   The number of characters printed to the standard output.
 */

int decimal(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	const char *str;
	char *p;

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
				for (p = buffer; *p != '\0'; p++)
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
