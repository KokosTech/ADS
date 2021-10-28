#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* left, *right;
} node_t;

node_t* add(node_t* root, int value){
    if(!root){
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = value;
        return new_node;
    }

    if(value < root->value)
        root->left = (root->left, value);
    else if(value > root->value)
        root->right = add(root->right, value);

    return root;
}

void printBT(node_t* root){
    if(!root)
        return;
    printf("%d\n", root->value);
    size_t pos = 0;
    while(){
        
    }
    printf("\n");
}

void kill_list(node_t* root){

}

int main(){
    node_t* bin = add(NULL, 15);
    bin = add(bin, 11);
    bin = add(bin, 8);
    bin = add(bin, -2);
    bin = add(bin, 20);
    printBT(bin);
    return 0;
}