#include "xor_list.h"

node_t *add(node_t *head, short value){
    node_t new_node = (node_t *)malloc(sizeof(node_t));
    new_node->xpn = head;
    new_node->value = value;
}