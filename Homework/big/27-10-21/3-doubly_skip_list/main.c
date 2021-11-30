#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LEVEL 2 // No of levels (aka 1 - normal LL & n-1 express lanes - in this case (logic) - 1 express lane)
#define FREQ 3 // How frequent do we want an express lane // in this case for level 2 (level 1 express lane)
#define NEW_LINE printf("\n");

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

// I give up comenting my code, my eyes are sore from helping the others, i need seruous help

void insert_update(d_skip_list_t *list, unsigned long key, int value) {
    node_t* current = list->head;
    node_t* prev = NULL, *next = NULL, *update;
    next = xor(current->xpn, prev);

    while(next && (unsigned)next->key < key){
        prev = current;
        current = next;
        next = xor(current->xpn, prev);
    }

    update = current; 

    while(current->next && current->next->key < key)
        current = current->next;
    // IF = UPDATE; ELSE = INSERT;
    if (current->next && current->next->key == key) {
        current->next->value = value;
        return;
    }

    node_t* new = (node_t*)malloc(sizeof(node_t));
    char level = (key % FREQ) ? 1 : 2;

    new->key = key;
    new->value = value;
    
    new->xpn = NULL;

    // Express Lane - XOR
    if(level == 2){
        new->xpn = xor(update, next);
        if(next)
            next->xpn = xor(xor(update, next->xpn), new);
        update->xpn = xor(prev, new);
    }

    if(current->next)
        current->next->prev = new;

    new->next = current->next;
    new->prev = current;
    current->next = new;
    //free(update); - Doesn't work - since it's an XOR
    ++list->size;
}

void print_list(d_skip_list_t* list){
    node_t* current, *prev = NULL, *next = NULL;

    for(int i = MAX_LEVEL - 1; i >= 0; --i){
        current = list->head;
        printf("Level %d: ", i + 1);

        // Express lane
        if(i == 1){
            while(xor(current->xpn, prev)){
                next = xor(current->xpn, prev);
                prev = current;
                current = next;
                printf("%d (%d) ", current->value, current->key);
            }
        } else {
            // Normal List
            while(current->next){
                current = current->next;
                printf("%d (%d) ", current->value, current->key);
            }
        } NEW_LINE
    }
}

void kill_list(d_skip_list_t* list) {
    node_t* current = list->head, *next = current->next;
	
	while (next != NULL) {
		current = next;
		next = current->next;
		free(current);
	}
	
	free(next);
	free(list->head);
}

int main() {
    d_skip_list_t l;
    init_list(&l);
    insert_update(&l, 1, 1);
    insert_update(&l, 2, 2);
    insert_update(&l, 3, 3);
    insert_update(&l, 4, 4);
    insert_update(&l, 5, 5);
    insert_update(&l, 6, 6);
    print_list(&l);
    kill_list(&l);
/*     print(&l);
    destroy(&l) */;
    return 0;
}