#include "dynamic.h"
#include <string.h>

// For HW - Get commands from arguments - FOR THURSDAY
// For example - ./a.out init 10 push 5 back print
// We can use switch: -i -b ....

int main(int argc, char **argv){
    if(argc < 3){
        printf("NO INIT ARGS GIVEN\n");
        exit(-1);
    }

    if(strcmp(argv[1], "-i")){
        printf("ARR NOT INITIALIZED\n");
        exit(-1);
    }

    printf("%s\n", argv[1]);
    dynamic_arr_t *arr = init((int) strtol(argv[2], (char **)NULL, 10));
    printf("%d\n", (int) strtol(argv[2], (char **)NULL, 10));
    printf("3: %s\n", argv[3]);


    for(int i = 3; i < argc; ++i){
        if(!strcmp(argv[i], "-a")){
            printf("adding\n");
            push_back(arr, (double)strtol(argv[++i], (char **)NULL, 10));
        } else if(!strcmp(argv[i], "-b")) {
            printf("backing\n");
            printf("%d\n", back(arr));
        } else if(!strcmp(argv[i], "--print")) {
            printf("printing\n");
            print_arr(arr);
        } else if(!strcmp(argv[i], "-r")) {
            printf("popping\n");
            pop(arr);
        } else if(!strcmp(argv[i], "-f")) {
            printf("fronting\n");
            printf("%d\n", front(arr));
        }
    }

    return 0;
}