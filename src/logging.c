#include <stdio.h>
#include <stdarg.h>

#include "clrs.h"
#include "logging.h"
#include "types.h"

void log_print(String head, String clr, String fmt, ...) {
    va_list args;
    va_start(args, fmt);

    fprintf(stdout, "%s%s%s ", clr, head, CLR_RESET);
    vfprintf(stdout, fmt, args);

    va_end(args);
}

void flog_normal(String fmt, String msg) {
    log_print("log  ", CLR_BOLD, fmt, msg);
}

void log_normal(String msg) { flog_normal("%s\n", msg); }

void flog_info(String fmt, String msg) {
    log_print("info ", CLR_BOLD CLR_BLUE, fmt, msg);
}

void log_info(String msg) { flog_info("%s\n", msg); }

unsigned char flog_error(String fmt, String msg) {
    log_print("error", CLR_BOLD CLR_RED, fmt, msg);
    return 1;
}

unsigned char log_error(String msg) {
    flog_error("%s\n", msg);
    return 1;
}
