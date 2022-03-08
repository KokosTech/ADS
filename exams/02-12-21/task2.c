#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t {
    char data;
    node_t *smaller, *bigger;
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

// WRITE AFTER THIS COMMENT

int *fetchValues(node_t *root, int *values) {
	if (root->left == NULL && root->right == NULL) {
		(*values) = root->value;
		return values + 1;
	}

	
	if (root->left)
		values = fetchValues(root->left, values);
	
	(*values) = root->value;
	values++;
	
	if (root->right)
		values = fetchValues(root->right, values);

	return values;
}

node_t *parent(node_t *root, node_t *child) {
	if (root == NULL)
		return NULL;
	if (root->smaller == child || root->bigger == child)
		return root;

	if (root->data < child->data)
		return parent(root->bigger, child);
	
	return parent(root->smaller, child);
}

// Basically my idea is to check if 2 nodes have the same child, obviously, but I don't have really the time to do it, as well as, I'm not sure, what to do now

bool has_snare(node_t *root){
/*     if (root == NULL)
        return false;
    if (root->smaller == NULL && root->bigger == NULL)
        return false;
    if (root->smaller != NULL && root->bigger != NULL)
        return true;
    if (root->smaller != NULL)
        return has_snare(root->smaller);
    if (root->bigger != NULL)
        return has_snare(root->bigger); */

    if (root == NULL)
        return false;

    if(root->smaller == NULL && root->bigger == NULL)
        return parent(root, root) != NULL;

}

int main(){

    return 0;
}