#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
    char *key;
    unsigned short value;
    struct pair *next;
} pair_t;

typedef struct hash_table{
    pair_t *buckets;
    size_t size;
} hash_table_t;

int hash(char *str){
    return str[0];
}

hash_table_t *init(size_t size){
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    hash_table->size = size;
    hash_table->buckets = (pair_t *)calloc(size, sizeof(pair_t *));
    
    return hash_table;
}

int main(){


    return 0;
}