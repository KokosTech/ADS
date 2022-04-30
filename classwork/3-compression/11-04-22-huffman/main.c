// Huffman algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define char_t unsigned char


// Priority queue
typedef struct node_t{
    struct node_t *prev, *next;
    char data;
    char_t priority;
} node_t;

typedef struct list_t{
    node_t *head;
    node_t *tail;
    size_t size;
} list_t;

list_t *init(){
    list_t *l = (list_t*)malloc(sizeof(list_t));

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

char front(list_t list){
    return list.head->data;
}
char back(list_t list){
    return list.tail->data;
}

char push(list_t* list, char value, char_t priority){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = value;
    new_node->priority = priority;
    
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL)
        list->head->prev = new_node;
    else
        list->tail = new_node;
    
    list->head = new_node;
    ++list->size;
    return new_node->data;
}

char dpop(list_t* list){
    if (list->size == 0)
        return 0;

    char temp = back(*list);

    node_t* old_node = list->tail;
    list->tail = old_node->prev;
    list->tail->next = NULL;

    free(old_node);
    --list->size;
    return temp;
}

void ppop(list_t* list){
    if (list->size == 0)
        return;
    
    node_t *current = list->head;
    node_t *max_priority = list->head;
    for(int i = 0; i < list->size; ++i){
        if(max_priority->priority < current->priority){
            max_priority = current;
        }
        current = current->next;
    }

    if(max_priority->prev == NULL){
        list->head = max_priority->next;
        list->head->prev = NULL;
    } else if (max_priority->next == NULL){
        list->tail = max_priority->prev;
        list->tail->next = NULL;
    } else {
        max_priority->prev->next = max_priority->next;
        max_priority->next->prev = max_priority->prev;
    }
    
    --(list->size);
    free(max_priority);
    max_priority = NULL;
}

 char peek(list_t* list){
    if (list->size == 0)
        return NULL;
    
    node_t *current = list->head;
    node_t *max_priority = list->head;
    for(int i = 0; i < list->size; ++i){
        if(max_priority->priority < current->priority){
            max_priority = current;
        }
        current = current->next;
    }

    return max_priority->data;
}

void print_list(list_t list){
    node_t *c_node = list.head;
    while(c_node != NULL){
        printf("Data: %d\n", c_node->data);
        printf("Priority: %d\n", c_node->priority);

        c_node = c_node->next;
    }
    printf("\n");
}

list_t *destroy(list_t *list){
    node_t *c_node = list->head;
    while(c_node->next != NULL){
        c_node = c_node->next;
        free(c_node->prev);
    }
    free(c_node);
    free(list);

    return NULL;
}

// Hash map
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

/* bool *hash_contains(hash_table_t *table, char *key){
    size_t hash_val = hash(key) % table->size;
    if(table->pair[hash_val]->key == NULL){
        return false;
    } else {
        while(table->pair[hash_val]->key != NULL){
            if(hash_val == table->size - 1){
                printf("FULL");
            }
            ++hash_val;
        }
        return true;
    }
    return false;
} */

void hash_print(hash_table_t *table){
    for(int i = 0; i < table->size; ++i)
        if(table->pair[i]->key != NULL)
            printf("[%d][%s] %d || %d\n", i, table->pair[i]->key, table->pair[i]->value, hash(table->pair[i]->key) % table->size);
}

int main() {

    return 0;
}