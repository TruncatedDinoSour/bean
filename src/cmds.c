#include <stddef.h>
#include <sys/types.h>

#include "cmds.h"
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
