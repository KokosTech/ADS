#ifndef __LINKED_H
#define __LINKED_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    struct node_t* next;
    char data;
    struct node_t* prev;
} node_t;

typedef struct list_t{
    node_t* head;
    node_t* tail;
    unsigned int size;
} list_t;

list_t* init();

char push(list_t* list, char value);
char pop(list_t* list);

char r_push(list_t* list, char value);
char r_pop(list_t* list);

char front(list_t list);
char back(list_t list);

void print_list(list_t list);

#endif