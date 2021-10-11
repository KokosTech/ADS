#include <stdio.h>

int bi_search(int* arr, size_t l, size_t r, int q){
    if(l > r)
        return -1;

    size_t mid = (l + r) / 2;

    if(arr[mid] == q)
        return mid;

    if(arr[mid] < q)
        return bi_search(arr, mid + 1, r, q);

    return bi_search(arr, l, mid - 1, q);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    printf("%d\n", bi_search(arr, 0, sizeof(arr)/sizeof(int), 7));

    return 0;
}