#include <stdio.h>
#include <stdlib.h>
#define MAX_BUCKET 5
#define NEW_LINE printf("\n");

int max(int* arr, int size){
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int min(int* arr, int size){
    int min = arr[0];
    for (int i = 1; i < size; ++i)
        if(arr[i] < min)
            min = arr[i];
    return min;
}

int* sort(int* arr, int size){
    // Bottom of recursion / Checks

    if(size == 0)
        return NULL;

    if(size == 1)
        return arr;

    // Vars for the last check / for the algorithm

    int __min = min(arr, size), __max = max(arr, size);

    if(__min == __max)
        return arr;

    int x = (__max - __min) / MAX_BUCKET;
    int bs[MAX_BUCKET] = {0};
    int bs_temp[MAX_BUCKET] = {0};

    // Getting the size for the buckets - we could use resize instead of 2 separate loops

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < MAX_BUCKET; ++j){
            int temp = __min + + x * j;
            (x == 0) ? x++ : x;
            if(arr[i] <= temp){
                ++bs[j];
                ++bs_temp[j];
                break;
            }
            if(j == MAX_BUCKET - 1){
                ++bs[j];
                ++bs_temp[j];
            }
        }
    }

    // Heap memory allocation 

    int** arr_sorted;
    arr_sorted = (int**)calloc(MAX_BUCKET, sizeof(int*));
    for(int i = 0; i < MAX_BUCKET; ++i)
        arr_sorted[i] = (int*)calloc(bs[i], sizeof(int));
    int* arr_sorted_full = (int*)calloc(size, sizeof(int));

    // Filling the buckets

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < MAX_BUCKET; ++j){
            int temp = __min + + x * j;
            (x == 0) ? x++ : x;
            if(arr[i] <= temp){
                arr_sorted[j][--bs[j]] = arr[i];
                break;
            }
            if(j == MAX_BUCKET - 1){
                arr_sorted[j][--bs[j]] = arr[i];
            }
        }
    }

    // Recursion - aka sorting the buckets -> cat-ing them -> freeing them

    for(int i = 0, idx = 0; i < MAX_BUCKET; ++i){
        arr_sorted[i] = sort(arr_sorted[i], bs_temp[i]);
        for(int j = 0; j < bs_temp[i]; ++j){
            if(arr_sorted != NULL){
                arr_sorted_full[idx] = arr_sorted[i][j];
                ++idx;
            }
        }
        free(arr_sorted[i]);
    }
    free(arr_sorted); 
    return arr_sorted_full;
}

int main(){
    int arr[] = {42, 32, 33, 52, 37, 47, 51, 12, 12, 3, 4, -5, 10, 6, 2, 23, 9};
    int size = sizeof(arr)/sizeof(int);
    int* sorted = sort(arr, size);

    for(int i = 0; i < size; ++i){
        printf("%d ", sorted[i]);
    } NEW_LINE

    return 0;
}