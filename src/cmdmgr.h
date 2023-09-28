#ifndef _CMDMGR_H
#define _CMDMGR_H
#include "types.h"

#define CMD_NAME(name) _cmd_##name
#define CMD_DEF(name)  UChar CMD_NAME(name)(String[])
#define CMD(name)      UChar CMD_NAME(name)(String argv[])

typedef struct {
    String name, desc;
    UChar (*cmd)(String[]);
} Command;

const Command *find_command(String, const Command[]);
#endif /* _CMDMGR_H */
