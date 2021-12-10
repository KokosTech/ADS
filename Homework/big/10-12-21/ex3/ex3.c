#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Structure of binary tree
typedef struct bTree{
    int val;
    struct bTree *left;
    struct bTree *right;
}node_t;

// The normal / basic / usual funcs

node_t *add(node_t *root, int value) {
	if (root == NULL) {
		node_t *newNode = (node_t *)malloc(sizeof(node_t));
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->val = value;
		return newNode;
	}

	if (value < root->val) 
		root->left = add(root->left, value);
	
	else if (value > root->val) 
		root->right = add(root->right, value);
	
	return root;
}

int *fetchValues(node_t *root, int *values) {
	if (root->left == NULL && root->right == NULL) {
		(*values) = root->val;
		return values + 1;
	}

	
	if (root->left)
		values = fetchValues(root->left, values);
	
	(*values) = root->val;
	values++;
	
	if (root->right)
		values = fetchValues(root->right, values);

	return values;
}

size_t sizeTree(node_t *root) {
	if (root == NULL)
		return 0;

	return sizeTree(root->left) + sizeTree(root->right) + 1;
}

// Not used - only for testing purposes - aka the 2 balance funcs

node_t *_helperBalancer(node_t *root, int *arr, size_t size) {
	if (size == 0)
		return NULL;
	int element = arr[size / 2];
	root = add(root, element);
	_helperBalancer(root, arr, size / 2);

	_helperBalancer(root, arr + size / 2 + 1, size - (size / 2 + 1));

	return root;
}

node_t *balanceTree(node_t *root) {
	size_t size = sizeTree(root);
	int *arr = (int *)malloc(sizeof(int) * size);

	fetchValues(root, arr);

	node_t *newRoot =  _helperBalancer(NULL, arr, size);	

	free(arr);
	arr = NULL;
	return newRoot;
}

// Printing

void print2DUtil(node_t *root, int space){
    size_t size = sizeTree(root);

	if (root == NULL)
		return;

	space += size;

	print2DUtil(root->right, space);

	printf("\n");
	for (int i = size; i < space; i++)
		printf(" ");
	printf("%d\n", root->val);

	print2DUtil(root->left, space);
}

void printTree(node_t *root){
    print2DUtil(root, 0);
}

// Bad Split

void bad_split(node_t *root, node_t **result1, node_t **result2) {
    size_t size = sizeTree(root);
    int *root_arr = (int *)malloc(sizeof(int) * size);
    fetchValues(root, root_arr);

    int *arr1 = (int *)malloc(sizeof(int) * size / 2);
    int *arr2 = (int *)malloc(sizeof(int) * (size - (size / 2 + 1)));

    for(size_t i = 0; i < size; i++){
        if(i % 2)
            arr1[i/2] = root_arr[i];
        else
            arr2[i/2] = root_arr[i];
    }

    printf("BAL\n");
    
    *result1 = _helperBalancer(NULL, arr1, size / 2);

	*result2 = _helperBalancer(NULL, arr2, size - (size / 2 + 1));

	// Freeing!!!
	free(root_arr);
	root_arr = NULL;
	free(arr1);
	arr1 = NULL;
	free(arr2);
	arr2 = NULL;
}

// Split for 6 :)

void *xor (void *a, void *b) {
	return (void*)((uintptr_t)a ^ (uintptr_t)b);
}

void swap(node_t **a, node_t **b) {
    *a = (node_t*)xor(*a, *b);
    *b = (node_t*)xor(*b, *a);
    *a = (node_t*)xor(*a, *b);
}

void split(node_t *tree, node_t **result1, node_t **result2){   
    if(!tree) return; // bottom
    
    split(tree->left, result1, result2); 
    *result1 = add(*result1, tree->val);
    swap(result1, result2);
    split(tree->right, result1, result2);
}

// Freeing func

node_t *destroy_tree(node_t *root){
    if(!root) return NULL;

    root->left = destroy_tree(root->left);
    root->right = destroy_tree(root->right);

    free(root);
    return NULL;
}

int main(){
    node_t *tree = add(NULL, 10);
    tree = add(tree, 5);
    tree = add(tree, 15);
    tree = add(tree, 3);
    tree = add(tree, 6);
    tree = add(tree, 12);
    tree = add(tree, 18);
    tree = add(tree, 8);
    tree = add(tree, 13);

    printf("NORMAL TREE:\n");
    printTree(tree);

    node_t *t1 = NULL, *t2 = NULL;
    split(tree, &t1, &t2);
	// trying the bad one, vs the good (6) one
    //bad_split(tree, &t1, &t2);
    t1 = balanceTree(t1);
    t2 = balanceTree(t2);
    printf("\n\nTREE1:\n");
    printTree(t1);
    printf("\n\nTREE2:\n");
    printTree(t2); 
    printf("\n\nVALS:\n");

	// Show VALS at end just for the user
    int *arr = (int *)calloc(sizeTree(tree), sizeof(int));
    fetchValues(tree, arr);
    for(size_t i = 0; i < sizeTree(tree); ++i)
        printf("%d ", arr[i]);
	printf("\n");

	// Freeing everything

	free(arr);
	arr = NULL;

	tree = destroy_tree(tree);
	t1 = destroy_tree(t1);
	t2 = destroy_tree(t2);

    return 0;
}
