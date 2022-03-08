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

size_t sizeTree(node_t *root) {
	if (root == NULL)
		return 0;

	return sizeTree(root->smaller) + sizeTree(root->bigger) + 1;
}

void print2DUtil(node_t *root, int space){
    size_t size = sizeTree(root);
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += size;

	// Process right child first
	print2DUtil(root->bigger, space);

	// Print current node_t after space
	// count
	printf("\n");
	for (int i = size; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);

	// Process left child
	print2DUtil(root->smaller, space);
}

void printTree(node_t *root){
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

node_t *destroy_tree(node_t *root){
    if(!root) return NULL;

    root->smaller = destroy_tree(root->smaller);
    root->bigger = destroy_tree(root->bigger);

    free(root);
    return NULL;
}

// LITTLE EX

node_t* nearest_ancestor(node_t *root, node_t *node1, node_t *node2){
    if(!root) return NULL;

    if (root->data > node1->data && root->data > node2->data)
        return nearest_ancestor(root->smaller, node1, node2);
 
    if (root->data < node1->data && root->data < node2->data)
        return nearest_ancestor(root->bigger, node1, node2);

    return root;
}

int main(){
    // Creating a big tree
	node_t *root = add(NULL, 15); 
	root = add(root, 11);
	root = add(root, 8);
	root = add(root, -2);
	root = add(root, 20);
    root = add(root, 10);
    root = add(root, 12);
    root = add(root, -3);

    node_t *first = root->smaller->bigger;
    node_t *second = root->smaller->smaller->smaller->smaller;

    printTree(root);
    printf("The nearest ancestor between %d and %d is: %d\n", first->data, second->data, nearest_ancestor(root, first, second)->data);

    root = destroy_tree(root);
    first = NULL;
    second = NULL;
    return 0;
}