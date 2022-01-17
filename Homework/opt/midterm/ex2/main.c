#include "linkedlist.h"

bool strict_sub_list(node_t *head) {
    if(head == NULL || head->next == NULL)
        return 1;
    
    // printf("S: %lf; NS: %lf\t", head->start, head->next->start);
    // printf("E: %lf; NE: %lf\n", head->end, head->next->end);

    if((head->start <= head->next->start && head->end > head->next->end)
    || (head->start < head->next->start && head->end <= head->next->end))
        return strict_sub_list(head->next);

    return 0;
}

int main(){
    node_t *head = push(NULL, 7, 11);
    head = push(head, 6, 11);
    head = push(head, 5, 11);
    head = push(head, 4, 11);
    head = push(head, 3, 11);
    head = push(head, 2, 11);
    head = push(head, 1, 11);
    head = push(head, -100, 100);
    printf("%d\n", strict_sub_list(head));
    head = destroy_list(head);
    return 0;
}