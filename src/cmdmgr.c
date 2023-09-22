#ifndef _CMDMGR_C
#define _CMDMGR_C

typedef struct {
    const char *const name;
    int (*cmd)(char **);
} Command;

const Command *find_command(const char *const, const Command *);

#ifdef CMDMGR_IMPL
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
#endif /* CMDMGR_IMPL */
#endif /* _CMDMGR_C */
