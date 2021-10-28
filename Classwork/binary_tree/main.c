#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* left, *right;
    unsigned char level;
} node_t;

node_t* add(node_t* root, int value, unsigned char level){
    if(!root){
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = value;
        new_node->left = level + 1;
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

unsigned char _height(node_t* node, unsigned char level){
    if(node == NULL)
        return level;

    if(!node->right, level + 1)
        unsigned char r =  _height(node->right, level +1)

    if(!node->lefr, level + 1)
        unsigned char l =  _height(node->left, level +1)

    return r > l ? r : l;
}

unsigned char height(node_t* root){
    return _height(root, 0);
}

void printCBT(node_t* node){
    if(!node->left)
        printf("%d ", node->left->value);

    if(!node->right)
        printf("%d ", node->right->value);
}

void kill_list(node_t* root){

}

int main(){
    node_t* bin = add(NULL, 15, -1);
    bin = add(bin, 11, -1);
    bin = add(bin, 8, -1);
    bin = add(bin, -2, -1);
    bin = add(bin, 20), -1);
    printBT(bin);
    return 0;
}