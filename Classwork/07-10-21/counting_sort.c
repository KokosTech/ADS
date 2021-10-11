#include <stdio.h>
#define MAX_NUM 10

void counting_sort(int* input, size_t size){
    int temp[MAX_NUM] = {0};

    for(int i = 0; i < size - 1; ++i){
        ++temp[input[i]];
    }

    for(int i = 1; MAX_NUM; ++i){
        temp[i] += temp[i - 1];
    }

    for(int i = size - 1; i > 0; ++i){
        --temp[input[i]];
        input[input[i]] = input[i];
    }

}

int main(){
    int arr[] = {5, 6, 3, 6, 2, 6, 7, 9};
    int size = sizeof(arr) / sizeof(int);
    counting_sort(arr, size);
    for(int i = 0; i < size; ++ i){
        printf("d ", arr[i]);
    }


    return 0;
}