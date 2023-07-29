#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * decimal - Custom print function that prints formatted output to the standard output,
 *           supporting the %d format specifier for integers.
 *
 * @format: A pointer to a format string containing the text to be printed, along with
 *          optional format specifiers.
 * @...   : Variable arguments list, corresponding to the format specifiers in the
 *          format string. Currently, only integers are supported (%d).
 *
 * Return: The number of characters printed to the standard output.
 *
 * Note: This function should be used with care and not as a replacement for the standard
 *       printf function, as it has limited functionality and only supports a subset of
 *       format specifiers. It is mainly intended for demonstration purposes or when
 *       advanced formatting is not required.
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
