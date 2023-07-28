#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * decimal - Print formatted output with integer substitution.
 *
 * This function prints formatted output with integer substitution. It supports
 * printing '%' character as a literal and replacing '%d' with an integer value.
 *
 * @format: The formatted string to print.
 *
 * Return: The number of characters printed (excluding the null terminator).
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

	return (printed_chars);
}
