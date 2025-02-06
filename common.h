#pragma once

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
#define va_arg __builtin_va_arg

void printf(const char *fmt, ...);
