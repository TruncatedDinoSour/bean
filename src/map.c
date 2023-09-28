#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "map.h"
#include "types.h"

size_t map_hash(MString key) {
    size_t hash = 0;

    while (*key) {
        hash += (size_t)*key++;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash % MAP_MAX_CAPACITY;
}

void map_init(Map *map) {
    size_t idx;

    for (idx = 0; idx < MAP_MAX_CAPACITY; ++idx)
        map->buckets[idx] = NULL;
}

void map_put(Map *map, String key, void *value) {
    size_t idx   = map_hash(key);
    Entry *entry = map->buckets[idx], *new_entry;

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            /* key exists, update the value */

            entry->value = value;
            return;
        }

        entry = entry->next;
    }

    /* insert a new value */

    new_entry = malloc(sizeof(*new_entry));

    strncpy(new_entry->key, key, MAP_KEY_SIZE);

    new_entry->value = value;
    new_entry->next  = map->buckets[idx];

    map->buckets[idx] = new_entry;
}

UChar map_get(const Map *map, String key, void **out) {
    Entry *entry = map->buckets[map_hash(key)];

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            *out = entry->value;
            return 1;
        }

        entry = entry->next;
    }

    return 0;
}

void map_del(Map *map) {
    size_t idx;
    Entry *entry, *next;

    for (idx = 0; idx < MAP_MAX_CAPACITY; ++idx) {
        entry = map->buckets[idx];

        while (entry != NULL) {
            next = entry->next;
            free(entry);
            entry = next;
        }

        map->buckets[idx] = NULL;
    }
}
