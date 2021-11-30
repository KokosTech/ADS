#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

#define MAX_LEVEL 2

typedef struct node_t{
    int val;
    int key;
    struct node_t *next;
    struct node_t *prev;
    struct node_t *xpn;
} node_t;

typedef struct list_t {
    node_t *head;
} list_t;

node_t *xor(node_t* a, node_t* b){
    return (node_t*)((uintptr_t) a ^ (uintptr_t) b);
}

void init_list(list_t *list) 
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    list->head = head;
    head->key = -1;
    head->val = 0;
    head->next = NULL;
    head->prev = NULL;
    head->xpn = NULL;
}

void insert_update(list_t *list, int key, int val) 
{
    node_t* update;
    node_t* current = list->head;
    node_t* prev = NULL, *next = NULL;
    next = xor(current->xpn, prev);

    while (next != NULL && next->key < key)
    {
        prev = current;
        current = next;
        next = xor(current->xpn, prev);
    }
    update = current;
    while (current->next != NULL && current->next->key < key)
        current = current->next;
    

    if(current->next && current->next->key == key)
    {
        current->next->val = val;
        return;
    } 

    node_t* newNode = (node_t *)malloc(sizeof(node_t));
    newNode->val = val;
    newNode->key = key;

    if (key % 3 == 0)
    {
        update->xpn = xor(prev, newNode);
        newNode->xpn = xor(update, next);
        if(next)
            next->xpn = xor(xor(update, next->xpn), newNode);
       
    }
    if(current->next)
        current->next->prev = newNode;
    newNode->next = current->next;
    current->next = newNode;
    newNode->prev = current;
}

void print_normal(list_t *l) 
{
        node_t *current = l->head;
        printf("\n List elements: ");
        while (current->next != NULL) 
        {
                current = current->next;
                printf("%d(%d) ", current->val, current->key);
        }
        printf("\n");
 

}

void print_express(list_t * l) 
{
    node_t *current, *prev, *next;
    current = l->head;
    prev = NULL;
    printf("\n Express line elements: ");
    while(current->next != NULL) {
        next = (node_t *)((uintptr_t)current->xpn ^ (uintptr_t)prev);
        prev = current;
        current = next;
        printf("%d(%d) ", current->val, current->key);
    }
     printf("\n");
}

void destroy_list(list_t* l) 
{
    node_t* current = l->head, *next = current->next;
    
    while (next != NULL)
    {
        current = next;
        next = current->next;
        free(current);
    }
    
    free(next);
    free(l->head);
}

int main()
{
    list_t l;
    init_list(&l);
    insert_update(&l, 1, 1);
    insert_update(&l, 3, 13);
    insert_update(&l, 2, 2);
    insert_update(&l, 2, 12);
    insert_update(&l, 6, 3);
    print_normal(&l);
    print_express(&l);
    return 0;
}
