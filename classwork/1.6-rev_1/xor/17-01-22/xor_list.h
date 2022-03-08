#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    short value;
    struct node_t *xpn;
} node_t;

node_t *add(node_t *head, short value);