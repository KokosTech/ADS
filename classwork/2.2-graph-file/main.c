#include "../../include/marto/graph.h"
#include <stdio.h>
#include <stdlib.h>

struct graph_node_t *read_from_file(const char *filename){
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("File not found\n");
        return NULL;
    }

    struct graph_node_t **nodes = NULL;
    int *values = NULL;
    int count = 0, i = 0;
    int value, index, parent_index;

    fscanf(file, "%d", &count);
    nodes = (struct graph_node_t **)malloc(count * sizeof(struct graph_node_t *));
    while(i < count && fscanf(file, "%d", &value) != EOF){
        printf("%d\n", value);
        nodes[i] = init_graph_node(value);
        ++i;
    }

    printf("-------------\n");

    while(fscanf(file, "%d %d", &index, &parent_index) != EOF){
        printf("%d %d\n", index, parent_index);
        connect_nodes(nodes[index], nodes[parent_index], 1);
    }
/*         if(start == NULL){
            start = init_graph_node(value);
            current = start;
        }
        else{
            if(current->value == parent_value){
                parent = current;
            }
            else{
                current = find_node(start, parent_value);
                parent = current;
            }
        }
        add_node(current, value, parent_value, weight); */
    //}
    fclose(file);
    return nodes[0];
}

struct graph_node_t *write_to_file(const char *filename, graph_node_t **nodes){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("File not found\n");
        return NULL;
    }

    struct graph_node_t **nodes = NULL;
    int *values = NULL;
    int count = 0, i = 0;
    int value, index, parent_index;

    fscanf(file, "%d", &count);
    nodes = (struct graph_node_t **)malloc(count * sizeof(struct graph_node_t *));
    while(i < count && fscanf(file, "%d", &value) != EOF){
        printf("%d\n", value);
        nodes[i] = init_graph_node(value);
        ++i;
    }

    printf("-------------\n");

    while(fscanf(file, "%d %d", &index, &parent_index) != EOF){
        printf("%d %d\n", index, parent_index);
        connect_nodes(nodes[index], nodes[parent_index], 1);
    }
/*         if(start == NULL){
            start = init_graph_node(value);
            current = start;
        }
        else{
            if(current->value == parent_value){
                parent = current;
            }
            else{
                current = find_node(start, parent_value);
                parent = current;
            }
        }
        add_node(current, value, parent_value, weight); */
    //}
    fclose(file);
    return nodes[0];
}

int main(){
    struct graph_node_t *start = read_from_file("graph.txt");
    print_node(start);
    return 0;
}