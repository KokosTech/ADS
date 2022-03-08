#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define RESIZE_FACTOR 2

typedef struct pair{
    char *key;
    int value;
} pair_t;

typedef struct hash_table{
    pair_t **pair;
    size_t size, capacity;
} hash_table;

size_t hash(char *str){
    return str[0];
}

hash_table *hash_init(size_t size){
    hash_table *table = (hash_table *)malloc(sizeof(hash_table));
    table->pair = (pair_t **)calloc(size, sizeof(pair_t *));
    table->size = 0;
    table->capacity = size;
    return table;
}

void resize_table(hash_table *table){
    hash_table *new_table = hash_init(table->capacity * RESIZE_FACTOR);
    for(size_t i = 0; i < table->capacity; i++){
        if(table->pair[i] != NULL){
            pair_t *pair = table->pair[i];
            while(pair != NULL){
                hash_table_insert(new_table, pair->key, pair->value);
                pair = pair->next;
            }
        }
    }
    free(table->pair);
    table->pair = new_table->pair;
    table->capacity = new_table->capacity;
    free(new_table);
}

hash_table *hash_add(hash_table *table, char const *key, int value) {
    pair_t *new_pair = (pair_t *)malloc(sizeof(pair_t));
    new_pair->key = (char *)malloc(strlen(key) + 1);
    strcpy(new_pair->key, key);
    new_pair->value = value;

    size_t index = hash(key) % table->capacity;
    table[index] = new_pair;
    ++table->size;
}

bool *hash_contains(hash_table *table, char *key);


int main(){
    hash_table *table = hash_init(20);
    return 0;
} 