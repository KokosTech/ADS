#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Open Hash Table

typedef struct pair{
    char *key;
    int value;
} pair_t;

typedef struct hash_table{
    pair_t **pair;
    size_t size;
} hash_table_t;

size_t hash(char *str){
    size_t str_l = strlen(str);
    return ((str[0] ^ str[(str_l - 1) / 2]) | (str[0] ^ str[str_l - 1]) | (str[str_l-1] ^ str[(str_l - 1) / 2])) + str_l;
}

hash_table_t *hash_init(size_t size){
    hash_table_t *table = (hash_table_t *)malloc(sizeof(hash_table_t));
    table->pair = (pair_t **)malloc(size * sizeof(pair_t *));
    for(size_t i = 0; i < size; ++i){
        table->pair[i] = (pair_t *)malloc(sizeof(pair_t));
        table->pair[i]->key = NULL;
    }
    table->size = size;
    return table;
}

hash_table_t *hash_add(hash_table_t *table, char *key, int value){
    size_t hash_val = hash(key) % table->size;
    if(table->pair[hash_val]->key == NULL){
        table->pair[hash_val]->key = (char *)malloc(strlen(key) * sizeof(char));
        strcpy(table->pair[hash_val]->key, key);
        table->pair[hash_val]->value = value;
    } else {
        while(table->pair[hash_val]->key != NULL){
            if(hash_val == table->size - 1){
                printf("FULL");
                return table;
            }
            ++hash_val;
        }
        table->pair[hash_val]->key = (char *)malloc(strlen(key) * sizeof(char));
        strcpy(table->pair[hash_val]->key, key);
        table->pair[hash_val]->value = value;
    }
    return table;
}

bool *hash_contains(hash_table_t *table, char *key){
    size_t hash_val = hash(key) % table->size;
    if(table->pair[hash_val]->key == NULL){
        table->pair[hash_val]->key = (char *)malloc(strlen(key) * sizeof(char));
        strcpy(table->pair[hash_val]->key, key);
        table->pair[hash_val]->value = value;
    } else {
        while(table->pair[hash_val]->key != NULL){
            if(hash_val == table->size - 1){
                printf("FULL");
                return table;
            }
            ++hash_val;
        }
        table->pair[hash_val]->key = (char *)malloc(strlen(key) * sizeof(char));
        strcpy(table->pair[hash_val]->key, key);
        table->pair[hash_val]->value = value;
    }
    return table;
}

void hash_print(hash_table_t *table){
    for(int i = 0; i < table->size; ++i)
        if(table->pair[i]->key != NULL)
            printf("[%d][%s] %d || %d\n", i, table->pair[i]->key, table->pair[i]->value, hash(table->pair[i]->key) % table->size);
}

int main(){
    hash_table_t *table = hash_init(20);
    table = hash_add(table, "Hello", 1);
    table = hash_add(table, "it's", 69);
    table = hash_add(table, "me", 420);
    table = hash_add(table, "Krum4o", 40);
    table = hash_add(table, "its", 40);
    table = hash_add(table, "Kru4mo", 40);
    hash_print(table);
    return 0;
}