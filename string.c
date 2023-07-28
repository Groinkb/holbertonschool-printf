#include <unistd.h>
#include <stdarg.h>

/**
 * string - Print a formatted string with string substitution.
 *
 * This function prints a formatted string with string substitution. It supports
 * replacing '%s' with a null-terminated string.
 *
 * @format: The formatted string to print.
 *
 * Return: The number of characters printed (excluding the null terminator).
 */
int string(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	const char *str;

	va_start(args, format);

	for (str = format; str && *str != '\0'; str++)
	{
		if (*str == 's')
		{
			char *str = va_arg(args, char *);
			int len = 0;
			while (str[len])
			{
				len++;
			}
			printed_chars += write(1, str, len);
		}
		else
		{
			printed_chars += write(1, str, 1);
		}
	}

	va_end(args);
	return (printed_chars);
}
