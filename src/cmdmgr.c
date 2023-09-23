#include <string.h>
#include <sys/types.h>

#include "cmdmgr.h"

const Command *find_command(const char *const name, const Command commands[]) {
    size_t idx = 0;
    const Command *c;

    while ((c = &commands[idx++])->name != NULL)
        if (strcmp(c->name, name) == 0)
            return c;

    return NULL;
}
