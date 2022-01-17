#include "linkedlist.h"

node_t *push(node_t *head, int start, int end){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->start = start;
    new_node->end = end;
    new_node->next = head;

    return new_node;
}

node_t *destroy_list(node_t *head){
    if(head == NULL)
        return NULL;
    destroy_list(head->next);
    free(head);
    head = NULL;
    return NULL;
}

