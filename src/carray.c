#include <stdlib.h>

#include "carray.h"

void carray_append(CArray *carr, char *item) {
    if (carr->arr == NULL) {
        carr->size = 0;
        carr->cap = CARRAY_INITIAL_SIZE;
        carr->arr = malloc(carr->cap * sizeof(*carr->arr));
    }

    if (carr->size >= carr->cap) {
        carr->cap += CARRAY_INITIAL_SIZE;
        carr->arr = realloc(carr->arr, carr->cap * sizeof(*carr->arr));
    }

    carr->arr[carr->size++] = item;
}

void carray_destroy(CArray *carr) {
    free(carr->arr);
}
