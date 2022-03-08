#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct graph_node_t {
  int value;
  struct graph_node_t** items;
  int item_count;
  char visited;
} graph_node_t;

graph_node_t* init_graph_node(int value);

void connect_nodes(graph_node_t* a, graph_node_t* b);

void add_node(graph_node_t* start, int new_value, int parent_value);

void print_node(graph_node_t* node) {
  printf("value=%d item_count=%d visited=%d items=",
    node->value, node->item_count, node->visited
  );
  for(int i = 0; i < node->item_count; i++) {
    printf("%d,",node->items[i]->value);
  }
  puts("");
}

graph_node_t* find_node(graph_node_t* start, int value);


