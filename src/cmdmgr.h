#ifndef _CMDMGR_H
#define _CMDMGR_H
#include "types.h"
#include "config.h"

#define CMD_NAME(name) _cmd_##name
#define CMD_DEF(name)  UChar CMD_NAME(name)(String[], Config *)
#define CMD(name)      UChar CMD_NAME(name)(String argv[], Config * cfg)
#define CCMD(name)                                   \
    static UChar CMD_NAME(__nocfg_##name)(String[]); \
    CMD(name) {                                      \
        (void)cfg;                                   \
        return CMD_NAME(__nocfg_##name)(argv);       \
    }                                                \
    static UChar CMD_NAME(__nocfg_##name)(String argv[])

typedef struct {
    String name, desc;
    UChar (*cmd)(String[], Config *);
} Command;

const Command *find_command(String, const Command[]);
#endif /* _CMDMGR_H */
