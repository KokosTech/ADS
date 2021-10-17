#include "skip_list.h"

int main(){
    skip_list_t list;
    init_list(&list);
    insert_update(&list, 1, 1);
    insert_update(&list, 2, 2);
    insert_update(&list, 3, 3);
    print_list(&list);

    return 0;
}