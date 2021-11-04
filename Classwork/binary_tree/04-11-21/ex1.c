#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* left, *right;
    unsigned char level;
} node_t;

node_t *add(node_t *root, int value) {
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

/* void printBT(node_t* root){
    if(!root)
        return;
    printf("%d\n", root->value);
    size_t pos = 0;
    while(){

    }
    printf("\n");
}
 */
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

int is_identical(node_t* first_root, node_t* second_root){
    if(first_root == NULL && second_root == NULL)
        return 1;
    if(first_root == NULL || second_root == NULL)
        return 0;

    return first_root->value == second_root->value &&
        is_identical(first_root->left, second_root->left) && 
        is_identical(first_root->right, second_root->right);
}

int main(){
    node_t* bin = add(NULL, 15);
    bin = add(bin, 11);
    bin = add(bin, 8);
    bin = add(bin, -2);
    bin = add(bin, 20);

    node_t* bin2 = add(NULL, 15);
    bin2 = add(bin2, 11);
    bin2 = add(bin2, 8);
    bin2 = add(bin2, -2);
    bin2 = add(bin2, 20);
    
    printf("%d\n", is_identical(bin, bin2));
    bin2 = add(bin2, 66);
    printf("%d\n", is_identical(bin, bin2));
    printf("%hhu\n", height(bin));

    return 0;
}