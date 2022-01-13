#include "hash_table.h"

size_t hash(char *str){
    size_t hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;
    return hash;
}

/* size_t hash(char *str){
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

hash_table_t *put(hash_table_t *hash_table, char *key, double value){
    pair_t *new_pair = (pair_t *)calloc(1, sizeof(pair_t));
    new_pair->key = (char *)malloc(strlen(key) + 1);
    strcpy(new_pair->key, key);
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

bool contains(hash_table_t *hash_table, char *key) {
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

double get(hash_table_t * hash_table, char *key){
    size_t bucket_num = hash(key) % hash_table->size;
    if(hash_table->buckets[bucket_num]== NULL){
        printf("NO SUCH KEY\n");
        return 0;
    }
    
    pair_t* current = hash_table->buckets[bucket_num];
    while(current != NULL){
        if(!strcmp(current->key, key)){
            double result = current->value;
            return result;
        }
        current = current->next;
    }
    printf("NO SUCH KEY\n");
    return 0;
}

hash_table_t *destroy_table(hash_table_t *hash_table){
    for(int i = 0; i < hash_table->size; i++){
        pair_t *current = hash_table->buckets[i];
        while(current != NULL){
            pair_t *temp = current;
            current = current->next;
            free(temp->key);
            temp->key = NULL;
            free(temp);
            temp = NULL;
        }
    }
    free(hash_table->buckets);
    hash_table->buckets = NULL;
    free(hash_table);
    hash_table = NULL;
    return hash_table;
}