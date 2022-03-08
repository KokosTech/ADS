#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct bTree{
    int val;
    struct bTree *left;
    struct bTree *right;
} node_t;


void _printTreeLogic(node_t *root, int spaces)
{
    if(!root)
        return;
    spaces += 10;
    _printTreeLogic(root->right, spaces);
    printf("\n");
    for(int i = 10; i < spaces; ++i){
        printf(" ");
    }
    printf("%d\n", root->val);

    _printTreeLogic(root->left, spaces);
}

void printTree(node_t *root)
{
    _printTreeLogic(root, 0);
}

void inOrderTraversal(node_t *root)
{
    if(!root) return;
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

void postOrderTraversal(node_t *root)
{
    if(!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->val);
}

void preOrderTraversal(node_t *root)
{
    if(!root) return;
    printf("%d ", root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

size_t size_tree(node_t* root){
    if(root == NULL)
        return 0;

    return size_tree(root->left) + size_tree(root->right) + 1;
}

unsigned char _height(node_t* node, unsigned char level) {
    if (node == NULL) {
        return level;
    }

    unsigned char right = _height(node->right, level+1);
    unsigned char left = _height(node->left, level+1);

    return right > left ? right : left;
}

unsigned char height(node_t* root) {
    return _height(root, 0);
}

// Get Balance factor function - used in add func
int getBalanceF(node_t* node) {
    if (node == NULL) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

int is_balanced(node_t *root){
    if(root == NULL)
        return 1;

    int if_is_balanced = (int)log2(size_tree(root)) + 1;

    return if_is_balanced == height(root);
}

size_t treeSize(node_t *root)
{
    if(!root) return 0;

    return treeSize(root->left) + treeSize(root->right) + 1;
}

int *fetchValues(node_t *root, int *values)
{
    if(root->left == NULL && root->right == NULL)
    {
        (*values) = root->val;
        return values+1;
    }

    if(root->left)
        values = fetchValues(root->right, values);
    
    (*values) = root->val;
    values++;

    if(root->right)
        values = fetchValues(root->right, values);

    return values;        
}

node_t *rotateLeft(node_t *y)
{
    node_t *x = y->right;
    node_t *T2 = x->left;

    y->right = T2;
    x->left = y;

    return x;
}

node_t *rotateRight(node_t *z)
{
    node_t *x = z->left;
    z->left = x->right;
    x->right = z;

    return x;
}

node_t *addNode(node_t *root, int val)
{
    if(!root){
        node_t *new = malloc(sizeof(node_t));
        new->val = val;
        new->left = NULL;
        new->right = NULL;

        return new;
    }

    if(val > root->val){
        root->right = addNode(root->right, val);
        //rotateLeft(root);
    }
    else if(val < root->val){
        root->left = addNode(root->left, val);
        //rotateRight(root);
    }

    return root;
}

node_t *addNodeButBalance(node_t *root, int val)
{
    if(!root){
        node_t *new = (node_t*)malloc(sizeof(node_t));
        new->val = val;
        new->left = NULL;
        new->right = NULL;

        return new;
    }

    if(val > root->val){
        root->right = addNode(root->right, val);
        //rotateLeft(root);
    }
    else if(val < root->val){
        root->left = addNode(root->left, val);
        //rotateRight(root);
    }
    else{
        return root;
    }

    // Balance the tree

    int b = getBalanceF(root);


    if (b > 1 && val < root->left->val)
        return rotateRight(root);
 
    // Right Right Case
    if (b < -1 && val > root->right->val)
        return rotateLeft(root);
 
    // Left Right Case
    if (b > 1 && val > root->left->val)
    {
        root->left =  rotateLeft(root->left);
        return rotateRight(root);
    }
 
    // Right Left Case
    if (b < -1 && val < root->right->val)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

node_t *destroy(node_t *root)
{
    if(!root) return NULL;

    root->left = destroy(root->left);
    root->right = destroy(root->right);

    free(root);
    return NULL;
}

node_t *closest_end_node(node_t *root, int *h){
    if(root = NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
        return root;
    
    (*h)++;
    int l_h = *h, r_h = *h;
    node_t *right = NULL, *left = NULL;
    if(root->right != NULL)
        right = closest_end_node(root->right, &r_h);
    if(root->left != NULL)
        left = closest_end_node(root->left, &l_h);
    if(root->left || root->right){
        *h = root->left == NULL ? r_h : l_h;
        return root->left == NULL ? right : left;
    }

    if(l_h < r_h){
        *h = l_h;
        return left;
    } else {
        *h = r_h;
        return right;
    }
}

int main(){
    node_t *root = NULL;

    root = addNode(root, 13);
    addNode(root, 10);
    addNode(root, 15);
    addNode(root, 5);
    addNode(root, 11);
    addNode(root, 16);
    addNode(root, 4);
    addNode(root, 6);
/*     root->left = rotateLeft(root->right);
    root = rotateRight(root); */
    printTree(root);
    int i = 0;
    printf("%d\n", closest_end_node(root, &i)->val);
    return 0;
}