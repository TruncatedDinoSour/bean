#include "config_kw.h"
#include "config.h"
#include "carray.h"
#include "const.h"
#include "types.h"
#include "line.h"
#include "file.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

static CArray _config_line_arr = {0};

extern UChar kw_inited;

void config_init(void) {
    kw_init();
}

UChar config_add(Config *cfg, String line) {
    KwFn fn;
    UChar ret = 1;

    if (!kw_inited)
        return 1;

    line_split(&_config_line_arr, line);

    if (_config_line_arr.size == 0)
        goto __config_add_cleanup;

    if ((fn = *kw_find(_config_line_arr.arr[0])) != NULL)
        ret = fn(cfg, &_config_line_arr);

__config_add_cleanup:
    line_clear(&_config_line_arr);
    return ret;
}

void config_del(void) { line_destroy(&_config_line_arr); }

UChar config_load(Config *cfg) {
    char *line;
    int fd;

    if ((fd = open(CONFIG_FILE, O_RDONLY)) == -1)
        return 1;

    config_init();

    while ((line = read_line(fd)) != NULL) {
        config_add(cfg, line);
        free(line);
    }

    close(fd);

    return 0;
}
