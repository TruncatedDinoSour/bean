#ifndef _LINE_H
#define _LINE_H
#include "carray.h"
#include "types.h"

void line_split(CArray *, String);
void line_clear(CArray *);
void line_destroy(CArray *);
#endif /* _LINE_H */
