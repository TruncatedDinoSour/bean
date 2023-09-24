#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "line.h"

Line *split_line(char *line) {
    size_t argc = 1, idx = 0, jdx, tlen;
    char **argv = NULL, *token;
    Line *l     = NULL;

    for (jdx = 0; line[jdx] != '\0'; ++jdx)
        if (line[jdx] == ' ')
            argc++;

    /* allocate argv */

    if ((argv = malloc(argc * sizeof(*argv))) == NULL)
        goto __split_line_cleanup; /* argv allocation failure */

    /* split argv */

    token = strtok(line, " ");

    while (token != NULL) {
        tlen      = strlen(token);
        argv[idx] = malloc(tlen + 1);

        if (argv[idx] == NULL)
            goto __split_line_cleanup; /* argument allocation failure */

        memcpy(argv[idx], token, tlen + 1);

        token = strtok(NULL, " ");
        ++idx;
    }

    if ((l = malloc(sizeof(Line))) == NULL)
        goto __split_line_cleanup; /* `Line` allocation failure */

    l->argc = argc;
    l->argv = argv;

    return l;

__split_line_cleanup: /* memory cleanup in case of error */
    if (argv != NULL) {
        for (jdx = 0; jdx < idx; ++jdx)
            free(argv[jdx]);

        free(argv);
    }

    if (l != NULL)
        free(l);

    return NULL;
}
