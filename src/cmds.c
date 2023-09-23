#ifndef _CMDS_C
#define _CMDS_C
#include <stddef.h>

#include "cmdmgr.c"

CMD_DEF(help);

/* #define CMDS_IMPL */

#ifdef CMDS_IMPL
#include <sys/types.h>

#include "logging.h"

const Command cmds[] = {
    {"help", CMD_NAME(help)},
    {0},
};

CMD(help) {
    size_t idx = 0;
    const Command *c;

    LOG_NORMAL("available subcommands");

    while ((c = &cmds[idx++])->name != NULL)
        FLOG_NORMAL("  %s\n", c->name);

    FLOG_INFO("example : " CLR_BOLD "%s help" CLR_RESET "\n", argv[0]);

    return 0;
}
#endif /* CMDS_IMPL */
#endif /* _CMDS_C */
