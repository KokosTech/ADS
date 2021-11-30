#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// O(n)

int minEk(int arr[], size_t size){
    int currentMin = arr[0];
    for(int i = 1; i < size; ++i)
        if(currentMin > arr[i])
            currentMin = arr[i];

    return currentMin;
}

// O(n^2)

int stupidMinEl(int arr[], size_t size){
    int currentMin = arr[0];
    bool isMin = true;
    int x;
    for(x = 0; x < size; ++x){
        isMin = true;
        for(int y = 0; y < size; ++y){
            if(arr[x] > arr[y])
                isMin = false;
        }
        if(isMin)
            break;
    }

    return arr[x];
}

bool isPrime(int num){
    if(num == 2)
        return true;
    else if (num <= 1)
        return false;

    for(int i = 2; i < sqrt(num); ++i)
        if(num % i == 0)
            return false;

    return true;
}

int main(){
    printf("%d", isPrime(101));
    return 0;
}