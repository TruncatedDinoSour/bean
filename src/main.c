#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "cmds.h"
#include "clrs.h"
#include "main.h"
#include "types.h"
#include "const.h"
#include "logging.h"

int main(const int argc, String argv[]) {
    int fd;
    const Command *c;

    if (access(CONFIG_FILE, F_OK) != 0) {
        flog_info("creating config file " CLR_BOLD "`%s`\n", CONFIG_FILE);

        fd = open(CONFIG_FILE, O_WRONLY | O_CREAT);

        if (fd == -1)
            return log_error("failed to open the config file for writing");

        write(fd, DEFAULT_CONFIG, strlen(DEFAULT_CONFIG));
        close(fd);

        chmod(CONFIG_FILE, CONFIG_FILE_PERMS);
    }

    if (argc < 2) {
        log_error("no subcommand supplied");
        cmd_help(argv);
        return 1;
    }

    c = find_command(argv[1], cmds);

    if (c == NULL)
        return flog_error("no such subcommand " CLR_BOLD "`%s`\n", argv[1]);

    return c->cmd(argv);
}
