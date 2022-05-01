#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    short val;
    struct node_t *next;
} node_t;

node_t *init_queue(); // so useful

void push(node_t **head, short val);
void pop(node_t **head);

void print_queue(node_t *head);
node_t *destroy_list(node_t *head);
