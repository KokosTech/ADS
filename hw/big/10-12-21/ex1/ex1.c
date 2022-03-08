#include <stdio.h>  
#include <stdlib.h>

/* void swap(int* xp, int* yp){
    *xp = *xp ^ *yp;
    *yp = *xp ^ *yp;
    *xp = *xp ^ *yp;
} */

void heapify(int *a, size_t n, size_t i)  {  
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])  
        largest = left;  

    if (right < n && a[right] > a[largest])  
        largest = right;  

    if (largest != i) {  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  

void heapSort(int *a, size_t n)  {  
    for (int i = n / 2 - 1; i > -1; --i)  
        heapify(a, n, i);  

    for (int i = n - 1; i > -1; --i){  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  

void printArr(int *arr, size_t n){  
    // Some people say I write C in to Python-y way 
    for (size_t i = 0; i < n; ++i)
        printf("%d ", arr[i]);  
    
    printf("\n");
}  

int main()  {  
    int arr[] = {55, 32, 65, 33, 67, 23, 6, 2, 8, 23, 201};
    size_t arr_size = sizeof(arr) / sizeof(int);

    printf("[BEFORE] ");
    printArr(arr, arr_size); // Before
    
    heapSort(arr, arr_size); // Sort
    
    printf("[AFTER] ");
    printArr(arr, arr_size); // After
    return 0;  
}
