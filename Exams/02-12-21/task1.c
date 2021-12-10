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

// WRITE AFTER THIS COMMENT

// OLD function - it can work , but still not finished - more uneque approach - can work on any tree - i think

/* node_t *parent(node_t *root, node_t *child) {
	if (root == NULL)
		return NULL;
	if (root->smaller == child || root->bigger == child)
		return root;

	if (root->data < child->data)
		return parent(root->bigger, child);
	
	return parent(root->smaller, child);
}

int d_root(struct node_t *root, node_t *x) { 
    if (root->data == x->data) 
        return 0; 
    else if (root->data > x->data) 
        return 1 + d_root(root->smaller, x); 
    return 1 + d_root(root->bigger, x); 
} 

int get_shortest_distance(node_t *root, node_t *a, node_t *b){
    if(!root){
        return 0;
    }

    if(root == a){
        return d_root(root, b);
    } else if(root == b){
        return d_root(root, a);
    }

    if(root == a || root == b){
        return 1;
    }

    if(a == b){
        return 0;
    }

    if(parent(root, a) == b || parent(root, b) == a){
        return 1;
    }

    if(parent(root, a) == parent(root, b)){
        return 1;
    }

    return 1 + get_shortest_distance(root, parent(root, a), parent(root, b));
} */

// Just to make my life easier - got from Marto's code

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


// Get the distance from the root to a node
int d_root(struct node_t *root, node_t *x){
    if(!root)
        return -1;
    if (root->data == x->data) 
        return 0; 
    else if (root->data > x->data) 
        return 1 + d_root(root->smaller, x); 
    return 1 + d_root(root->bigger, x); 
} 


// Get the distance between two nodes
int get_shortest_distance(struct node_t *root, node_t *a, node_t *b){ 
    if (root == NULL) 
        return 0; 
  
/*     if (root->data < a->data && root->data < b->data)
        return get_shortest_distance(root->bigger, a, b);  */

    // Actually this has to be first 
    if (root->data > a->data && root->data > b->data) 
        return get_shortest_distance(root->smaller, a, b); 
  
    if (root->data < a->data && root->data < b->data)
        return get_shortest_distance(root->bigger, a, b); 
  
    if (root->data >= a->data && root->data <= b->data) 
        return d_root(root, a) +  d_root(root, b); 
} 

int __get_shortest_distance(node_t *root, node_t *a, node_t *b){ 
   if (a->data > b->data)
        return get_shortest_distance(root, b, a);
   return get_shortest_distance(root, a, b);
} 

// Freeing the memory
// Yeah, i f-ed it up, so imma use the other points and not do ex2
node_t *destroy_tree(node_t *root){
    if(!root) return NULL;

    root->smaller = destroy_tree(root->smaller);
    root->bigger = destroy_tree(root->bigger);

    free(root);
    return NULL;
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

    // Printing the tree, so I can think
    printTree(root);

    // Creating two nodes, to find their distance
    node_t *first = root->smaller->bigger;
    node_t *second = root->smaller->smaller->smaller->smaller;

    // Printing the nodes' value
    printf("FIRST: %d; SECOND: %d\n", first->data, second->data);

    // Printing the distance
    //printf("%d\n", get_shortest_distance(root, first, second)); --- OLD
    printf("%d\n", __get_shortest_distance(root, root->smaller->bigger, root->smaller->smaller->smaller->smaller));

    // Cleaning everything up
    root = destroy_tree(root);
    first = NULL;
    second = NULL;
    return 0;
}
