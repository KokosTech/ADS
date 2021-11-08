#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
	int value;
	struct node_t *left, *right;
	unsigned char level;
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

size_t sizeTree(node_t *root) {
	if (root == NULL)
		return 0;

	return sizeTree(root->left) + sizeTree(root->right) + 1;
}

void print2DUtil(node_t *root, int space)
{
    size_t size = sizeTree(root);
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += size;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = size; i < space; i++)
		printf(" ");
	printf("%d\n", root->value);

	// Process left child
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void printTree(node_t *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int is_identical(node_t* first_root, node_t* second_root){
    if(first_root == NULL && second_root == NULL)
        return 1;
    if(first_root == NULL || second_root == NULL)
        return 0;

    return first_root->value == second_root->value &&
        is_identical(first_root->left, second_root->left) && 
        is_identical(first_root->right, second_root->right);
}


int check_if_subtree(node_t *root, node_t *subtree) {
    if(subtree == NULL)
        return 0;
    if(is_identical(root->left, subtree) || is_identical(root->right, subtree) || is_identical(root, subtree))
        return 1;

    return check_if_subtree(root->left, subtree->left) && check_if_subtree(root->right, subtree->right);
}

int main(){
    node_t *root = add(NULL, 15); 
	root = add(root, 11);
	root = add(root, 8);
	root = add(root, -2);
	root = add(root, 20);

    printTree(root);

    node_t *subroot = add(NULL, 11); 
	subroot = add(subroot, 8);
	subroot = add(subroot, -2);

	printf("\nSubtree:\n");
	printTree(subroot);

	node_t *subroot1 = add(NULL, 3); 
	subroot1 = add(subroot1, 8);
	subroot1 = add(subroot1, -2);

	node_t *root2 = add(NULL, 15); 
	root2 = add(root2, 11);
	root2 = add(root2, 8);
	root2 = add(root2, -2);
	root2 = add(root2, 20);

	printf("\nNot aSubtree:\n");
	printTree(subroot);

    printf("Check if subtree: %d\n", check_if_subtree(root, subroot));
	printf("Check if subtree1: %d\n", check_if_subtree(root, subroot1));
	printf("Check if root2: %d\n", check_if_subtree(root, root2));

    return 0;
}