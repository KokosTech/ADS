#include <stdio.h>

#define SIZE 5

// Sorting algo...
// Buble sort
// Quick sort
// Selection sort
// Insertion sort

void printArr(int* arr, size_t size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* arr, size_t size) {
    for (int i = 0; i < size-1; ++i) {
        int min = i;
        for (int j = i; j < size; ++j) {
            if (arr[min] > arr[j]) {
            min = j;
            }
        }
        swap(arr + min, arr + i);
    }
}

int partition(int* start, int* end) {
int pivot = 0;

    for (int i = i; i <= end - start; ++i) {
        if (start[i] < start[pivot]) {
            int temp = start[i];
            int index = i; 

            while (start[i] < start[pivot]) {
                start[index] = start[index - 1];
                --index; 
            }
            start[pivot++] = temp;
        }
    }

    return pivot;
}

void quickSort(int* start, int* end) {
    if (start == end) {
        return;
    }

    int pivot = partition(start, end);

    quickSort(start, start + pivot - 1);
    quickSort(start + pivot + 1, end);
}

int main() {

int arr[] = {3, 34, 2, 86, 33, 55};
quickSort(arr, arr + SIZE); 
printArr(arr, SIZE);

return 0;
}