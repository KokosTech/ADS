#include "dynamic.h"
#include "hash_table.h"
#include <math.h>

#define DEFAULT_ALLOC_SIZE 10

// #define get_name(var)  #var // this is a macro, btw
// we'll use a hash table for the "dynamic" var names, since C isn't a scripting language

int is_num(char *s){
    for (int i = 0; s[i]!= '\0'; i++)
        if(isdigit(s[i]) == 0 && s[i] != '.' && s[i] != '-')
              return 0;
    return 1;
}

int main(){
    dynamic_arr_t *arr = init_arr(DEFAULT_ALLOC_SIZE);
    hash_table_t *varnames = init(DEFAULT_ALLOC_SIZE);
    char *buf;
    buf = (char *)malloc(sizeof(char) * 256);
    double buf2 = 0;

    while(1){
        buf[0] = '\0';
        printf("Enter num/opr: ");
            scanf("%s", buf);

        if(!strcmp(buf, "exit")) {break;}

        if (is_num(buf)){
            sscanf(buf, "%lf", &buf2);
            push_back(arr, buf2);
            buf2 = 0;
        } else {
            if(!strcmp("+", buf) && arr->size >= 2){
                arr->array[arr->size - 2] += back(arr);
                pop(arr);
            } else if (!strcmp("/", buf) && arr->size >= 2){
                arr->array[arr->size - 2] /= back(arr);
                pop(arr);
            } else if (!strcmp("^", buf) && arr->size >= 2){
                arr->array[arr->size - 2] = pow(arr->array[arr->size - 2], back(arr));
                pop(arr);
            } else if (buf[0] == '@' && arr->size >= 1){
                char *res = buf + 1;
                printf("AFTER res\n");
                if (contains(varnames, res)){
                    printf("A varible with the name %s already exists, pushing back value of %lf into the stack\n", res, get(varnames, res));
                    push_back(arr, get(varnames, res));
                } else {
                    varnames = put(varnames, res, back(arr));
                    pop(arr);
                    printf("A varible with the name %s, with value of %lf, has been declared\n", res, get(varnames, res));
                }
                res = NULL;
            } else if (!strcmp("++", buf && arr->size >= 1)){
                ++arr->array[arr->size - 1];
            } else {
                printf("Unknown command\n");
            }
        }
        print_arr(arr);
    }

    // Freeing memory
    free(buf);
    buf = NULL;
    free(arr->array);
    arr->array = NULL;
    free(arr);
    arr = NULL;
    varnames = destroy_table(varnames);
}