#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node_t{
    struct node_t *next;
    double start;
    double end;
} node_t;

node_t *push(node_t *head, double start, double end);
node_t *destroy_list(node_t *head);