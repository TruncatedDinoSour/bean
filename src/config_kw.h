#ifndef _CONFIG_KW_H
#define _CONFIG_KW_H
#include "config.h"
#include "carray.h"

#define CONFIG_KW_NAME(kw) _config_kw_##kw
#define CONFIG_KW_DEF(kw) void CONFIG_KW_NAME(kw)(Config *, CArray *)
#define CONFIG_KW(kw) void CONFIG_KW_NAME(kw)(Config *cfg, CArray *line)

CONFIG_KW_DEF(can);
#endif /* _CONFIG_KW_H */
