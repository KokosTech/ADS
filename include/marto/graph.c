#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


struct graph_node_t* init_graph_node(int value);

void connect_nodes(struct graph_node_t* a, struct graph_node_t* b, US weight);

void add_node(struct graph_node_t* start, int new_value, int parent_value, US weight);

void print_node(struct graph_node_t* node);

int bfs(struct graph_node_t *start, struct graph_node_t *end);
struct graph_node_t* find_node(struct graph_node_t* start, int value);

struct graph_node_t* init_graph_node(int value){
    struct graph_node_t* new_node = (struct graph_node_t*)malloc(sizeof(struct graph_node_t));
    new_node->value = value;
    new_node->items = NULL;
    new_node->item_count = 0;
    new_node->visited = 0;
    return new_node;
}

void connect_nodes(struct graph_node_t* a, struct graph_node_t* b, US weight){
    if (a == NULL || b == NULL)
        return;
        
    a->items = (struct graph_node_t**)realloc(a->items, (1 + a->item_count) * sizeof(struct graph_node_t*));
    a->items[a->item_count++] = b;
    a->weight[a->item_count - 1] = weight;
}

struct graph_node_t* find_node(struct graph_node_t* start, int value){
    if(start->value == value)
        return start;

    start->visited = 1;

    for(int i = 0; i < start->item_count; i++)
    {
        if(start->items[i]->visited == 1)
            continue;

        struct graph_node_t* temp = find_node(start->items[i], value);
        if(temp != NULL)
        {
            start->visited = 0;
            return temp;
        }
    }

    start->visited = 0;
    return NULL;
}

void add_node(struct graph_node_t* start, int new_value, int parent_value, US weight){
    struct graph_node_t *temp = find_node(start, parent_value);
    struct graph_node_t *new_node = init_graph_node(new_value);
    connect_nodes(temp, new_node, weight);
}

int hasPath(struct graph_node_t *start, struct graph_node_t *end){
    start->visited = 1;
    if(start == end)
    {
        start->visited = 0;
        return 1;
    }
    for(int i = 0; i < start->item_count; i++)
    {      
        if(!start->items[i]->visited && hasPath(start->items[i], end))
        {
            start->visited = 0;
            return 1;
        }
    }
    start->visited = 0;
    return 0;
}

int bfs(struct graph_node_t *start, struct graph_node_t *end){
    if(!start || !end)
        return 0;
      
    queue_t queue;
    queue.push = 0;
    queue.pop = 0;

    queue.arr[queue.push++] = start;
    start->visited = 1;
    
    
    while(queue.push - queue.pop > 0) {
    	struct graph_node_t *temp = queue.arr[queue.pop];
        
	if(end == queue.arr[queue.pop])
            return 1;
            
        for(int i = 0; i < temp->item_count; i++)
        {
            if(temp->items[i]->visited == 0) {
                queue.arr[queue.push++] = temp->items[i];
            	temp->items[i]->visited = 1;
	    }
        }
        queue.pop++;
    }
    
    return 0;
}

void print_node(struct graph_node_t* node) {
    printf("value=%d item_count=%d visited=%d items=",
           node->value, node->item_count, node->visited
    );
    for(int i = 0; i < node->item_count; i++) {
        printf("%d,",node->items[i]->value);
    }
}

int greatest_val(struct graph_node_t *start){
    start->visited = 1;
    int temp = start->value;

    for(int i = 0; i < start->item_count; i++){      
        if(!start->items[i]->visited){
            int val = greatest_val(start->items[i]);
            if(val > temp)
                temp = val;
            return 1;
        }
    }
    start->visited = 0;
    return 0;
}

unsigned short dijkstra(struct graph_node_t *start, struct graph_node_t *end) {
    int size = greatest_val(start) + 1;
    int pathsLen[size];

    for (int i = 0; i < size; i++) {
        pathsLen[i] = -1;
    }

    // Add to queue
    // For queue size pop lowest weight 


}