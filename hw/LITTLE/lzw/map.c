#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "map.h"

// HASH function from the interwebs
int hash(char *str) {
    size_t str_l = strlen(str);
    return ((str[0] ^ str[(str_l - 1) / 2]) | (str[0] ^ str[str_l - 1]) | (str[str_l-1] ^ str[(str_l - 1) / 2])) + str_l;
}

map_t *init_map(size_t size) {
    map_t *map = (map_t *)malloc(sizeof(map_t));

    map->size = size;
    map->buckets = (pair_t **)calloc(size, sizeof(pair_t *));

    return map;
}

pair_t *add_pair(const char *key, US *value, pair_t *next) {
    pair_t *new_pair = (pair_t *)malloc(sizeof(pair_t));
    new_pair->key = key;
    new_pair->value = *value;
    new_pair->next = next;

    return new_pair;
}

map_t *put(map_t *map, const char *key, US *value) {
    if(!map) return NULL;

    size_t bucket_num = hash(key) % map->size;

    // ADD IF HEAD
    if (!map->buckets[bucket_num]) {
        map->buckets[bucket_num] = add_pair(key, value, NULL);
        return map;
    }

    // UPDATE
    pair_t *current = map->buckets[bucket_num];
    while (current) {
        if (!strcmp(current->key, key)) {
            current->value = *value;
            break;
        }
        current = current->next;
    }

    // IF NOT - ADD A NEW ELLEMENT
    map->buckets[bucket_num] = add_pair(key, value, map->buckets[bucket_num]);

    return map;
}

bool contains(map_t *map, const char *key) {
    if(!map) return false;

    size_t bucket_num = hash(key) % map->size;
    if(!map->buckets[bucket_num]) return false;

    pair_t *current = map->buckets[bucket_num];
    while (current) {
        if (!strcmp(current->key, key)) {
            return true;
        }
        current = current->next;
    }

    return false;
}

US get_value(map_t *map, const char *key) {
    if(!map) return 0;

    size_t bucket_num = hash(key) % map->size;
    if(!map->buckets[bucket_num]) return 0;

    pair_t *current = map->buckets[bucket_num];
    while (current) {
        if (!strcmp(current->key, key)) {
            return current->value;
        }
        current = current->next;
    }

    return 0;
}