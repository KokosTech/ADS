#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    struct node_t *next;
    int start;
    int end
} node_t;