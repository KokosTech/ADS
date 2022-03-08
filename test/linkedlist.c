#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int data;
    struct Data* next;
} Data;

Data* init(int data){
    Data* node = (Data*) malloc(sizeof(Data));

    node->data = data;
    node->next = NULL;

    return node;
}

void add_first(Data** node, int data){
    Data* temp = init(data);
    temp->next = (*node);
    (*node) = temp;
}

void remove_first(Data** node){
    Data* tempnode = *node;
    *node = tempnode->next;
    free(tempnode);
}

void remove_spec(Data** node, int index){
    while((*node)->next != NULL & index > 0){
        (*node)++; --index;
    }
    remove_first(&(*node)->next);
}

void print_list(Data* node){
    while(node->next != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
}

int main(){
    Data* node = init(1);
    add_first(&node, 2);
    add_first(&node, 3);
    add_first(&node, 4);
    printf("%d\n", node->data);
    print_list(node);
    remove_first(&node);
    print_list(node);
    add_first(&node, 5);
    print_list(node);
    remove_spec(&node, 3);
    return 0;
}