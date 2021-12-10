#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int data;
    struct node_t *prev, *next;
} node_t;

void push(struct node_t **head, int data){
    struct node_t *new_node = (node_t *)malloc(sizeof(node_t));
 
    new_node->data = data;
    new_node->next = (*head);

    (*head) = new_node;
}

int is_cyclic(node_t* node) {
    node_t *slower = node, *faster = node;

    while (slower && faster && faster->next) {
        slower = slower->next;
        faster = faster->next->next;

        if (slower == faster)
            return 1;
    }

    return 0;
}

int main(){
    struct node_t* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    
    printf("Is cyclic: %d\n", is_cyclic(head));

    return 0;
}

