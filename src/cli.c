#include <stdio.h>
#include <stddef.h>

#include "cli.h"
#include "clrs.h"
#include "logging.h"

const Command cli_cmds[] = {
    {"help", "print the help page", CMD_NAME(help)},
    {"sync", "sync all cans", CMD_NAME(sync)},
    {0},
};

CCMD(help) {
    size_t idx = 0;
    const Command *c;

    log_normal("available subcommands");

    while ((c = &cli_cmds[idx++])->name != NULL)
        flog_normal("  " CLR_BOLD CLR_CYAN "%s" CLR_RESET " -- %s\n", c->name,
                    c->desc);

    flog_info("example : " CLR_BOLD "%s help" CLR_RESET "\n", argv[0]);

    return 0;
}

CCMD(sync) {
    /* TODO */

    printf("hello %s, we will now sync all the cans !11111111111!\n", argv[0]);
    return 0;
}
