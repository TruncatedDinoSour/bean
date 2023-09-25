#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "line.h"
#include "types.h"

Line *line_split(String line) {
    size_t argv_bound = LINE_ARGV_INC, length = strlen(line);
    char *token, *buffer = malloc((length + 1) * sizeof(*buffer));
    Line *result = malloc(sizeof(*result));

    result->argc = 0;
    result->argv = malloc(argv_bound * sizeof(*result->argv));

    memcpy(buffer, line, length + 1);

    token = strtok(buffer, " ");

    while (token != NULL) {
        if (result->argc >= argv_bound) {
            argv_bound += LINE_ARGV_INC;
            result->argv =
                realloc(result->argv, argv_bound * sizeof(*result->argv));
        }

        result->argv[result->argc] = malloc(strlen(token) + 1);
        memcpy(result->argv[result->argc++], token, strlen(token) + 1);

        token = strtok(NULL, " ");
    }

    free(buffer);

    return result;
}

void line_destroy(Line *line) {
    if (line->argc > 0)
        while (line->argc--)
            free(line->argv[line->argc]);

    free(line->argv);
    free(line);
}
