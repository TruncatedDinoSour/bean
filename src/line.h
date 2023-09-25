#ifndef _LINE_H
#define _LINE_H
#include <stddef.h>
#include "types.h"

#define LINE_ARGV_INC 5

typedef struct {
    size_t argc;
    char **argv;
} Line;

Line *line_split(String);
void line_destroy(Line *);
#endif /* _LINE_H */
