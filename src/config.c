#include "config_kw.h"
#include "config.h"
#include "types.h"
#include "line.h"
#include "carray.h"

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
