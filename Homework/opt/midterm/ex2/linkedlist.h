#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node_t{
    struct node_t *next;
    int start;
    int end;
} node_t;

node_t *push(node_t *head, int start, int end);
node_t *destroy_list(node_t *head);