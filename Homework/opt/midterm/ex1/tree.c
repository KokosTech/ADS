#include "tree.h"

tree_t *add(tree_t *root, int value) {
	if (root == NULL) {
		tree_t *new_node = (tree_t *)malloc(sizeof(tree_t));
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->val = value;
		return new_node;
	}

	if (value < root->val) 
		root->left = add(root->left, value);
	else if (value > root->val) 
		root->right = add(root->right, value);
	
	return root;
}

// Helper funcs

size_t sizeTree(tree_t *root) {
	if (root == NULL)
		return 0;

	return sizeTree(root->left) + sizeTree(root->right) + 1;
}

unsigned char _height(tree_t* node, unsigned char level) {
    if (node == NULL) {
        return level;
    }

    unsigned char right = _height(node->right, level+1);
    unsigned char left = _height(node->left, level+1);

    return right > left ? right : left;
}

unsigned char height(tree_t* root) {
    return _height(root, 0);
}

// Get Max Sum of Level Sums - algorithm - HW

int __get_max_sum(tree_t *node, int level){
    if(node == NULL)
        return 0;
    if (level == 0)
        return node->val;
    
    int sum = 0;
    sum += __get_max_sum(node->left, level - 1);
    sum += __get_max_sum(node->right, level - 1);
    
    return sum;
}

int __max(int *arr, size_t size){
    int current_max = arr[0];
    for(int i = 1; i < size; ++i)
        if(current_max < arr[i])
            current_max = arr[i];

    free(arr);
    return current_max;
}

int get_max_sum(tree_t *node){
    int levelCount = height(node);
    int *sums = calloc(levelCount, sizeof(int));
    for (int i = 0; i < levelCount; i++)
        sums[i] = __get_max_sum(node, i);
    return __max(sums, levelCount);
}

// Printing

void print2DUtil(tree_t *root, int space){
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

void printTree(tree_t *root){
    print2DUtil(root, 0);
}

// Freeing 

tree_t *destroy_tree(tree_t *root){
    if(!root) return NULL;

    root->left = destroy_tree(root->left);
    root->right = destroy_tree(root->right);

    free(root);
    return NULL;
}