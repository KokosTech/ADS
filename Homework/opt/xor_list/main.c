#include <stdio.h>
#include <stdlib.h>

typedef struct list_t{
    struct list_t* p;
    int data;
} list_t;

void* xor (void* a, void* b) {
    return (void*)((long unsigned int)a ^ (long unsigned int)b);
}

list_t* x_remove(list_t* list){
    if (list == NULL)
        return NULL;

    list_t *next_item = list->p;
    free(list);

    if (next_item == NULL)
        return NULL;
    
    next_item->p = xor(list, next_item->p);
    
    return next_item;
}

list_t* destroy_list(list_t *list){
    //for(list_t *curr_item=list; curr_item!=NULL;curr_item=x_remove(curr_item));
    for (; list != NULL; list = x_remove(list));

    return NULL;
}

list_t* add(list_t* list, int data){
    list_t* item = malloc(sizeof(list_t));
    item->data = data;

    /*if(!list->p)
    list->p = list->p ^ item;

    else
    list->p = (list->p ^ item) ^ list->p;*/

    //item -> p = NULL ^ list;
    item->p = list;
    
    if(list == NULL){
        list->p = NULL;
    }
    // list->p = item ^ list->p;

    if (list != NULL)
        list->p = xor(item, list->p);
    
    return item;
}

void print_list(list_t* list){
    list_t* prev = NULL;
    list_t* tmp = list;

    while (tmp != NULL){
        printf("tmp=%p data=%d p=%p\n", tmp, tmp->data, tmp->p);

        list_t* tmp2 = tmp;
        //tmp = tmp->p ^ prev;
        tmp = xor(tmp->p, prev);
        prev = tmp2;
    }

    puts("");
}

int find_value(list_t* list, int value_to_find){
    list_t* prev = NULL;
    list_t* tmp = list;

    int index = 0;

    while(tmp->data != value_to_find){
        if(list->p == NULL)
            return -1;
        ++index;
        list_t* tmp2 = tmp;
        tmp = xor(tmp->p, prev);
        prev = tmp2;
    }

    return index;
}

int main(){
    //list_t list1= {NULL,5};
    //list_t* list = &list1;
    list_t *list = NULL;
    list = add(list, 5);

    list = add(list, 10);
    list = add(list, 15);
    list = add(list, 20);
    //print_list(list);

    list = x_remove(list);
    list = x_remove(list);
    print_list(list);
    printf("\n%d\n", find_value(list, 5));

    /*for(list_t* tmp = list; tmp != NULL; tmp = tmp->next)
    {
    printf("%d ", tmp->data);
    }
    puts("");*/
    return 0;
}