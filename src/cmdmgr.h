#ifndef _CMDMGR_H
#define _CMDMGR_H
#define CMD_NAME(name) cmd_##name
#define CMD_DEF(name) int CMD_NAME(name)(const char *const *)
#define CMD(name) int CMD_NAME(name)(const char *const argv[])

typedef struct {
    const char *const name;
    int (*cmd)(const char *const *);
} Command;

const Command *find_command(const char *const, const Command *);
#endif /* _CMDMGR_H */
