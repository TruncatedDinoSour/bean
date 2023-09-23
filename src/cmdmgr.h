#ifndef _CMDMGR_H
#define _CMDMGR_H
#include "types.h"

#define CMD_NAME(name) cmd_##name
#define CMD_DEF(name)  short CMD_NAME(name)(String *)
#define CMD(name)      short CMD_NAME(name)(String argv[])

typedef struct {
    String name, desc;
    short (*cmd)(String *);
} Command;

const Command *find_command(String, const Command *);
#endif /* _CMDMGR_H */
