#ifndef _COMMANDS_H
#define _COMMANDS_H

typedef struct {
    const char *const name;
    int (*cmd)(char **);
} Command;

const Command *find_command(const char *const, const Command *);

#ifdef COMMANDS_IMPL
#include <sys/types.h>
#include <string.h>

const Command *find_command(const char *const name, const Command commands[]) {
    size_t idx = 0;
    const Command *c;

    while ((c = &commands[idx++])->name != NULL)
        if (strcmp(c->name, name) == 0)
            return c;

    return NULL;
}
#endif /* COMMANDS_IMPL */
#endif /* _COMMANDS_H */
