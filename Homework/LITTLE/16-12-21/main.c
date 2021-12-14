#include "dynamic.h"
#include <string.h>
#include <ctype.h> // for isdigit
//#include <errno.h> // Including this, because if there isn't a number
// acording to the documentation of strtol - it returns error code in something 
// called errno, which I did a little digging into, and it's actually quite useful
// Actually we dont need it, we can use isdigit

// or we could use the first answ, but it says there's a diff between the std and the man page ???
// LINK https://stackoverflow.com/questions/19671001/how-can-we-check-if-an-input-string-is-a-valid-double

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

void print_help(){
    printf("dynamic.c HELP PAGE:\n\n");
    printf("USAGE: ./main.out -i [INIT_SIZE] -[OTHER_ARGS]\n\n");
    printf("ARGS:\n");
    printf("-a : this arg calls the PUSH_BACK func, basically it adds / pushes a new element\n");
    printf("-b : this arg calls the BACK func, basically it returns the back element\n");
    printf("-f : this arg calls the FRONT ffunc, basically it returns the front element\n");
    printf("-r : this arg calls the POP func, basically it removes / pops the last element\n");
    printf("--print : this arg calls the PRINT_ARR func, basically it prints the whole array\n");
    printf("--help : this arg calls the PRINT_HELP func, basically it shows what you're reading now\n");

}

int main(int argc, char **argv){
    if(argc == 2 && (!strcmp(argv[1], "--help"))){
        print_help();
        exit(0);
    }

    if(argc < 3){
        printf("NO INIT ARGS GIVEN\n");
        exit(-1);
    }

    if(strcmp(argv[1], "-i")){
        printf("ARR NOT INITIALIZED\n");
        exit(-1);
    }

    dynamic_arr_t *arr = NULL;

    if(is_num(argv[2])){
        arr = init((size_t)strtol(argv[2], (char **)NULL, 10));
    } else {
        printf("NO VALID SIZE GIVEN AT INIT\n");
        exit(-1);
    }


    for(int i = 3; i < argc; ++i){
        switch (argv[i][1]){
        case '-':
            if(!strcmp(argv[i], "--print"))
                print_arr(arr);
            break;
        case 'a':
            if(is_num(argv[++i])){
                push_back(arr, (double)strtod(argv[i], (char **)NULL));
            } else {
                printf("NO VALID VAL GIVEN AT PUSH\n");
                exit(-1);
            }
            break;
        case 'b':
            printf("%.2lf\n", back(arr));
            break;
        case 'f':
            printf("%.2lf\n", front(arr));
            break;
        case 'r':
            pop(arr);
            break;
        default:
            break;
        }
    }

    return 0;
}