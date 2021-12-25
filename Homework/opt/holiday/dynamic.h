#pragma once
#include <stdio.h>
#include <stdlib.h>

// Stack Dynamic Array

typedef struct {
    double *array;
    size_t size;
    size_t capacity;
} dynamic_arr_t;

dynamic_arr_t *init_arr(size_t init_capacity);
void push_back(dynamic_arr_t *arr, double value);
void pop(dynamic_arr_t *arr);
double back(dynamic_arr_t *arr);
double front(dynamic_arr_t *arr);

void print_arr(dynamic_arr_t *arr);
