#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIRS 4
#define DEBUG_CAP 1000

typedef struct pair_t {
    int r; // x
    int c; // y
} pair_t;

typedef struct notmac_route_t {
    size_t count;
    size_t capacity;

    pair_t **pairs;
} notmac_route_t; // DONT ASK ABOUT THE FUCKING NAME

typedef struct stack_element_t {
    pair_t *pair;
    notmac_route_t *route;
} stack_element_t;

typedef struct stack_t {
    size_t capacity;

    size_t top;
    stack_element_t **elements;
} stack_t;

// Inits

pair_t *init_pair(int r, int c) {
    pair_t *pair = (pair_t *)malloc(sizeof(pair_t));
    pair->r = r;
    pair->c = c;

    return pair;
}

notmac_route_t *init_routes(size_t size) {
    notmac_route_t *route = malloc(sizeof(notmac_route_t));
    route->pairs = (pair_t **)malloc(sizeof(pair_t *) * size);

    route->count = 0;
    route->capacity = size;

    return route;
}

stack_element_t *init_stack_element(pair_t *pair, size_t size) {
    stack_element_t *element = malloc(sizeof(stack_element_t));
    element->pair = pair;
    element->route = init_routes(size);

    return element;
}

stack_t *init_stack(size_t size) {
    stack_t *stack = malloc(sizeof(stack_t));
    stack->elements = (stack_element_t **)malloc(sizeof(stack_element_t *) * (size + 1));

    stack->capacity = size;
    stack->top = -1;

    return stack;
}

// Dynamic

void resize_route(notmac_route_t *route){
    route->pairs = realloc(route->pairs, sizeof(pair_t) * route->count * 2);
}

void resize_stack(stack_t *stack) {
    stack->elements = realloc(stack->elements, sizeof(stack_element_t *) * stack->capacity * 2);
    stack->capacity *= 2;
}

// Add

notmac_route_t *add_route(notmac_route_t *route, int r, int c) {
    if(route->count == route->capacity)
        resize_route(route);

    pair_t *pair = malloc(sizeof(pair_t));
    pair->r = r;
    pair->c = c;
    route->pairs[route->count++] = pair;

    return route;
}

void dfs(int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, char grid[r][c]) {
    char **board = malloc(sizeof(char *) * r);for (int i = 0; i < r; i++) {
        board[i] = malloc(sizeof(char) * c);
        memcpy(board[i], grid[i], sizeof(char) * c);
    }

    notmac_route_t *visited = init_routes(DEBUG_CAP);
    notmac_route_t *result = init_routes(DEBUG_CAP);

    stack_t *stack = init_stack(DEBUG_CAP);

    int directions[][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    stack_element_t *start = init_stack_element(init_pair(pacman_r, pacman_c), DEBUG_CAP);
    stack->elements[++stack->top] = start;

    while (stack->top != -1) {
        stack_element_t *temp = stack->elements[stack->top--];
        
        temp->route = add_route(temp->route, temp->pair->r, temp->pair->c);
        visited = add_route(visited, temp->pair->r, temp->pair->c);

        if (temp->pair->r == food_r && temp->pair->c == food_c){
            for (size_t i = 0; i < temp->route->count; ++i, ++result->count)
                result->pairs[i] = temp->route->pairs[i];
            break;
        }

        for (size_t i = 0; i < DIRS; ++i) {
            int next_r = temp->pair->r + directions[i][0];
            int next_c = temp->pair->c + directions[i][1];

            if (next_r < 0 || next_r >= r || next_c < 0 && next_c >= r)
                continue;

            if (board[next_r][next_c] == '-' || board[next_r][next_c] == '.'){
                board[next_r][next_c] = '=';
                stack_element_t *new_stack_element = init_stack_element(init_pair(next_r, next_c), DEBUG_CAP);
                new_stack_element->route->count = temp->route->count;
                memcpy(new_stack_element->route->pairs, temp->route->pairs, sizeof(pair_t) * temp->route->count);
/*                 for (size_t i = 0; i < temp.count; ++i)
                    newEl.routes[i] = temp.routes[i]; */
                stack->elements[++stack->top] = new_stack_element;
            }
        }
    }

    printf("%ld\n", visited->count);
    for (size_t i = 0; i < visited->count; ++i)
        printf("%d %d\n", visited->pairs[i]->r, visited->pairs[i]->c);
    
    printf("%ld\n", result->count - 1);
    for (size_t i = 0; i < result->count; ++i)
        printf("%d %d\n", result->pairs[i]->r, result->pairs[i]->c);
    
    // Freeing memory

/*     for (size_t i = 0; i < result->count; ++i)
        free(result->pairs[i]);
    free(result->pairs);
    free(result);

    for (int i = 0; i < r; i++)
        free(board[i]);
    free(board);

    for (size_t i = 0; i < stack->top; ++i) {
        for (size_t j = 0; j < stack->elements[i]->route->count; ++j)
            //free(stack->elements[i]->route->pairs[j]);
        free(stack->elements[i]->route->pairs);
        free(stack->elements[i]->route);
        free(stack->elements[i]);
    }

    free(stack->elements);
    free(stack);

    for (size_t i = 0; i < visited->count; ++i)
        free(visited->pairs[i]);
    free(visited->pairs);
    free(visited); */

    return;
}

int main(void){

    int r, c;
    int pacman_r, pacman_c;
    int food_r, food_c;
    scanf("%d %d", &pacman_r, &pacman_c);
    scanf("%d %d", &food_r, &food_c);
    scanf("%d %d", &r, &c);
    char grid[r][c];

    for( int i = 0; i < r; i++) {
        scanf("%s[^\\n]%*c", grid[i]);
    }
    dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);
    return 0;
}
