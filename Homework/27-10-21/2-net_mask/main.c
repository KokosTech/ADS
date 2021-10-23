#include <stdio.h>
#define MASK_SIZE 4

void print_mask(unsigned char* mask){
    for(int i = 0; i < MASK_SIZE; ++i){
        printf("%d ", mask[i]);
    }
    printf("\n");
}

// Used this method for the calculation https://www.techtarget.com/searchnetworking/tip/IP-addressing-and-subnetting-Calculate-a-subnet-mask-using-the-hosts-formula
// Calculation for 255.255.255.255 - Full Subnet vs Given input
// 255.255.254.000 = 11111111 11111111 11111110 00000000 - GIVEN INPUT (EXAMPLE)
// 255.255.255.255 = 11111111 11111111 11111111 11111111 - FULL SUBNET MASK
// XOR
// 000.000.001.255 = 00000000 00000000 00000001 11111111 - RESULT
//Network:   255.255.254.0/23      11111111 11111111 11111110 00000000
//Broadcast: 255.255.255.255       11111111 11111111 11111111 11111111
//HostMin:   255.255.254.1         11111111 11111111 11111110 00000001
//HostMax:   255.255.255.254       11111111 11111111 11111111 11111110
//Hosts/Net: 510

unsigned int get_net_size(unsigned char* net_mask){
    int count = 0, res = 1;

    for(int i = 0; i < MASK_SIZE; ++i){
        if(net_mask[i] == 255)
            continue;

        net_mask[i] ^= 255;
        while(net_mask[i]){
            net_mask[i] >>= 1;
            ++count;
        }
    }

    while(count){
        res *= 2;
        --count;
    }

    res -= 2;

    return res <= 0 ? 0 : res;
}

int main(){
    unsigned char net_mask[MASK_SIZE];
    
    printf("Enter subnet mask (use spaces ' ' or 'new_lines=enter=return' instead of '.'): ");

    for(int i = 0; i < 4; ++i)
        scanf("%hhu", net_mask + i); // From scanf MANual page for converting int to uchar;

    printf("The subnet mask has: %d free adresses\n", get_net_size(net_mask));

    return 0;
}