#include "common.h"

void putchar(char ch);

void *
memcpy(void *dst, const void *src, size_t n) {
    // copy byte by byte
    uint8_t *d = dst;
    const uint8_t *s = src;
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}

void *
memset(void *buf, char c, size_t n) {
    uint8_t *p = (uint8_t *)buf;
    while (n--) {
        *p++ = c;
    }
    return buf;
}

// The strcpy function continues copying even if src is longer than the memory
// area of dst. This can easily lead to bugs and vulnerabilities, so it's
// generally recommended to use alternative functions instead of strcpy.
// TODO: implementing and using an alternative function (strcpy_s) instead.
char *
strcpy(char *dst, const char *src) {
    char *d = dst;
    // stop if *src != '\0'
    while (*src) {
        *d++ = *src++;
    }
    *d = '\0';
    return dst;
}

int
strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            break;
        }
        s1++, s2++;
    }
    // The casting to unsigned char * when comparing is done to conform to the
    // POSIX specification. See:
    // https://www.man7.org/linux/man-pages/man3/strcmp.3.html#:~:text=both%20interpreted%20as%20type%20unsigned%20char
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

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
