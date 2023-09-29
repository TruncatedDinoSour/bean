#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "cli.h"
#include "clrs.h"
#include "main.h"
#include "types.h"
#include "const.h"
#include "config.h"
#include "logging.h"

extern const Command cli_cmds[];

int main(const int argc, String argv[]) {
    int fd;
    const Command *c;
    Config cfg = {0};
    UChar ret;

    if (access(CONFIG_FILE, F_OK) != 0) {
        flog_info("creating config file " CLR_BOLD "`%s`\n", CONFIG_FILE);

        fd = open(CONFIG_FILE, O_WRONLY | O_CREAT);

        if (fd == -1)
            return log_error("failed to open the config file for writing");

        write(fd, DEFAULT_CONFIG, strlen(DEFAULT_CONFIG));
        close(fd);

        chmod(CONFIG_FILE, CONFIG_FILE_PERMS);
    }

    flog_info("loading config file " CLR_BOLD "`%s`\n", CONFIG_FILE);

    if ((ret = config_load(&cfg, 1)) != 0)
        goto __main_cleanup;

    if (argc < 2) {
        log_error("no subcommand supplied");
        CMD_NAME(help)(argv, &cfg);
        ret = 1;
        goto __main_cleanup;
    }

    c = find_command(argv[1], cli_cmds);

    if (c == NULL)
        return flog_error("no such subcommand " CLR_BOLD "`%s`\n", argv[1]);

    ret = c->cmd(argv, &cfg);

__main_cleanup:
    config_destroy(&cfg);
    return ret;
}
