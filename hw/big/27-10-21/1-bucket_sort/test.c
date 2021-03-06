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
    if(size == 0)
        return NULL;

    if(size == 1)
        return arr;

    int** arr_sorted;
    arr_sorted = (int**)calloc(MAX_BUCKET, sizeof(int*));

    int x = (size < MAX_BUCKET) ? ((max(arr, size) - min(arr, size)) / MAX_BUCKET) + 1 : max(arr, size) / MAX_BUCKET;
    int bs[MAX_BUCKET] = {0};
    int bs_temp[MAX_BUCKET] = {0};
    int count = 0;

    //printf("\n[SIZE] %d | [MAX] %d | [MIN] %d | [X] %d\n", size, max(arr, size), min(arr, size), x);
    for(int i = 0; i < size; ++i){
        for(int j = 1; j <= MAX_BUCKET; ++j){
            int temp = (size < MAX_BUCKET) ? min(arr, size) + x * j : x * (j + 1);
            //printf("arr (%d) ? temp (%d)\n", arr[i], temp);
            if(arr[i] <= temp+1){
                ++bs[j-1];
                ++bs_temp[j-1];
                break;
            }
        }
    }


    for(int i = 0; i < MAX_BUCKET; ++i)
        printf("%d ", bs[i]);
    printf("\n");

    for(int i = 0; i < MAX_BUCKET; ++i){
        arr_sorted[i] = (int*)calloc(bs[i], sizeof(int));
        if(bs[i] > 0)
            ++count;
    }

    if(count == 1){
        int bs[MAX_BUCKET] = {0};
        int bs_temp[MAX_BUCKET] = {0};
        int med = 0;
        for(int i = 0; i < size; ++i)
            med += arr[i];
        med /= size;
        x = (max(arr, size) - min(arr, size)) / 5;

        //printf("\n[SIZE] %d | [MAX] %d | [MIN] %d | [X] %d\n", size, max(arr, size), min(arr, size), x);
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < MAX_BUCKET; ++j){
                int temp = min(arr, size) + (x) * j;
                (x == 0) ? ++x : x;
                //printf("arr (%d) ? temp (%d)\n", arr[i], temp);
                if(arr[i] <= temp){
                    ++bs[j];
                    ++bs_temp[j];
                    break;
                }
            }
        }

        for(int i = 0; i < size; ++i){
            for(int j = 0; j < MAX_BUCKET; ++j){
                int temp = min(arr, size) + (x) * j;
                (x == 0) ? ++x : x;
                //printf("arr (%d) ? temp (%d)\n", arr[i], temp);
                if(arr[i] <= temp){
                    //printf("[ADDED] %d: buck (%d) & bs (%d)\n", arr[i], j, bs[j]);
                    arr_sorted[j][--bs[j]] = arr[i];
                    //printf("[NEW_ARR_VAL] %d\n", arr_sorted[j][bs[j]]);
                    break;
                }
            }
        }
        int* arr_sorted_full = (int*)calloc(size, sizeof(int));
        int idx = 0;
        for(int i = 0; i < MAX_BUCKET; ++i){
            for(int j = 0; j < bs_temp[i]; ++j){
                if(arr_sorted[j] != NULL){
                    arr_sorted_full[idx] = arr_sorted[i][j];
                    ++idx;
                }
            }
        }

        return arr_sorted_full;
    }

/*     for(int i = 0; i < MAX_BUCKET; ++i){
        for(int j = 0; j < size; ++j){
            int temp = x * j;
            if(arr[j] <= temp){
                arr_sorted[i][--bs[i]] = arr[j];
                break;
            }
        }
    } */

    for(int i = 0; i < size; ++i){
        for(int j = 1; j <= MAX_BUCKET; ++j){
            int temp = (size < MAX_BUCKET) ? min(arr, size) + x * j : x * (j + 1);
            //printf("arr (%d) ? temp (%d)\n", arr[i], temp+1);
            if(arr[i] <= temp+1){
                //printf("[ADDED] %d: buck (%d) & bs (%d)\n", arr[i], j-1, bs[j-1]);
                arr_sorted[j-1][--bs[j-1]] = arr[i];
                //printf("[NEW_ARR_VAL] %d\n", arr_sorted[j-1][bs[j-1]]);
                break;
            }
        }
    }

/*     for(int i = 0; i < MAX_BUCKET; ++i){
        printf("Bucket %d: ", i + 1);
        for(int j = 0; j < bs_temp[i]; ++j){
            printf("%d ", arr_sorted[i][j]);
        } NEW_LINE
    } NEW_LINE */

    int* arr_sorted_full = (int*)calloc(size, sizeof(int));
    int idx = 0;
    for(int i = 0; i < MAX_BUCKET; ++i){
        arr_sorted[i] = sort(arr_sorted[i], bs_temp[i]);
        for(int j = 0; j < bs_temp[i]; ++j){
            if(arr_sorted[j] != NULL){
                arr_sorted_full[idx] = arr_sorted[i][j];
                ++idx;
            }
        }
    }

    return arr_sorted_full;
}

int main(){
    int arr[] = {29, 30, 31, 32, 33, 50, 20, 43};
    int size = sizeof(arr)/sizeof(int);
    int* sorted = sort(arr, size);

    printf("Size of array: %d\n", size);
    for(int i = 0; i < (int)(sizeof(arr)/sizeof(int)); ++i){
        printf("%d ", sorted[i]);
    } NEW_LINE;
    return 0;
}
