#include "common.h"

void putchar(char ch);

void
printf(const char *fmt, ...) {
    // Variable Argument Lists
    va_list vargs;
    va_start(vargs, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            switch (*fmt) {
            // '\0' is null terminator - we're at the end of the string
            case '\0': { // '%' at the end of format string
                putchar('%');
                goto end;
            }
            case '%': {
                putchar('%');
                break;
            }
            case 's': {
                const char *s = va_arg(vargs, const char *);
                while (*s) { // Print a NULL-terminated ('\0") string
                    putchar(*s);
                    s++;
                }
                break;
            }
            case 'd': {
                int value = va_arg(vargs, int);
                if (value < 0) {
                    putchar('-');
                    value = -value;
                }

                int divisor = 1;
                while (value / divisor > 9) {
                    divisor *= 10;
                }

                while (divisor > 0) {
                    // add leftmost digit of the number to ascll char '0' in
                    // order to have corresponding digit character in ascll
                    putchar('0' + value / divisor);
                    value %= divisor;
                    divisor /= 10;
                }

                break;
            }
            case 'x': {
                int value = va_arg(vargs, int);
                // 4bit contains 1 hexadecimal so 32bit integer has 8 hex digits
                // iterates 8 times (from 7 down to 0), exactly the number of
                // hexadecimal digits in a 32-bit integer.
                for (int i = 7; i >= 0; i--) {
                    // right bitwise shift corresponding to i to access each hex
                    // digit and &(and) to 0xf to isolate another 7 digit except
                    // the last 4 that just got right shift to
                    int nibble = (value >> (i * 4)) & 0xf;
                    // use nibble as decimal index to obtain corresponding hex
                    // character from array
                    putchar("0123456789abcdef"[nibble]);
                }

                break;
            }
            }
        } else {
            putchar(*fmt);
        }

        fmt++;
    }

end:
    va_end(vargs);
}
