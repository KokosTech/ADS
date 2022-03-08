#include <stdio.h>
#include <stdlib.h>

int f(int x) {
    if (x == 10) {
        return 0;
    } else if (x == 15) {
        return 1;
    } else if (x == 5) {
        return 2;
    } else if (x == 35) {
        return 3;
    } else if (x == 7) {
        return 4;
    } else if (x == 20) {
        return 5;
    } else if (x == 9) {
        return 6;
    } else if (x == 1)  {
        return 7;
    } else {
        return -1;
    }
}

struct table {
    int array[8];
};

struct table* table_new() {
    struct table* t = malloc(sizeof(struct table));
    for (int i = 0; i < 8; i++) {
        t->array[i] = 0;
    }
    return t;
}

void table_add(struct table *t, int number) {
    int i = f(number);
    if (i != -1) {
        t->array[i] = number;
    }
}

void table_delete(struct table *t) {
    free(t);
}

void table_print(struct table *t) {
    for (int i = 0; i < 8; i++) {
        int number = t->array[i];
        printf("[%d] %d, ", i, number);
    }
}

int table_search(struct table *t, int x) {
    int i = f(x);
    if (i == -1) {
        return -1;
    } else {
        if (t->array[i] == x) {
            return i;
        } else {
            return -1;
        }
    }
}

int main() {
    struct table* t = table_new();
    
    table_print(t);

    int numbers[8] = {10, 15, 5, 35, 7, 20, 9, 1};
    for (int i = 0; i < 8; i++) {
        int number = numbers[i];
        table_add(t, number);
    }

    printf("\n\n");

    int numbers2[8] = {10, 0, 5, -6, 7, 2, 9, 1};
    for (int i = 0; i < 8; i++) {
        int number = numbers2[i];
        printf("%d\n", table_search(t, number));
    }
    
    return 0;
}