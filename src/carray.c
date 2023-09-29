#include <stdlib.h>

#include "carray.h"

void carray_check(CArray *carr) {
    if (carr->arr == NULL) {
        carr->size = 0;
        carr->cap = CARRAY_INITIAL_SIZE;
        carr->arr = malloc(carr->cap * sizeof(*carr->arr));
    }

    if (carr->size >= carr->cap) {
        carr->cap += CARRAY_INITIAL_SIZE;
        carr->arr = realloc(carr->arr, carr->cap * sizeof(*carr->arr));
    }
}

void carray_append(CArray *carr, char *item) {
    carray_check(carr);
    carr->arr[carr->size++] = item;
}

void carray_clear(CArray *carr) {
    carr->size = 0;
}

void carray_destroy(CArray *carr) {
    free(carr->arr);

    carr->arr = NULL;
    carr->size = 0;
    carr->cap = 0;
}
