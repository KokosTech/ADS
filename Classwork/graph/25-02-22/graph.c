#include "graph.h"

graph_node_t *init_graph_node(int value) {
    graph_node_t *node = (graph_node_t *)malloc(sizeof(graph_node_t));
    node->value = value;
    node->items = NULL;
    node->item_count = 0;
    node->visited = 0;
    return node;
}

void connect_nodes(graph_node_t *a, graph_node_t *b) {
	if(!a || !b)
		return;

    a->items = (graph_node_t**)realloc(a->items, (1 + a->item_count) * sizeof(graph_node_t*));
    a->items[a->item_count++] = b;
}

graph_node_t* find_node(graph_node_t* start, int value)
{
    if(!start)
        return NULL;
        
    if(start->value == value)
        return start;

    start->visited = 1;

    for(int i = 0; i < start->item_count; i++)
    {
        if(start->items[i]->visited == 1)
            continue;

        graph_node_t* temp = find_node(start->items[i], value);
        if(temp != NULL)
        {
            start->visited = 0;
            return temp;
        }
    }

    start->visited = 0;
    return NULL;
}

void add_node(graph_node_t *start, int new_value, int parent_value) {
    graph_node_t *parent = find_node(start, parent_value);
    graph_node_t *new_node = init_graph_node(new_value);
    connect_nodes(parent, new_node);
}

int has_path(graph_node_t *start, int value) {
    if(start == NULL)
        return 0;
    if(start->value == value)
        return 1;

    start->visited = 1;
    for(int i = 0; i < start->item_count; i++){
        if(start->visited == 1)
            continue;

        int temp = has_path(start->items[i], value);
        if(temp != 0){
            start->visited = 0;
            return 1;
        }
    }
        
    start->visited = 0;
    return 0;
}

void print_node(graph_node_t *node) {
    printf("value=%d item_count=%d visited=%d items=",
           node->value, node->item_count, node->visited
    );
    for(int i = 0; i < node->item_count; i++) {
        printf("%d,",node->items[i]->value);
    }
    puts("");
}