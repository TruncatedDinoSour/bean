#ifndef _LOGGING_H
#define _LOGGING_H
#include "clrs.h"
#include <stdio.h>

#define LOG_PRINT(head, clr, fmt, ...) \
    printf(clr head CLR_RESET " " fmt, __VA_ARGS__)

#define FLOG_NORMAL(fmt, msg) LOG_PRINT("log  ", CLR_BOLD, fmt, msg)
#define LOG_NORMAL(msg)       FLOG_NORMAL("%s\n", msg)

#define FLOG_INFO(fmt, msg) LOG_PRINT("info ", CLR_BOLD CLR_BLUE, fmt, msg)
#define LOG_INFO(msg)       FLOG_INFO("%s\n", msg)

#define FLOG_ERROR(fmt, msg) LOG_PRINT("error", CLR_BOLD CLR_RED, fmt, msg)
#define LOG_ERROR(msg)       FLOG_ERROR("%s\n", msg)
#define FLOG_ERROR_RET(fmt, msg) \
    do {                         \
        FLOG_ERROR(fmt, msg);    \
        return 1;                \
    } while (0)
#define LOG_ERROR_RET(msg) \
    do {                   \
        LOG_ERROR(msg);    \
        return 1;          \
    } while (0)
#endif /* _LOGGING_H */
