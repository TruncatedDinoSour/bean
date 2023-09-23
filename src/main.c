#include <stddef.h>

#include "cmds.h"
#include "clrs.h"
#include "chroot.h"
#include "cmdmgr.h"
#include "logging.h"

extern const Command cmds[];

int main(const int argc, const char *const argv[]) {
    const Command *c;

    if (argc < 2) {
        log_error("no subcommand supplied");
        cmd_help(argv);
        return 1;
    }

    c = find_command(argv[1], cmds);

    if (c == NULL)
        return flog_error("no such subcommand : " CLR_BOLD "%s" CLR_RESET "\n",
                          argv[1]);

    return c->cmd(argv);
}
