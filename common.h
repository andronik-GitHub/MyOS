#ifndef CPP_OS__COMMON_H
#define CPP_OS__COMMON_H

typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;

#define true 1
#define false 0
#define NULL ((void*)0)
#define align_up(value, align)   __builtin_align_up(value, align)
#define is_aligned(value, align) __builtin_is_aligned(value, align)
#define offsetof(type, member)   __builtin_offsetof(type, member)
#define va_list  __builtin_va_list  // змінна-"курсор", що вміє ходити по додаткових аргументах
#define va_start __builtin_va_start // поставити курсор на перший аргумент після fmt
#define va_end   __builtin_va_end   // прочитати поточний аргумент як вказаний тип і пересунути курсор далі
#define va_arg   __builtin_va_arg   // завершити роботу з курсором (прибрати за собою)
#define PAGE_SIZE 4096

#define SYS_PUTCHAR 1
#define SYS_GETCHAR 2
#define SYS_EXIT 3


void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
char *strcpy(char *dst, const char *src);
char *strcpy_s(char *dst, size_t dst_size, const char *src);
int strcmp(const char *s1, const char *s2);
void printf(const char *fmt, ...);

#endif