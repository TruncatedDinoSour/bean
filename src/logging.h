#ifndef _LOGGING_H
#define _LOGGING_H
#include "types.h"

void log_print(String, String, String, ...)
    __attribute__((format(printf, 3, 4)));

void flog_normal(String, String);
void log_normal(String);

void flog_info(String, String);
void log_info(String);

unsigned char flog_error(String, String);
unsigned char log_error(String);
#endif /* _LOGGING_H */
