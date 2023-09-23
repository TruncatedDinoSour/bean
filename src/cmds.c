#include <stddef.h>
#include <sys/types.h>

#include "cmds.h"
#include "clrs.h"
#include "logging.h"

const Command cmds[] = {
    {"help", CMD_NAME(help)},
    {0},
};

CMD(help) {
    size_t idx = 0;
    const Command *c;

    log_normal("available subcommands");

    while ((c = &cmds[idx++])->name != NULL)
        flog_normal("  %s\n", c->name);

    flog_info("example : " CLR_BOLD "%s help" CLR_RESET "\n", argv[0]);

    return 0;
}
