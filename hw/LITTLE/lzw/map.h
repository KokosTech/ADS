#pragma once

#include <stdbool.h>
#define US unsigned short

typedef struct pair {
    char *key;
    US value;
    struct pair *next;
} pair_t;

typedef struct map {
    pair_t **buckets;
    size_t size;
} map_t;

map_t *init_map(size_t size);
map_t *put(map_t *map, const char *key, US value);
bool contains(map_t *map, const char *key);
US get_value(map_t *map, const char *key);

 void print(map_t *map);
