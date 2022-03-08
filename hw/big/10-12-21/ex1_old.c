#include <stdio.h>

void* xor (void *a, void *b) {
	return (void*)((uintptr_t)a ^ (uintptr_t)b);
}

void swap(int** a, int** b) {
    *a = (int*)xor(*a, *b);
    *b = (int*)xor(*b, *a);
    *a = (int*)xor(*a, *b);
}

void heapsort(int *arr, unsigned int size){
    for(int i = size/2; i >= 0; --i)
        for(int j = i; j < size; ++j)
            if(arr[j] < arr[i])
                swap(&arr[i], &arr[j]);

    for(int i = size-1; i > 0; --i){
        swap(&arr[0], &arr[i]);

        for(int j = 0; j < i; ++j)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
}

int main(){
    int arr[] = {55, 32, 65, 33, 67, 23, 6, 2, 8, 23, 201};
    heapsort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}