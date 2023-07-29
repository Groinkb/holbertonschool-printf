#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * integer - Custom print function that prints formatted
 *  output to the standard output,
 *           supporting the %i format specifier for integers.
 * @format: A pointer to a format string containing the text to be printed, along with
 *          optional format specifiers.
 * @...   : Variable arguments list, corresponding to
 * the format specifiers in the
 *          format string. Currently, only integers are supported (%i).
 *
 * Return: The number of characters printed to the standard output.
 * Note: This function behaves similarly to printf, but with limited functionality. It
 *       supports the %i format specifier for printing
 * integers. The function calculates
 *       the number of digits in the integer and prints
 * it digit by digit. If the integer
 *       is negative, it will be printed with a leading '+' sign.
 *  The function is mainly
 *       intended for demonstration purposes
 * or when advanced formatting is not required.
 */
int integer(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

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
			else if (*format == 'i')
			{
				int num = va_arg(args, int);
				int num_len = 1;
				int temp = num;
				int i, j;

				if (num < 0)
				{
					num_len++;
					num *= -1;
				}
				while (temp /= 10)
					num_len++;

				if (num < 0)
				{
					_putchar('+');
					num *= -1;
				}

				for (i = 0; i < num_len; i++)
				{
					int divisor = 1;
					int digit;
					for (j = 0; j < num_len - i - 1; j++)
						divisor *= 10;
					digit = num / divisor;
					num %= divisor;
					printed_chars += _putchar('0' + digit);
				}
				format++;
			}
			else
			{
				printed_chars += _putchar(*format);
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}
		format++;
	}

	va_end(args);
	return printed_chars;
}
