#ifndef _CONFIG_H
#define _CONFIG_H
#include "carray.h"
#include "types.h"

typedef struct {
    CArray cans;
} Config;

void config_add(Config *, String);
#endif /* _CONFIG_H */
