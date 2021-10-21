#include <stdio.h>
#define MASK_SIZE 4

void print_mask(unsigned char* mask){
    for(int i = 0; i < MASK_SIZE; ++i){
        printf("%d ", mask[i]);
    }
    printf("\n");
}

unsigned int get_net_size(unsigned char* net_mask){
    int count = 0, res = 1;

    for(int i = 0; i < MASK_SIZE; ++i){
        if(net_mask[i] == 255)
            continue;

        net_mask[i] ^= 255;
        while(net_mask[i] != 0){
            ++count;
            net_mask[i] >>= 1;
        }
    }

    while(count != 0){
        res *= 2;
        --count;
    }

    return res - 2;
}

int main(){
    unsigned char net_mask[MASK_SIZE] = {255, 255, 255, 248};

    print_mask(net_mask);
    printf("%d\n", get_net_size(net_mask));

    return 0;
}