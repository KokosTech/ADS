#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "map.h"
#include "lzw.h"

// Personal SEO:
// Project Title: LZW Compression
// Author: KokosTech @ https://github.com/kokostech
// Language: c
// Subject: Algorithms and data structures, 10th grade
// Type: LITTLE homework

int main() {
    char *string = "yeeee, woooo, it fucking woooorks!!!!\0";
    node_t *head = init_queue();

    printf("RAW: %s\n", string);
    head = lzw_encode(string);
    
    printf("Encoded: ");
    print_queue(head);

    printf("Decoded: %s\n", lzw_decode(head));
    return 0;
}
