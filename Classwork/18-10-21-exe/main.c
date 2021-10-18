#include <stdio.h>
#include <stdbool.h>

unsigned int crossesAt(unsigned int x1, unsigned int v1, unsigned int x2, unsigned int v2){
    unsigned int v = v1 - v2;
    unsigned int x = x2 - x1;

    return (x / v) * v1 + x1;
}

bool crosses(unsigned int x1, unsigned int v1, unsigned int x2, unsigned int v2){
    unsigned int v = v1 - v2;
    unsigned int x = x2 - x1;

    int test = ((double)x /(double)v * (double)v1) + x1 % 10;
    while (test > 10){
        test %= 10;
    }

    return test;
}

bool crossesButBetter(unsigned int x1, unsigned int v1, unsigned int x2, unsigned int v2){
    return (!((size_t)(x1 - v1) % (size_t)(x2 - v2))) || (x1 == x2);
}

int main(){
    //printf("Crosses at: %d\n", crossesAt(59, 37, 533, 2));
    printf("Crosses hmmm: %s\n", crosses(59, 37, 533, 2) ? "True" : "False");
    printf("Crosses hmmm: %s\n", crosses(1, 3, 4, 2) ? "True" : "False");
    printf("Crosses hmmm but better: %s\n", crossesButBetter(59, 37, 533, 2) ? "True" : "False");
    printf("Crosses hmmm but better: %s\n", crossesButBetter(1, 3, 4, 2) ? "True" : "False");
    printf("Crosses hmmm but better: %s\n", crossesButBetter(1, 1, 1, 1) ? "True" : "False");

    return 0;
}