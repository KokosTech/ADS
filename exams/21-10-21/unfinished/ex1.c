#include <stdio.h>
#define BYTE_SIZE 8

unsigned int count_patern(short data){
    size_t count = 0;
    for(int i = 0; i < BYTE_SIZE * sizeof(short); ++i){
        if(data>>i & 1 && data>>(i+1) & 1)
            ++count;
    }
    return count;
}

int main(){
    printf("Count: %d\n", count_patern(19811));

    return 0;
}