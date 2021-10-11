#include <stdio.h>
#define ARR_SIZE 5

void print_array(int* arr, size_t size){
    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int* arr, size_t size){
    for(int i = 0; i < size - 1; ++i){
        int min = i;
        for(int j = i; j < size; ++j){
            if(arr[min] > arr[j])
                min = j;
        }
        swap(arr + min, arr + i);
    }
}

int main(){
    int arr[ARR_SIZE];

    for(int i = 0; i < ARR_SIZE; ++i){
        scanf("%d", arr + i);
    }

    print_array(arr, ARR_SIZE);
    sort(arr, ARR_SIZE);
    print_array(arr, ARR_SIZE);

    return 0;
}