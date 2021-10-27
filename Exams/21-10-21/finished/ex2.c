#include <stdio.h>

// Sort Most Common

int get_most_common(int* arr, size_t size){
    size_t i, j, count;
    size_t most = 0;
    int temp, elem;

    for(i = 0; i < size; i++) {
        temp = arr[i];
        count = 1;
        for(j = i + 1; j < size; j++) {
            if(arr[j] == temp) {
                count++;
            }
        }
        if (most < count) {
            most = count;
            elem = arr[i];
        }
    }
    return elem;
}

int countOccurrences(int* arr, int size, int x){
    int res = 0;
    for (int i=0; i<size; i++)
        if (x == arr[i])
          res++;
    return res;
}

void sort_most_common(int* arr, size_t size){
    int com = get_most_common(arr, size), temp;
    size_t occ = countOccurrences(arr, size, com);
/* 
    for(int i = 0; i < size; ++i){
        if(arr[i] == com){
            temp = arr[0];
            arr[--occ] = com;
            for(int j = occ; j < size; ++j){
                arr[j] = arr[j+1];
                if(j == i){
                    continue;
                }
            }
        }
    } */
    for(int i = 0; i < size; ++i){
        if(arr[i] == com){
            temp = arr[--occ];
            arr[occ] = arr[i];
            arr[i] = com;
        }
    }


}  

void print_arr(int* arr, size_t size){
    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {3, 4, 2, 4, 3};
    size_t size = sizeof(arr)/sizeof(int);
    print_arr(arr, size);
    sort_most_common(arr, size);
    print_arr(arr, size);

    return 0;
}