#include "common.h"

void putchar(char ch);


/* The memset fills the first n bytes of buf with c */
void *memset(void *buf, char c, size_t n)
{
    uint8_t *b = (uint8_t *)buf;

    while (n--)
        *b++ = c;

    return buf;
}

/* The memcpy copies n bytes from src to dst */
void *memcpy(void *dst, const void *src, size_t n)
{
    uint8_t *d = (uint8_t *) dst;
    const uint8_t *s = (const uint8_t *) src;

    while (n--) 
        *d++= *s++;

    return  dst;
}

/* The strcpy copies the string from src to dst */
char *strcpy(char *dst, const char *src)
{
    char *d = dst;

    while(*src)
        *d++ = *src++;

    *d = '\0';
    return dst;
}

/* The strcpy_s copies the string from src to dst within the limits of dst_size */
char *strcpy_s(char *dst, size_t dst_size, const char *src)
{
    if (dst_size == 0)
        return dst;

    char *d = dst;
    size_t left = dst_size - 1; // reserve for '\0'

    while(*src && left > 0)
        *d = *src;

    *d = '\0';
    return dst;
}

/* 
    The strcmp compares s1 and s2 and return digital: 0, positive, negative 
    return 0 - s1 == s2
    return positive - s1 > s2
    return negative - s1 < s2
*/
int strcmp(const char *s1, const char *s2)
{
    while(*s1 && *s2)
    {
        if (*s1 != *s2) break;

        s1++;
        s2++;
    }

    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void printf(const char *fmt, ...)
{
    va_list vargs;
    va_start(vargs, fmt);

    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++; // Skip '%'

            switch (*fmt) // Read the next character
            {
                case '\0':
                    putchar('%');
                    goto end;
                case '%': // Print '%'
                    putchar('%');
                    break;
                case 's': // Print a NULL-terminated string
                {
                    const char *s = va_arg(vargs, const char *);

                    while (*s)
                    {
                        putchar(*s);
                        s++;
                    }

                    break;
                }
                case 'd': // Print an integer in decimal
                {
                    int value = va_arg(vargs, int);
                    unsigned magnitude = value;
                    if (value < 0)
                    {
                        putchar('-');
                        magnitude = -magnitude;
                    }

                    unsigned divisor = 1;
                    while (magnitude / divisor > 9)
                        divisor *= 10;

                    while (divisor > 0)
                    {
                        putchar('0' + magnitude / divisor);
                        magnitude %= divisor;
                        divisor /= 10;
                    }

                    break;
                }
                case 'x': // Print an integer in hexadecimal
                {
                    unsigned value = va_arg(vargs,unsigned);
                    for (int i = 7; i >= 0; i--)
                    {
                        unsigned nibble = (value >> (i * 4)) & 0xf;
                        putchar("0123456789abcdef"[nibble]);
                    }
                }
            }
        }
        else putchar(*fmt);

        fmt++;
    }
    
    end:
        va_end(vargs);
}