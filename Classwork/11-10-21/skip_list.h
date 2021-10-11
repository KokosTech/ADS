#ifndef __SKIP_LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __SKIP_LIST
#define MAX_LEVEL 2

typedef struct node_t{
    short key; // sorted
    short value;
    struct node_t** next;
} node_t;

typedef struct skip_list_t{
    node_t* head;
    size_t size;
    
} skip_list_t;

void init_list(skip_list_t*);
void inset(skip_list_t*, unsigned short key, short value);

#endif