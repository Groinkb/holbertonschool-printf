#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*
 * d - function to print formatted output
 * @format: format string
 * ...
 * Return: number of characters printed
 */
int d(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	const char *str;
	char buffer[20];
	char *p;
	int num;

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
				num = va_arg(args, int);
				snprintf(buffer, sizeof(buffer), "%d", num);
				p = buffer;

				while (*p != '\0')
				{
					_putchar(*p);
					printed_chars++;
					p++;
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

	return (printed_char)s;
}
