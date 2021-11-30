#include "linkedlist.h"

// Init, mate

list_t* init(){
    list_t* l =  (list_t*)malloc(sizeof(list_t));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

// Add

char push(list_t* list, char value){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = value;
    
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

char pop(list_t* list){
    if (list->size == 0)
        return 0;

    char temp = front(*list);

    node_t* old_node = list->head;
    list->head = old_node->next;
    list->head->prev = NULL;

    free(old_node);
    --list->size;
    return temp;
}

// Add | Reverse

char r_push(list_t* list, char value);
char r_pop(list_t* list);

// Print

char front(list_t list){
    return list.head->data;
}
char back(list_t list);

void print_list(list_t list){
    node_t* c_node = list.head;
    while(c_node != NULL){
        printf("% c ", c_node->data);
        c_node = c_node->next;
    }
    printf("\n");
}