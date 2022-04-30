#include "queue.h"

node_t *init_queue() { return NULL; }

node_t *create_node(short val) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

void push(node_t **head, short val){
    if(!(*head)) {
        (*head) = create_node(val);
        return;
    }
    
    node_t *current = (*head);
    while(current->next)
        current = current->next;
    
    current->next = create_node(val);
}

void pop(node_t **head){
    if(!(*head)) return;

    (*head) = (*head)->next;
}

void print_queue(node_t *head) {
    if(!head) return;

    node_t *current = head;
    while(current){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

node_t *destroy_list(node_t *head){
    if(head == NULL)
        return NULL;
    destroy_list(head->next);
    free(head);
    head = NULL;
    return NULL;
}