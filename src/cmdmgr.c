#ifndef _CMDMGR_C
#define _CMDMGR_C
#define CMD_NAME(name) cmd_##name
#define CMD_DEF(name) int CMD_NAME(name)(const char *const *)
#define CMD(name) int CMD_NAME(name)(const char *const argv[])

typedef struct {
    const char *const name;
    int (*cmd)(const char *const *);
} Command;

const Command *find_command(const char *const, const Command *);

#ifdef CMDMGR_IMPL
#include <string.h>
#include <sys/types.h>

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
