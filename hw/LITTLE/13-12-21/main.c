#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
    char data;
    struct node_t *smaller, *bigger;
} node_t;

node_t *add(node_t *root, int data) {
	if (root == NULL) {
		node_t *newNode = (node_t *)malloc(sizeof(node_t));
		newNode->smaller = NULL;
		newNode->bigger = NULL;
		newNode->data = data;
		return newNode;
	}

	if (data < root->data) 
		root->smaller = add(root->smaller, data);
	
	else if (data > root->data) 
		root->bigger = add(root->bigger, data);
	
	return root;
}

node_t *destroy_tree(node_t *root){
    if(!root) return NULL;

    root->smaller = destroy_tree(root->smaller);
    root->bigger = destroy_tree(root->bigger);

    free(root);
    return NULL;
}

// LITTLE EX

int __oddEvenDiff(node_t *root){
    if(!root) return 0;

    if(root->data % 2)
        return (__oddEvenDiff(root->smaller) + __oddEvenDiff(root->bigger) - 1);
    else
        return (__oddEvenDiff(root->smaller) + __oddEvenDiff(root->bigger) + 1);
}

unsigned int oddEvenDiff(node_t *root){
    return abs(__oddEvenDiff(root)); // works only with INTs, otherwise I was gonna use CHARs
}

int main(){
    node_t *tree = NULL;
    tree = add(tree, 5); // o
    tree = add(tree, 3); // o
    tree = add(tree, 1); // o
    tree = add(tree, 4); // e
    tree = add(tree, 7); // o

    printf("DIFF: %d\n", oddEvenDiff(tree));

    tree = destroy_tree(tree);
    return 0;
}
