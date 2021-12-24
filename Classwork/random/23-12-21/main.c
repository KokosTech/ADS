#include "dynamic.h"
#include <ctype.h> // for isdigit
#include <string.h>

// For HW - Get commands from arguments - FOR THURSDAY
// For example - ./a.out init 10 push 5 back print
// We can use switch: -i -b ....

int is_num(char *s){
    for (int i = 0; s[i]!= '\0'; i++){
        if(isdigit(s[i]) == 0 && s[i] != '.')
              return 0;
    }
    return 1;
}

int main(){
    dynamic_arr_t *arr = init(10);
    char buf[256];
    while(1){
        buf[0] = '\0';
        printf("Enter num/opr: ");
            scanf("%s", buf);

        if (is_num(buf)){
            double buf2 = 0;
            sscanf(buf, "%lf", &buf2);
            push_back(arr, buf2);
        } else {
            if(arr->size >= 2){
                if(!strcmp("+", buf)){
                    arr->array[arr->size - 2] += back(arr);
                    pop(arr);
                } else if (!strcmp("/", buf)){
                    arr->array[arr->size - 2] /= back(arr);
                    pop(arr);
                }
            } else if (!strcmp("++", buf)){
                ++arr->array[arr->size - 1];
            } else {
                printf("Unknown command\n");
            }
        }
        print_arr(arr);
    }
    return 0;
}