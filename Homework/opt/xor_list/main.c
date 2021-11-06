#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node* xpn;
} Node;

void* xor (void* a, void* b) {
	return (void*)((uintptr_t)a ^ (uintptr_t)b);
}

void push(Node** head, char value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->xpn = *head;

    if(*head == NULL){
        *head = (Node*)malloc(sizeof(Node));
    }

    if(*head == !NULL)
        (*head)->xpn = (uintptr_t)(*head)->xpn ^ (uintptr_t)node;

    *head = node;

}

Node* x_remove(Node* list){
    if (list == NULL)
        return NULL;

    Node *next_item = list->xpn;
    free(list);

    if (next_item == NULL)
        return NULL;
    
    next_item->xpn = xor(list, next_item->xpn);
    
    return next_item;
}

Node* destroy_list(Node *list){
    for (; list != NULL; list = x_remove(list));
    return NULL;
}

void print_list(Node* list){
    Node* prev = NULL;
    Node* tmp = list;

    while (tmp != NULL){
        printf("tmp=%p data=%d p=%p\n", tmp, tmp->data, tmp->xpn);

        Node* tmp2 = tmp;
        tmp = xor(tmp->xpn, prev);
        prev = tmp2;
    }

    puts("");
}

char find(Node* head, char __data){
    Node* current, *prev, *next;
    current = head;
    prev = NULL;

    while(current && current->data != __data){
        next = (uintptr_t)current->xpn ^ (uintptr_t)prev;
        prev = current;
        current = next;
    }

    return current->data;
}

/* int find_value(list_t* list, int value_to_find){
    list_t* prev = NULL;
    list_t* tmp = list;

    int index = 0;

    while(tmp->data != value_to_find){
        if(list->xpn == NULL)
            return -1;
        ++index;
        list_t* tmp2 = tmp;
        tmp = xor(tmp->xpn, prev);
        prev = tmp2;
    }

    return index;
} */

int main(){
    Node *list = (Node*)malloc(sizeof(Node));;
    push(list, 5);

    push(list, 10);
    push(list, 15);
    push(list, 20);

    list = x_remove(list);
    list = x_remove(list);
    print_list(list);
    printf("\n%d\n", find(list, 5));
    
    return 0;
}