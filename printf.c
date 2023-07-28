/**
 * Custom putchar function that writes a character to the standard output (stdout).
 *
 * @param c The character to be written.
 * @return On success, the number of characters written is returned. 
 * On failure, -1 is returned.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * Custom printf function that prints formatted output to the standard output (stdout).
 * It supports format specifiers: %d, %i, %s, %c, and %%
 *
 * @param format The format string containing the characters to print.
 * @param ... The optional arguments based on format specifiers.
 * @return The total number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    const char *str;
    int printed_chars = 0;

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
                    
                    sprintf(buffer, "%d", value);
                    for (char *p = buffer; *p != '\0'; p++)
                    {
                        _putchar(*p);
                        printed_chars++;
                    }
                    break;
                }
                case 's':
                {
                    char *value = va_arg(args, char *);
                    for (char *p = value; *p != '\0'; p++)
                    {
                        _putchar(*p);
                        printed_chars++;
                    }
                    break;
                }
                case 'c':
                {
                    char value = (char)va_arg(args, int);
                    _putchar(value);
                    printed_chars++;
                    break;
                }
                case '%':
                    _putchar('%');
                    printed_chars++;
                    break;
                default:
                    
                    break;
            }
            str++;
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
