#include "cmds.c"
#include "clrs.h"
#include "chroot.c"
#include "cmdmgr.c"
#include "logging.h"

int main(const int argc, const char *const argv[]) {
    extern const Command cmds[];
    const Command *c;
    const char *x;

    if (argc < 2) {
        LOG_ERROR("no subcommand supplied");
        cmd_help(argv);
        return 1;
    }

    x = chroot_setup("hello");

    if (x != NULL)
        printf("%s\n", x);

    x = chroot_destroy("hello");

    if (x != NULL)
        printf("%s\n", x);

    c = find_command(argv[1], cmds);

    if (c == NULL)
        FLOG_ERROR_RET("no such subcommand : " CLR_BOLD "%s" CLR_RESET "\n",
                       argv[1]);

    return c->cmd(argv);
}
