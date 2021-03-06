#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EDGE_W 6

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */

typedef struct queue {
    int *arr;
    int push;
    int pop;
} queue_t;

queue_t *init_queue(size_t size) {
    queue_t *q = (queue_t *)calloc(1, sizeof(queue_t));
    q->arr = (int *)malloc((size + 1) * sizeof(int));
    return q;
}

int *bfs(int n, int m, int edges_rows, int edges_columns, int** edges, int s, int* result_count) {    
    int current = 0;
    *result_count = n;

    int *visited = (int *)calloc(n, sizeof(int));
    int *result = (int *)malloc((n) * sizeof(int));
    
    queue_t *q = init_queue(n);
    
    for(int i = 0; i < n; ++i)
        *(result + i) = -1; 
    result[s - 1] = 0;

    q->arr[q->push++] = s;
    visited[s - 1] = 1;

    while(q->push != q->pop){ 
        current = q->arr[q->pop++];

        for(int i = 0; i < edges_rows; ++i) { 
            for(char j = 0; j < 2; ++j) {
                if(edges[i][j] == current && visited[edges[i][!j] - 1] == 0) {
                    visited[edges[i][!j] - 1] = 1;

                    int *temp = &result[edges[i][!j] - 1];
                    (*temp) = ((*temp) > result[current - 1] + EDGE_W || (*temp) == -1) ? result[current - 1] + EDGE_W :(*temp);
                    temp = NULL;

                    q->arr[q->push++] = edges[i][!j];
                    break;
                }
            }
        }
    }

    free(visited);
    visited = NULL;
    free(q->arr);
    q->arr = NULL;
    free(q);
    q = NULL;
    return result;
}

int main(){
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int q = parse_int(ltrim(rtrim(readline())));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));

        int n = parse_int(*(first_multiple_input + 0));

        int m = parse_int(*(first_multiple_input + 1));

        int** edges = malloc(m * sizeof(int*));

        for (int i = 0; i < m; i++) {
            *(edges + i) = malloc(2 * (sizeof(int)));

            char** edges_item_temp = split_string(rtrim(readline()));

            for (int j = 0; j < 2; j++) {
                int edges_item = parse_int(*(edges_item_temp + j));

                *(*(edges + i) + j) = edges_item;
            }
        }

        int s = parse_int(ltrim(rtrim(readline())));

        int result_count;
        int* result = bfs(n, m, m, 2, edges, s, &result_count);

        for (int i = 0; i < result_count; i++) {
            if(i != s-1){
                fprintf(fptr, "%d", *(result + i));

                if (i != result_count - 1) 
                    fprintf(fptr, " ");
            }
        }

        fprintf(fptr, "\n");
        free(result);
        result = NULL;
        for(int i = 0; i < m; ++i) {
            free(*(edges + i));
            *(edges + i) = NULL;
        }
        free(edges);
        edges = NULL;
        free(first_multiple_input);
    }

    fclose(fptr);
    fptr = NULL;

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

