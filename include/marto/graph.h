#pragma once

#include <stdlib.h>
#include <stdio.h>

#define US unsigned short

struct graph_node_t {
  int value;
  struct graph_node_t** items;
  int item_count;
  unsigned short weight[1000];
  char visited;
};

typedef struct queue{
    struct graph_node_t *arr[1000];
    int push;
    int pop;
}que;

struct graph_node_t* init_graph_node(int value);

void connect_nodes(struct graph_node_t* a, struct graph_node_t* b, US weight);

void add_node(struct graph_node_t* start, int new_value, int parent_value, US weight);

void print_node(struct graph_node_t* node);

struct graph_node_t* find_node(struct graph_node_t* start, int value);


