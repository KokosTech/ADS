#include <stdio.h>

// XOR without XOR

int main(){
    int i = 5, j = 6;
    
    printf("%d\n", i ^ j); // XOR
    printf("%d\n", (i | j) & ~(i & j)); // User-made XOR

    return 0;
}

