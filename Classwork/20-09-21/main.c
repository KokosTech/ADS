#include <stdio.h>

int count_of_ones(int num){
    int count_of_ones = 0;

    while(num != 0){
        count_of_ones += (num & 1);
        num  >>= 1;
    }

    return count_of_ones;
}

int main(){
    int num = 0;
    scanf("%d", &num);
    printf("%d\n", count_of_ones(num));

    return 0;
}