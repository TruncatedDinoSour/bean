#ifndef _LINE_H
#define _LINE_H
#include <stddef.h>

typedef struct {
    size_t argc;
    char **argv;
} Line;

Line *split_line(char *);
#endif /* _LINE_H */
