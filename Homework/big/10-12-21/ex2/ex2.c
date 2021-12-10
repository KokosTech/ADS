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
    new_node->prev = NULL;

    if(*head)
        (*head)->prev = new_node;

    (*head) = new_node;
}

// Тук няма много да спазвам правото си на писане, 
// защото имам малко да разказвам. Значи Марто каза, 
// че е достатъчно да правим само на next, тъй като, 
// ако е реално цикличен, той ще си бъде както и по prev,
// така и по next. Anyways, it's pain to switch between keyboard
// layout to do this shit 

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

void destroy_list(struct node_t **head){  
    struct node_t *current = *head;
    struct node_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main(){
    struct node_t* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    printf("[BEFORE] Is cyclic: %d\n", is_cyclic(head));
    head->next->next->next->next = head->next; // Cycling it
    printf("[AFTER] Is cyclic: %d\n", is_cyclic(head));

    // Imma hard code it, so i don't have to make a function to remove the cycle
    head->next->next->next->next = NULL;
    destroy_list(&head); // - FIX IT LATER - destroying a list with a loop - not a great idea
    head = NULL;

    return 0;
}

