#include <stdio.h>
#include <stdlib.h>

typedef struct bTree{
    int val;
    struct bTree *left;
    struct bTree *right;
}node_t;

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
	return newRoot;
}


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

void _bad_split(node_t *root, node_t **result1, node_t **result2, int *root_arr, size_t size) {
    if (size == 0)
		return;

    int element = root_arr[size / 2];

    if((size/2)%2)
        *result1 = add(*result1, element);
    else
        *result2 = add(*result2, element);

    _bad_split(root, result1, result2, root_arr, size / 2);

	_bad_split(root, result1, result2, root_arr + size / 2 + 1, size - (size / 2 + 1));
}

void bad_split(node_t *root, node_t **result1, node_t **result2) {
    size_t size = sizeTree(root);
    int *root_arr = (int *)malloc(sizeof(int) * size);
    fetchValues(root, root_arr);
    int *arr1 = (int *)malloc(sizeof(int) * size / 2);
    int *arr2 = (int *)malloc(sizeof(int) * (size - (size / 2 + 1)));
    //_bad_split(root, result1, result2, root_arr, size);
    for(int i = 0; i < size; i++){
        if(i%2)
            arr1[i/2] = root_arr[i];
        else
            arr2[i/2] = root_arr[i];
    }

    printf("BAL\n");
    
    *result1 = _helperBalancer(NULL, arr1, size / 2);

	*result2 = _helperBalancer(NULL, arr2, size - (size / 2 + 1));
}

// Split for 6

node_t *rightRotate(node_t *y) {
	node_t *x = y->left; 
	node_t *T2 = x->right;

	x->right = y;
	y->left = T2;

	return x;
}
node_t *leftRotate(node_t *y) {
	node_t *x = y->right; 
	node_t *T2 = x->left;

	x->left = y;
	y->right = T2;

	return x;
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

char BF(node_t *root) {
	return height(root->left) - height(root->right);
}

node_t *AVLInsert(node_t *root, int value) {
	
	if (root == NULL) {
		node_t *newNode = (node_t *)malloc(sizeof(node_t));
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->val = value;
		return newNode;
	}

	if (value < root->val) 
		root->left = AVLInsert(root->left, value);
	
	else if (value > root->val) 
		root->right = AVLInsert(root->right, value);
	

	// TODO
	if (BF(root) > 1) {
		if (BF(root->left) < 0)
			root->left = leftRotate(root->left);
		root = rightRotate(root);
	} else if (BF(root) < -1) {
		if (BF(root->right) > 0)
			root->right = rightRotate(root->right);
		root = leftRotate(root);
	}

	return root;
}

void* xor (void* a, void* b) {
	return (void*)((uintptr_t)a ^ (uintptr_t)b);
}

void swap(node_t** a, node_t** b) {
    *a = (node_t*)xor(*a, *b);
    *b = (node_t*)xor(*b, *a);
    *a = (node_t*)xor(*a, *b);
}

void split(node_t *tree, node_t **result1, node_t **result2){   
    if(!tree) return; // bottom
    
    split(tree->left, result1, result2); 
    *result1 = AVLInsert(*result1, tree->val);
    swap(result1, result2);
    split(tree->right, result1, result2);
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
    //bad_split(tree, &t1, &t2);
    //balanceTree(t1);
    //balanceTree(t2);
    printf("\n\nTREE1:\n");
    printTree(t1);
    printf("\n\nTREE2:\n");
    printTree(t2); 
    printf("\n\nVALS:\n");
    int *arr = (int *)calloc(sizeTree(tree), sizeof(int));
    fetchValues(tree, arr);
    for(int i = 0; i < sizeTree(tree); i++)
        printf("%d ", arr[i]);
    return 0;
}