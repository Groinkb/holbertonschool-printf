#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int integer(const char *format, ...)
{
	va_list args;
	const char *str;
	int printed_chars = 0;
	int i, j;

	va_start(args, format);

	for (str = format; str && *str != '\0'; str++)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'i')
			{
				int num = va_arg(args, int);
				int num_len = 1;
				int temp = num;

				if (num < 0)
				{
					num_len++;
					num *= -1;
				}
				while (temp /= 10)
					num_len++;

				if (num < 0)
				{
					printed_chars += _putchar('+');
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
				str++;
			}
			else
			{
				printed_chars += _putchar(*str);
			}
		}
		else
		{
			printed_chars += _putchar(*str);
		}
	}

	va_end(args);

	return printed_chars;
}
