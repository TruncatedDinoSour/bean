#include "config_kw.h"
#include "logging.h"
#include "config.h"
#include "carray.h"
#include "const.h"
#include "types.h"
#include "line.h"
#include "file.h"
#include "clrs.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

extern UChar kw_inited;

void config_init(void) { kw_init(); }

UChar config_add(Config *cfg, String line) {
    KwFn fn;
    CArray line_arr = {0};

    if (!kw_inited)
        return 1;

    line_split(&line_arr, line);

    if (line_arr.size == 0)
        return 1;

    if ((fn = *kw_find(line_arr.arr[0])) != NULL)
        return fn(cfg, &line_arr);

    return 0;
}

void config_destroy(Config *cfg) {
    while (cfg->cans.size)
        free_line(cfg->cans.arr[--cfg->cans.size]);

    carray_destroy(&cfg->cans);
}

UChar config_load(Config *cfg, UChar logging) {
    char *line;
    size_t line_n = 0;
    int fd;
    UChar ret = 0;

    if ((fd = open(CONFIG_FILE, O_RDONLY)) == -1)
        return 1;

    config_init();

    while ((line = read_line(fd)) != NULL) {
        ++line_n;

        if ((ret = config_add(cfg, line)) != 0) {
            if (logging)
                flog_error("config failure at line %lu ( `%s` )\n", line_n,
                           line);

            break;
        }
    }

    close(fd);
    return ret;
}
