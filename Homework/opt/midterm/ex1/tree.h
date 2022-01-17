#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int val;
    struct tree *left;
    struct tree *right;
} tree_t;

tree_t *add(tree_t *root, int value);

size_t sizeTree(tree_t *root);

int get_max_sum(tree_t *node);

void printTree(tree_t *root);

tree_t *destroy_tree(tree_t *root);