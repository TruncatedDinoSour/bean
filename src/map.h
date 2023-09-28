#ifndef _MAP_H
#define _MAP_H
#define MAP_MAX_CAPACITY 64
#define MAP_KEY_SIZE     64

#include <stddef.h>

#include "types.h"

typedef struct Entry {
    char key[MAP_KEY_SIZE];
    void *value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[MAP_MAX_CAPACITY];
} Map;

size_t map_hash(MString);
void map_init(Map *);
void map_put(Map *, String, void *);
UChar map_get(const Map *, String, void **);
void map_del(Map *);

/* im sorry for this mess but i just cant with `void *` so i added this
 * auto-caster
 *
 * ! NOTE -- dont forget to update if updated `Map` or any map definitions
 * themselves
 *
 * NOTE -- this only works with pointers */

#define MAP_TYPEDEF(name, type)                                      \
    typedef type name##_t;                                           \
    typedef struct name##_Entry {                                    \
        char key[MAP_KEY_SIZE];                                      \
        name##_t value;                                              \
        struct name##_Entry *next;                                   \
    } name##_Entry;                                                  \
    typedef struct {                                                 \
        name##_Entry *buckets[MAP_MAX_CAPACITY];                     \
    } name;                                                          \
                                                                     \
    size_t name##_hash(MString);                                     \
    void name##_init(name *);                                        \
    void name##_put(name *, String, name##_t);                       \
    UChar name##_get(const name *, String, name##_t *);              \
    void name##_del(name *map);                                      \
                                                                     \
    size_t name##_hash(MString key) { return map_hash(key); }        \
    void name##_init(name *map) { map_init((Map *)map); }            \
    void name##_put(name *map, String key, name##_t value) {         \
        map_put((Map *)map, key, (void *)value);                     \
    }                                                                \
    UChar name##_get(const name *map, String key, name##_t *value) { \
        return map_get((const Map *)map, key, (void **)value);       \
    }                                                                \
    void name##_del(name *map) { map_del((Map *)map); }
#endif /* _MAP_H */
