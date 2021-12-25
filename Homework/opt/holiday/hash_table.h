#pragma once

#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pair{
    char *key;
    double value;
    struct pair *next;
} pair_t;

typedef struct hash_table{
    pair_t **buckets;
    size_t size;
} hash_table_t;

size_t hash(unsigned char *str);
hash_table_t *init(size_t size);
hash_table_t *put(hash_table_t *hash_table, char *key, double value);
bool contains(hash_table_t * hash_table, char *key);
double get(hash_table_t * hash_table, char *key);


