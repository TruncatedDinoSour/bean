#ifndef _CONFIG_H
#define _CONFIG_H
#include "carray.h"
#include "types.h"

typedef struct {
    CArray cans;
} Config;

void config_init(void);
UChar config_add(Config *, String);
void config_del(void);
UChar config_load(Config *);
#endif /* _CONFIG_H */
