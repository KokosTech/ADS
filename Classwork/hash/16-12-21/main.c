#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 16-12-21 - do PUT, GET, CONTAINS

typedef struct pair{
    char *key;
    unsigned short value;
    struct pair *next;
} pair_t;

typedef struct hash_table{
    pair_t **buckets;
    size_t size;
} hash_table_t;

int hash(char *str){
    return str[0];
}

int hash2(char *str){
    size_t str_l = strlen(str);
    return ((str[0] ^ str[(str_l - 1) / 2]) | (str[0] ^ str[str_l - 1]) | (str[str_l-1] ^ str[(str_l - 1) / 2])) + str_l;
}

hash_table_t *init(size_t size){
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    hash_table->size = size;
    hash_table->buckets = (pair_t **)calloc(size, sizeof(pair_t *));
    
    return hash_table;
}

// HOMEWORK - Create a random hash func for a random struct

hash_table_t *put(hash_table_t *hash_table, char *key, unsigned short value){
    pair_t *new_pair = (pair_t *)malloc(sizeof(pair_t));
    new_pair->key = key;
    new_pair->value = value;

    // ADD IF HEAD
    unsigned short bucket_num = hash(key) % hash_table->size;
    if(hash_table->buckets[bucket_num] == NULL){
        hash_table->buckets[bucket_num] = new_pair;
        return hash_table;
    }

    new_pair->next = hash_table->buckets[bucket_num];
    
    // CHECK FOR THE SAME KEY
    pair_t* current = hash_table->buckets[bucket_num];
    while(current != NULL){
        if(!strcmp(current->key, key)){
            current->value = value;
            break;
        }
        current = current->next;
    }

    // IF NOT - ADD A NEW ELLEMENT
    hash_table->buckets[bucket_num] = new_pair;
    
    return hash_table;
}

bool contains(hash_table_t * hash_table, char *key){
    unsigned short bucket_num = hash(key) % hash_table->size;
    if(hash_table->buckets[bucket_num]== NULL){
        printf("NO SUCH KEY\n");
        return false;
    }
    
    pair_t* current = hash_table->buckets[bucket_num];
    while(current != NULL){
        if(!strcmp(current->key, key)){
            return true;
        }
        current = current->next;
    }

    printf("NO SUCH KEY\n");
    return false;
}

unsigned short get(hash_table_t * hash_table, char *key){
    unsigned short bucket_num = hash(key) % hash_table->size;
    if(hash_table->buckets[bucket_num]== NULL){
        printf("NO SUCH KEY\n");
        return 0;
    }
    
    pair_t* current = hash_table->buckets[bucket_num];
    while(current != NULL){
        if(!strcmp(current->key, key)){
            return current->value;
        }
        current = current->next;
    }

    printf("NO SUCH KEY\n");
    return 0;
}

int main(){
    //hash_table_t *hash_table = init(10);
    //hash_table = put(hash_table, "KEY", 12);
    //printf("%d\n", get(hash_table, "KEY"));

    // TESTING H_FUNC2

    printf("%d\n", hash2("Hllllllllo"));
    printf("%d\n", hash2("Hollo"));
    return 0;
}