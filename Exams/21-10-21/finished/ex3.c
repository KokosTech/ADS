#include <stdio.h>
#include <stdlib.h>

// Stacked Doubly Linked List (?)
typedef struct node_t{
    int data;
    // Normal // Aka as added
    struct node_t* prev;
    struct node_t* next;
    // Ascending // Aka as sorted
    struct node_t* acs_prev;
    struct node_t* acs_next;
} node_t;

node_t* init_node(int value){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = value;
    new_node->acs_next = NULL;
    new_node->acs_prev = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

node_t* add_node(node_t* list, int value){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = value;
    
    new_node->next = NULL;
    new_node->prev = list;
    list = new_node;
    
     if(list->prev =! NULL)
        //list->prev->next = list;

    return list;
}

void print_as_added(node_t* list){
    
}

void print_as_sorted(node_t* list){

}

int main(){
    node_t* head = init_node(4);
    head = add_node(head, 6);
    printf("%d\n", head->data);

    return 0;
}