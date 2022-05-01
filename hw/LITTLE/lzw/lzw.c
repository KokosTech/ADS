#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "map.h"
#include "queue.h"
#include "lzw.h"

#define SCHAR 2
#define DEF_BUFFER 3

char *cat(char *s1, char *s2) {
    if(!s1 || !s2) return NULL;
    printf("%s + %s\n", s1, s2);
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char *to_string(short val) {
    char *result = malloc(sizeof(char) * SCHAR);
    result[0] = (unsigned char)val;
    result[1] = '\0';
    return result;
}

char *n_to_s(short val) {
    char *res = malloc(sizeof(char) * SCHAR * 3);
    sprintf(res, "%hu", val);
    return res;
}

void add_ascii(map_t *map) {
    if(!map) return;
    unsigned char *init_char = malloc(sizeof(unsigned char) * SCHAR);
    
    for(unsigned short i = 0; i < ASCII; ++i) {
        init_char[0] = (unsigned char)i;
        init_char[1] = '\0';
        map = put(map, init_char, n_to_s(i));
    }

    free(init_char);
}

void add_ascii_r(map_t *map) {
    if(!map) return;
    unsigned char *init_char = malloc(sizeof(unsigned char) * SCHAR);
    
    for(unsigned short i = 0; i < ASCII; ++i) {
        init_char[0] = (unsigned char)i;
        init_char[1] = '\0';
        map = put(map, n_to_s(i), init_char);
    }

    free(init_char);
}

node_t *lzw_encode(char *string) {
    node_t *head = init_queue();
    map_t *map = init_map(ASCII);

    add_ascii(map);

    char *buffer = (char *)malloc(sizeof(char) * DEF_BUFFER);

    size_t str_c = 0, buff_c = 0, new_sym = 0;

    buffer[buff_c++] = string[str_c++];

    while(string[str_c] != '\0') {
        buffer[buff_c++] = string[str_c++];
        buffer[buff_c] = '\0';

        //printf("%s\n", buffer);
        
        if(!contains(map, buffer)) {
            char* substring = malloc(sizeof(char) * (buff_c - 0));
            
            for(int i = 0; i < buff_c - 1; ++i) 
                substring[i] = buffer[i];
            substring[buff_c - 1] = '\0';

            US val = strtoul(get_value(map, substring), NULL, 0);
            printf("\"%s\" : %d\n", substring, val);
            push(&head, val);

            free(substring);
            put(map, buffer, n_to_s(ASCII + new_sym++));
            buffer[0] = buffer[buff_c-1];
            buffer[1] = '\0';
            buff_c = 1;
        } else {
            buffer = (char *)realloc(buffer, strlen(buffer) + SCHAR);
        }
    }

    push(&head, strtoul(get_value(map, buffer), NULL, 0));

    //print(map);

    return head;
}



/*
    *    PSEUDOCODE
    1    Initialize table with single character strings
    2    OLD = first input code // current
    3    output translation of OLD
    4    WHILE not end of input stream
    5        NEW = next input code // next
    6        IF NEW is not in the string table
    7               S = translation of OLD
    8               S = S + C
    9       ELSE
    10              S = translation of NEW
    11       output S
    12       C = first character of S
    13       OLD + C to the string table
    14       OLD = NEW
    15   END WHILE
*/

char *lzw_decode(node_t *head) {
    map_t *map = init_map(ASCII);
    char *result = malloc(sizeof(char));
    
    result[0] = '\0';

    add_ascii_r(map);

    char* temp_str = calloc(sizeof(char), 1);
    short new_sym = 0;
    node_t *current, *next;
    char *old = malloc(sizeof(char) * 50);
    char *new = malloc(sizeof(char) * 50);

    current = head;
    old = n_to_s(current->val);
    temp_str = cat(temp_str, old);

    head = pop(head);
    //current = current->next;

    while(current) {
        printf("WHILE: %s\n", temp_str);
        new = n_to_s(head->val);
        temp_str = cat(temp_str, get_value(map, new));
        
        //current = pop(current);
        //current = current->next;
        head = pop(head);

        printf("ASCII - %s\n", n_to_s(ASCII + new_sym));
        if(!contains(map, n_to_s(ASCII + new_sym))) {
            result = cat(result, get_value(map, old));
            put(map, n_to_s(ASCII + new_sym++), temp_str);
            memset(temp_str, 0, strlen(temp_str));
            strcpy(old, new);
            temp_str = cat(temp_str,  get_value(map, old));
        }
    }

    result = cat(result, get_value(map, old));

    return result;
}