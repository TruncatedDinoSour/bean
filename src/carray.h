#ifndef _CARRAY_H
#define _CARRAY_H
#include <stddef.h>

#define CARRAY_INITIAL_SIZE 12
#define CARRAY_IDX(carr)    (carr).size - 1
#define CARRAY_PIDX(carr)   (carr)->size - 1

typedef struct {
    size_t size, cap;
    char **arr;
} CArray;

void carray_check(CArray *);
void carray_append(CArray *, char *);
void carray_clear(CArray *);
void carray_destroy(CArray *);
#endif /* _CARRAY_H */
