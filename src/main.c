#include "cmds.h"
#include "clrs.h"
#include "chroot.h"
#include "cmdmgr.h"
#include "logging.h"

int main(const int argc, const char *const argv[]) {
    extern const Command cmds[];
    const Command *c;

    if (argc < 2) {
        LOG_ERROR("no subcommand supplied");
        cmd_help(argv);
        return 1;
    }

    c = find_command(argv[1], cmds);

    if (c == NULL)
        FLOG_ERROR_RET("no such subcommand : " CLR_BOLD "%s" CLR_RESET "\n",
                       argv[1]);

    return c->cmd(argv);
}
