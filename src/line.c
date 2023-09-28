#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "line.h"
#include "types.h"
#include "carray.h"

void line_split(CArray *arr, String line) {
    size_t length = strlen(line);
    char *token, *buffer = malloc((length + 1) * sizeof(*buffer));

    line_clear(arr);
    memcpy(buffer, line, length + 1);

    token = strtok(buffer, " ");

    while (token != NULL) {
        carray_append(arr, malloc(strlen(token) + 1));
        memcpy(arr->arr[CARRAY_PIDX(arr)], token, strlen(token) + 1);
        token = strtok(NULL, " ");
    }

    free(buffer);
}

void line_clear(CArray *arr) {
    if (arr->size) {
        while (arr->size--)
            free(arr->arr[arr->size]);

        carray_clear(arr);
    }
}

void line_destroy(CArray *arr) {
    line_clear(arr);
    carray_destroy(arr);
}
