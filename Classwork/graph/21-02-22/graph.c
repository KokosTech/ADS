#include "graph.h"

graph_node_t *init_graph_node(int value) {
    graph_node_t *node = malloc(sizeof(graph_node_t));
    node->value = value;
    node->items = NULL;
    node->item_count = 0;
    node->visited = 0;
    return node;
}

void connect_nodes(graph_node_t *a, graph_node_t *b) {
    a->items = realloc(a->items, sizeof(graph_node_t*) * (a->item_count + 1));
    a->items[a->item_count++] = b;
}

void add_node(graph_node_t *start, int new_value, int parent_value) {
    graph_node_t *parent = find_node(start, parent_value);
    graph_node_t *new_node = init_graph_node(new_value);
    connect_nodes(parent, new_node);
}


// Depht-first search
graph_node_t *find_node(graph_node_t *start, int value){
    if(start == NULL)
        return NULL;
    if(start->value == value)
        return start;
    
}