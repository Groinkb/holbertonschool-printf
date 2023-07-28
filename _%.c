#include "main.h"

/**
 * Prints characters from the provided `format` string to the standard output (stdout).
 * This function handles special '%' characters to avoid unintended formatting issues
 * and returns the total number of characters printed.
 *
 * @param format The format string containing the characters to print.
 * @return The total number of characters printed.
 */
int percent(const char *format, ...)
{
    va_list args;
    va_start(args, format); 

    int printed_chars = 0; 

    while (*format) 
    {
        if (*format == '%')
        {
            format++; 

            if (*format == '%') 
            {
                write(1, format, 1); 
                printed_chars++; 
            }
        }
        else 
        {
            write(1, format, 1); 
            printed_chars++; 
        }

        format++; 
    }

    va_end(args); 

    return printed_chars;
}
