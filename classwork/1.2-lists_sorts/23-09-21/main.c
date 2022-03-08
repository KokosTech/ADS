#include "linkedlist.h"

int main(){
    list_t* list = init();
    push(list, 'a');
    printf("% c\n", push(list, 'a'));
    printf("% c\n", push(list, 'b'));
    printf("% c\n", push(list, 'c'));
    printf("% c\n", pop(list));
    printf("% c\n", list->head->data);

    printf("\n\n");
    print_list(*list);

    free(list);
    return 0;
}