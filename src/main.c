#include "cmdmgr.c"
#include "cmds.c"
#include "logging.h"
#include "clrs.h"

extern const Command cmds[];

int main(int argc, char *argv[]) {
    const Command *c;

    if (argc < 2) {
        LOG_ERROR("no subcommand supplied");
        cmd_help(argv);
        return 1;
    }

    c = find_command(argv[1], cmds);

    if (c == NULL)
        FLOG_ERROR_RET("no such command : " CLR_BOLD "%s" CLR_RESET "\n",
                       argv[1]);

    return c->cmd(argv);
}
