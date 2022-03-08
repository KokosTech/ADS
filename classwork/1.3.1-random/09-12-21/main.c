#include "dynamic.h"

// For HW - Get commands from arguments - FOR THURSDAY
// For example - ./a.out init 10 push 5 back print
// We can use switch: -i -b ....

int main(int argc, char **argv){
    dynamic_arr_t *arr = init(10);
    push_back(arr, 10);
    push_back(arr, 12);
    print_arr(arr);
    return 0;
}