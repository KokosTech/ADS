#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LEVEL 2 // No of levels (aka 1 - normal LL & n-1 express lanes - in this case (logic) - 1 express lane)
#define FREQ 3 // How frequent do we want an express lane // in this case for level 2 (level 1 express lane)

// Struct for the nodes
typedef struct node_t {
    long key;
    int value;
    struct node_t* prev;
    struct node_t* next;
    struct node_t* xpn; // Only used for the expressed lane (in this exercise / in these circumstances)
} node_t;

// Struct for doubly linked skip list
typedef struct skip_list_t {
    node_t *head;
    size_t size;        
} d_skip_list_t;

void* xor(void* a, void* b){
	return (void*)((uintptr_t)a ^ (uintptr_t)b); // As I quoted an answer from StackOverflow in class,
}                                                // we need to type cast them to uintptr_t and the result to void*

void init_list(d_skip_list_t *list) {
    // First node = head - not used for storing values (in this case)
    node_t* head = (node_t *)malloc(sizeof(node_t));
    head->key = -1;
    head->value = 0;
    head->prev = NULL, head->next = NULL, head->xpn = NULL;

    // List
    list->head = head;
    list->size = 0;
}

void insert_update(skip_list_t *list, unsigned short key, short value) {
    node_t **update = (node_t **)calloc(sizeof(node_t *), MAX_LEVEL);
    node_t *current = list->head;
    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        while (current->next[i] != NULL && 
            current->next[i]->key < key)
                current = current->next[i];
        update[i] = current;
    }
    
    node_t *next = current->next[0];
    
    // UPDATE value
    if (next != NULL && next->key == key) {
        current->next[0]->value = value;
        return;
    }
    
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->key = key;
    newNode->value = value;
    int level = (key % 3) ? 1 : 2;
    newNode->next = (node_t **)calloc(sizeof(node_t *), level);
    
    for (int i = 0; i < level; ++i) {
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }
    free(update);
    list->size++;

}

void print(skip_list_t *l) {
    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        node_t *current = l->head;
        while (current->next[i] != NULL) {
                current = current->next[i];
                printf("%d(%d) ", current->value, current->key);
        }
        printf("\n");
    }

} 

void destroy(skip_list_t *l) {
    node_t *current, *next;
    next = l->head;
    
    while (next) {
        current = next;
        next = current->next[0];
        free(current->next);
        free(current);
    }
}

int main() {
    d_skip_list_t l;
    init_list(&l);
    insert_update(&l, 2, 12);
    insert_update(&l, 6, 32);
    insert_update(&l, 4, 72);
    insert_update(&l, 3, 42);
    print(&l);
    destroy(&l);
    return 0;
}