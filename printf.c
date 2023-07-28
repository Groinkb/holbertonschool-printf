#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Write a character to the standard output (file descriptor 1).
 *
 * @c: The character to be written.
 *
 * Return: On success, 1 is returned. On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Print formatted output with variable arguments.
 *
 * This function prints formatted output with variable arguments. It supports
 * replacing '%d' or '%i' with an integer value, '%s' with a null-terminated string,
 * '%c' with a character, and '%%' with a literal '%'.
 *
 * @format: The formatted string to print.
 *
 * Return: The number of characters printed (excluding the null terminator).
 */
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
				if (value == NULL)
					value = "(null)";
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

	return (printed_chars);
}
