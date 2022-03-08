#include"graph.h"

int main() {
  graph_node_t* first = init_graph_node(5);
  
  add_node(first, 10, 5);
  add_node(first, 12, 5);
  add_node(first, 14, 5);
  
  add_node(first, 20, 10);
  add_node(first, 30, 20);
  
  add_node(first->items[0]->items[1], 40, 5);
  
  print_node(first->items[0]);
  
  return 0;
}
