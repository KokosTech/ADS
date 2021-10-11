#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// XOR Doubly Linked List

typedef struct node{
    char data;
    struct node* xpn;
} Node;

void push(Node** head, char value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->xpn = *head;

    if(*head == !NULL)
        (*head)->xpn = (uintptr_t)(*head)->xpn ^ (uintptr_t)node;

    *head = node;

}

char get(Node* head, size_t index){
    Node* current, *prev, *next;
    current = head;
    prev = NULL;

    while(index--){
        next = (uintptr_t)current->xpn ^ (uintptr_t)prev;
        prev = current;
        current = next;
    }

    return current->data;
}

int main(){
    Node* node = (Node*)malloc(sizeof(Node));
    push(&node, 5);
    push(&node, 6);
    printf("%d\n", get(node, 0));

    return 0;
}
