#include <unistd.h>
#include <stdlib.h>

#include "file.h"
#include "types.h"

char *read_line(int fd) {
    size_t bufsize = LINE_GROWTH, position = 0;
    ssize_t read_size;
    char *buffer, *new_buffer, c;

    if ((buffer = malloc(bufsize)) == NULL)
        return NULL; /* failed to allocate memory */

    while ((read_size = read(fd, &c, 1)) > 0) {
        if (c == '\0' || c == '\n' || c == '\r') {
            buffer[position] = '\0'; /* null-terminate the string */
            return buffer; /* return the line */
        }

        buffer[position++] = c;

        /* resize buffer if necessary */

        if (position >= bufsize) {
            bufsize += LINE_GROWTH;

            if ((new_buffer = realloc(buffer, bufsize)) == NULL) {
                free(buffer);
                return NULL; /* failed to reallocate memory */
            }

            buffer = new_buffer;
        }
    }

    /* check for read error or end of file */

    if (read_size < 0) {
        free(buffer);
        return NULL; /* read error */
    }

    /* no more lines to read */

    free(buffer);
    return NULL;
}
