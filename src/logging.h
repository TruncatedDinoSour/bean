#ifndef _LOGGING_H
#define _LOGGING_H
#include <stdarg.h>

#include "types.h"

void vlog_print(String, String, String, va_list)
    __attribute__((format(printf, 3, 0)));
void log_print(String, String, String, ...)
    __attribute__((format(printf, 3, 4)));

void flog_normal(String, ...) __attribute__((format(printf, 1, 0)));
void log_normal(String);

void flog_info(String, ...) __attribute__((format(printf, 1, 0)));
void log_info(String);

unsigned char flog_error(String, ...) __attribute__((format(printf, 1, 0)));
unsigned char log_error(String);
#endif /* _LOGGING_H */
