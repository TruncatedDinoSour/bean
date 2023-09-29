#ifndef _FILE_H
#define _FILE_H
#define LINE_GROWTH 256

#include "types.h"

char *read_line(int);
void free_line(char *);
#endif /* _FILE_H */
