#include <stddef.h>

#include "config_kw.h"
#include "types.h"

#include <stdio.h>

KwFn config_kws[KW_MAX] = {0};
UChar kw_inited         = 0;

const Kw kw_kws[] = {
    {"can", KW_NAME(can)},
};
const size_t kw_kws_sz = sizeof(kw_kws) / sizeof(kw_kws[0]);

void kw_init(void) {
    size_t idx = kw_kws_sz;
    const Kw *kw;

    if (kw_inited)
        return;

    while (idx) {
        kw = &kw_kws[--idx];
        config_kws[kw_hash(kw->name)] = kw->fn;
    }

    kw_inited = 1;
}

KwFn *kw_find(String kw) { return kw_inited ? &config_kws[kw_hash(kw)] : NULL; }

size_t kw_hash(MString key) {
    size_t hash = 0;

    while (*key) {
        hash += (size_t)*key++;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash % KW_MAX;
}

/* kws */

KW(can) {
    (void)cfg;
    (void)line;

    puts("`can` called :3");

    return 0;
}
