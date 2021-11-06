#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
	int value;
	struct node_t *left, *right;
} node_t;

node_t *add(node_t *root, int value) {
	// dyno
	if (root == NULL) {
		node_t *newNode = (node_t *)malloc(sizeof(node_t));
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->value = value;
		return newNode;
	}

	if (value < root->value) 
		root->left = add(root->left, value);
	
	else if (value > root->value) 
		root->right = add(root->right, value);
	
	return root;
}

unsigned char _height(node_t *node, unsigned char level) {
	if (node == NULL)
		return level;

	unsigned char right =  _height(node->right, level + 1);
	unsigned char left = _height(node->left, level + 1);
	
	return right > left ? right : left;
}

unsigned char height(node_t *root) {
	
	return _height(root, 0);
}

void printTree(node_t *root) {
	if (root == NULL)
		return; 
	
	printf("%d\n", root->value);
	unsigned short pos = 0;

	printf("\n");
}

int* fetch_values(node_t* root, int* values){
    if(root->left == NULL && root->right == NULL){
        (*values) = root->value;
        return values + 1;
    }

    if(root->left)
        values = fetch_values(root->left, values);
    
    (*values) = root->value;

    if(root->right)
        values = fetch_values(root->right, values + 1);

    return values + 1;
}

size_t size_tree(node_t* root){
    if(root == NULL)
        return 0;

    return size_tree(root->left) + size_tree(root->right) + 1;
}

node_t* _helper_balancer(node_t* root, int* arr, size_t size){
    if(size == 0){
        return NULL;
    }

    int element = arr[size/2];
    root = add(root, element);
    _helper_balancer(root, arr, size / 2);
    _helper_balancer(root, arr + size / 2 + 1, size - size / 2 - 1);
    return root;
}

node_t* balance_tree(node_t* root){
    size_t tree_size = size_tree(root);
    int* arr = (int*)calloc(tree_size, sizeof(int));
    fetch_values(root, arr);
    _helper_balancer(NULL, arr, tree_size);
}

void print2DUtil(node_t *root, int space) {     size_t size = size_tree(root);         if (root == NULL)         return;           space += size;           print2DUtil(root->right, space);         printf("\n");     for (int i = size; i < space; i++)         printf(" ");     printf("%d\n", root->value);          print2DUtil(root->left, space); }   void print2D(node_t *root) {  print2DUtil(root, 0); } 

int main() {
	node_t *root = add(NULL, 15); 
	root = add(root, 11);
	root = add(root, 8);
	root = add(root, -2);
	root = add(root, 20);

	printf("%hhu\n", height(root));
/*     int* values = (int*)calloc(6, sizeof(int));
    fetch_values(root, values);
    for(int i = 0; i < 6; ++i){
        printf("%d ", values[i]);
    } printf("\n"); */
	//printTree(root);

    root = balance_tree(root);
    print2D(root);
	return 0;
}