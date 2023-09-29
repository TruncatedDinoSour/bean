#ifndef _CONFIG_KW_H
#define _CONFIG_KW_H
#include <stddef.h>

#include "config.h"
#include "carray.h"
#include "types.h"

#define KW_MAX      64
#define KW_NAME_MAX 64

#define KW_NAME(name) _kw_##name
#define KW_DEF(name)  UChar KW_NAME(name)(Config *, CArray *)
#define KW(name)      UChar KW_NAME(name)(Config * cfg, CArray * line)

typedef UChar (*KwFn)(Config *, CArray *);

typedef struct {
    String name;
    KwFn fn;
} Kw;

size_t kw_hash(MString);
KwFn *kw_find(String);
void kw_init(void);

KW_DEF(can);
#endif /* _CONFIG_KW_H */
