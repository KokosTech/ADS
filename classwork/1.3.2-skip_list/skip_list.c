#include "skip_list.h"

void init_list(skip_list_t *list) {
    node_t *head = (node_t *)malloc(sizeof(node_t));
    list->head = head;
    list->size = 0;
    head->key = -1;
    head->value = 0;
    head->next = (node_t **)calloc(sizeof(node_t *), MAX_LEVEL);
    // memset(head->next, 0, MAX_LEVEL);
}

void insert_update(skip_list_t *list, unsigned short key, short value) {
    node_t **update = (node_t **)calloc(sizeof(node_t *), MAX_LEVEL);
    node_t *current = list->head;
    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        while (current->next[i] != NULL && current->next[i]->key < key)
                current = current->next[i];
        update[i] = current;
    }
    
    // UPDATE value
    node_t* next = current->next[0];
    if (next =! NULL, next->key == key){
        current->next[0]->value = value;
        return;
    }
    
    // Insert
    
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->key = key;
    newNode->value = value;
    int level = (key % 3) ? 1: 2;
    newNode->next = (node_t **)calloc(sizeof(node_t *), level);
    
    for (int i = 0; i < level; ++i){
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }

    current->next[0] = newNode;
    if (key % 3 == 0)
        current->next[1] = newNode;

    list->size++;

    free(update);
}

void print_list(skip_list_t* l){
        for (int i = MAX_LEVEL - 1; i >= 0; --i) {
            node_t* current = l->head;
            while (current->next[i] != NULL){
                current = current->next[i];
                printf("%d ", current->value);
            }
            printf("\n");
    }
}

void destroy(skip_list_t* list){
    node_t* current, *next;
    next = list->head;

    while(next){
        free(current->next);
        free(current);
        current = next;
        next = current->next[0];
    }
}

/* void init_list(skip_list_t* list){
    node_t* head = (node_t*)malloc(sizeof(node_t));
    list->head = head;
    list->size = 0;
    head->key = -1;
    head->value = 0;
    head->next = (node_t**)calloc(sizeof(node_t*), MAX_LEVEL);
    // memset(head->next, 0, MAX_LEVEL);
}

void insert(skip_list_t* list, unsigned short key, short value){
    node_t** update = (node_t**)calloc(sizeof(node_t*), MAX_LEVEL);
    node_t* current = list->head;

    for(int i = MAX_LEVEL - 1; i>= 0; --i)
        while(current->next[i]->key < key && current->next[i]!= NULL)
            current = current->next[i];
    
    // Exam - 3 exe. - HW

    if(current->next[0] == NULL){
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->key = key;
        new_node->value = value;

        for(int i = 0; i < MAX_LEVEL; ++i)
            new_node->next[i] = current->next[i];

        new_node->next = (node_t**)calloc(sizeof(node_t*), MAX_LEVEL);
        current->next[0] = new_node;
        
        if(key % 3 == 0)
            current->next[1] = new_node;
    }
} */
