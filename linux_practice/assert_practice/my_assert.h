#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdio.h>
#include <stdlib.h>

static void my_assert_fail(const char *expr,
                           const char *file,
                           int line,
                           const char *func)
{
    fprintf(stderr,
            "%s: %s:%d: %s: Assertion `%s' failed.\n",
            "assert_test", file, line, func, expr);

    abort();
}

#ifdef NDEBUG
#define my_assert(expr) ((void)0)
#else
#define my_assert(expr) \
    ((expr) ? (void)0 : \
    my_assert_fail(#expr, __FILE__, __LINE__, __func__))
#endif

#endif
