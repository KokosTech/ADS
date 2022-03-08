#include "linkedlist.h"

bool strict_sub_list(node_t *head) {
    if(head == NULL || head->next == NULL)
        return 1;
    
    double _start = head->start, _end = head->end, _next_start = head->next->start, _next_end = head->next->end;

    if(head->start > head->end){
        _start = (uintptr_t)_start ^ (uintptr_t)_end;
        _end = (uintptr_t)_end ^ (uintptr_t)_start;
        _start = (uintptr_t)_start ^ (uintptr_t)_end;
    }
        
    if(head->next->start > head->next->end){
        _next_start = (uintptr_t)_next_start ^ (uintptr_t)_next_end;
        _next_end = (uintptr_t)_next_end ^ (uintptr_t)_next_start;
        _next_start = (uintptr_t)_next_start ^ (uintptr_t)_next_end;
    }
        
    //printf("S: %lf; NS: %lf\t", _start, _next_start);
    //printf("E: %lf; NE: %lf\n", _end, _next_end);

    if((_start <= _next_start && _end > _next_end)
    || (_start < _next_start && _end >= _next_end))
        return strict_sub_list(head->next);

    return 0;
}

int main(){
    node_t *head = push(NULL, 7, 11);
    head = push(head, 6, 11);
    head = push(head, 5, 11);
    head = push(head, 4, 11);
    head = push(head, 11, 3);
    head = push(head, 2, 11);
    head = push(head, 1, 11);
    head = push(head, -10, 11);
    printf("%d\n", strict_sub_list(head));
    head = destroy_list(head);
    return 0;
}