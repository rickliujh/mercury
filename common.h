#pragma once

typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
// long is platform specific meaning it could be 32 bit or 64 bit
// long long in C guarantees you will get a 64 bit int
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
// represents physical memory address
typedef uint32_t paddr_t;
// represents virtual mem addr, equivalent to uintptr_t
typedef uint32_t vaddr_t;

#define true                     1
#define false                    0
#define NULL                     ((void *)0)
#define align_up(value, align)   __builtin_align_up(value, align)
#define is_aligned(value, align) __builtin_is_aligned(value, align)
// returns the offset of a member within a structure (how many bytes from the
// start of the structure).
#define offsetof(type, member) __builtin_offsetof(type, member)

/* Variable Argument Lists */

// va_list: This is a type that holds the information needed to retrieve the
// additional arguments. Before you use this type, you must declare a variable
// of type va_list.
#define va_list __builtin_va_list
// va_start: This macro initializes a va_list variable to retrieve the
// additional arguments. It must be called before you use va_arg to access the
// arguments. The first argument is the va_list variable, and the second
// argument is the last named argument of the function (the one right before the
// ellipsis ...).
#define va_start __builtin_va_start
// va_arg: This macro retrieves the next argument in the list. The first
// argument is the va_list variable, and the second argument is the type of the
// next argument (for example, int, double, etc.).
#define va_end __builtin_va_end
// va_end: This macro cleans up the va_list variable. It must be called after
// you have finished accessing the additional arguments.
#define va_arg    __builtin_va_arg
#define PAGE_SIZE 4096

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
void printf(const char *fmt, ...);
