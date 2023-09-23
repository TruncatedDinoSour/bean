#include <stdio.h>
#include <stdarg.h>

#include "clrs.h"
#include "types.h"
#include "logging.h"

void vlog_print(String head, String clr, String fmt, va_list args) {
    fprintf(stdout, "%s%s" CLR_RESET " ", clr, head);
    vfprintf(stdout, fmt, args);
}

void log_print(String head, String clr, String fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vlog_print(head, clr, fmt, args);

    va_end(args);
}

void flog_normal(String fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vlog_print("log  ", CLR_BOLD, fmt, args);

    va_end(args);
}

void log_normal(String msg) { flog_normal("%s\n", msg); }

void flog_info(String fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vlog_print("info ", CLR_BOLD CLR_BLUE, fmt, args);

    va_end(args);
}

void log_info(String msg) { flog_info("%s\n", msg); }

UChar flog_error(String fmt, ...) {
    va_list args;
    va_start(args, fmt);

    vlog_print("error", CLR_BOLD CLR_RED, fmt, args);

    va_end(args);
    return 1;
}

UChar log_error(String msg) {
    flog_error("%s\n", msg);
    return 1;
}
