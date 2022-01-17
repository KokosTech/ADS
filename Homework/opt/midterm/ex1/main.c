#include "tree.h"

int main(){
    tree_t *root = add(NULL, 25);
    root = add(root, 15);
    root = add(root, 50);
    root = add(root, 10);
    root = add(root, 22);
    root = add(root, 35);
    root = add(root, 70);
    root = add(root, 4);
    root = add(root, 12);
    root = add(root, 18);
    root = add(root, 24);
    root = add(root, 31);
    root = add(root, 44);
    root = add(root, 66);
    root = add(root, 90);

    printf("Biggest sum: %d\n", get_max_sum(root));
    //printTree(root);
    root = destroy_tree(root);
    return 0; 
}