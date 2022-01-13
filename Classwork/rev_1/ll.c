// Returns last-n node
// n = 3
// _ -> _ -> _ -> * -> _ -> _
// returns *

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    struct node_t* next;
    char data;
} node_t;

node_t *push(node_t *head, char value){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = value;
    new_node->next = head;

    return new_node;
}

node_t *last_n(node_t *node, int i){
    if(node->next == NULL){
        return node;
    }
    last_n(node->next, i);
}

node_t *findNthElement(node_t *head, int *count) {
    if (!head) {
        (*count)--;
        return NULL;
    }
        
    node_t *temp = findNthElement(head->next, count);
    
    if(*count == 0) {
        return head;
    }
    (*count)--;
    return temp;
}

int main(){
    node_t *head = NULL;
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    int i = 3;
    printf("%d\n", findNthElement(head, &i)->data);


    return 0;
}