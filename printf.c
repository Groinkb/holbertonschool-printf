#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
	return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	const char *str;
	char *p;

	va_start(args, format);

	for (str = format; str && *str != '\0'; str++)
	{
		if (*str == '%')
		{
			switch (*(str + 1))
			{
			case 'd':
			case 'i':
			{
				int value = va_arg(args, int);
				char buffer[20];
				snprintf(buffer, sizeof(buffer), "%d", value);
				for (p = buffer; *p != '\0'; p++)
				{
					printed_chars += _putchar(*p);
				}
				break;
			}
			case 's':
			{
				char *value = va_arg(args, char *);
				for (p = value; *p != '\0'; p++)
				{
					printed_chars += _putchar(*p);
				}
				break;
			}
			case 'c':
			{
				char value = (char)va_arg(args, int);
				printed_chars += _putchar(value);
				break;
			}
			case '%':
				printed_chars += _putchar('%');
				break;
			default:
				break;
			}
			str++;
		}
		else
		{
			printed_chars += _putchar(*str);
		}
	}

	va_end(args);

	return printed_chars;
}
