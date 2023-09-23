#ifndef _LOGGING_H
#define _LOGGING_H
void log_print(const char *, const char *, const char *, ...) __attribute__((format(printf, 3, 4)));

void flog_normal(const char *, const char *);
void log_normal(const char *);

void flog_info(const char *, const char *);
void log_info(const char *);

unsigned char flog_error(const char *, const char *);
unsigned char log_error(const char *);
#endif /* _LOGGING_H */
