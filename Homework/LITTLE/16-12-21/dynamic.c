#include "dynamic.h"

dynamic_arr_t *init(size_t init_capacity){
    if(init_capacity < 1) exit(0);
    dynamic_arr_t *arr = (dynamic_arr_t *)malloc(sizeof(dynamic_arr_t));
    arr->size = 0;
    arr->capacity = init_capacity;

    arr->array = (double *)malloc(sizeof(double) * init_capacity);
    return arr;
}

void push_back(dynamic_arr_t *arr, double value){
    if(arr->size == arr->capacity){
        arr->array = realloc(arr->array, arr->capacity*2);
        arr->capacity *= 2;
    }
    arr->array[arr->size++] = value;
}

void pop(dynamic_arr_t *arr){
    if(arr->size)
        --arr->size;
}

double back(dynamic_arr_t *arr){
    if(arr->size)
        return arr->array[arr->size - 1];
    return 0;
}

double front(dynamic_arr_t *arr){
    if(arr->size)
        return arr->array[0];
    return 0;
}

void print_arr(dynamic_arr_t *arr){
    if(!arr) return;
    for(size_t i = 0; i < arr->size; ++i)
        printf("%.2lf ", arr->array[i]);
    printf("\n");
}
