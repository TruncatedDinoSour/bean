#ifndef _CMDS_C
#define _CMDS_C
#include "cmdmgr.c"
#include <stddef.h>

int cmd_help(char **);

#ifdef CMDS_IMPL
#include <stdio.h>
#include "logging.h"

const Command cmds[] = {
    {"help", cmd_help},
    {NULL, NULL},
};

int cmd_help(char *argv[]) {
    unsigned idx = 0;
    const Command *c;

    LOG_NORMAL("available subcommands");

    while ((c = &cmds[idx++])->name != NULL)
        FLOG_NORMAL("  %s\n", c->name);

    FLOG_INFO("example : " CLR_BOLD "%s help" CLR_RESET "\n", argv[0]);

    return 0;
}
#endif /* CMDS_IMPL */
#endif /* _CMDS_C */
