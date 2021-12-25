#include "hash_table.h"

size_t hash(unsigned char *str){
    size_t hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;
    return hash;
}

/* size_t hash(unsigned char *str){
    size_t str_l = strlen(str);
    return ((str[0] ^ str[(str_l - 1) / 2]) | (str[0] ^ str[str_l - 1]) | (str[str_l-1] ^ str[(str_l - 1) / 2])) + str_l;
} */

hash_table_t *init(size_t size){
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    hash_table->size = size;
    hash_table->buckets = (pair_t **)calloc(size, sizeof(pair_t *));
    
    return hash_table;
}

// HOMEWORK - Create a random hash func for a random struct

hash_table_t *put(hash_table_t *hash_table, unsigned char *key, double value){
    pair_t *new_pair = (pair_t *)malloc(sizeof(pair_t));
    new_pair->key = key;
    new_pair->value = value;

    // ADD IF HEAD
    size_t bucket_num = hash(key) % hash_table->size;
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

bool contains(hash_table_t * hash_table, unsigned char *key){
    size_t bucket_num = hash(key) % hash_table->size;
    if(hash_table->buckets[bucket_num]== NULL){
        printf("NO SUCH KEY\n");
        return false;
    }
    
    pair_t* current = hash_table->buckets[bucket_num];
    while(current != NULL){
        if(!strcmp(current->key, key)){
            free(current);
            return true;
        }
        current = current->next;
    }

    free(current);
    printf("NO SUCH KEY\n");
    return false;
}

double get(hash_table_t * hash_table, unsigned char *key){
    size_t bucket_num = hash(key) % hash_table->size;
    if(hash_table->buckets[bucket_num]== NULL){
        printf("NO SUCH KEY\n");
        return 0;
    }
    
    pair_t* current = hash_table->buckets[bucket_num];
    while(current != NULL){
        if(!strcmp(current->key, key)){
            double result = current->value;
            free(current);
            return result;
        }
        current = current->next;
    }
    free(current);
    printf("NO SUCH KEY\n");
    return 0;
}