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
    char *string = "BABAABAAA\0";
    node_t *head = init_queue();

    printf("%s\n", string);
    head = lzw_encode(string);
    print_queue(head);

/*     map_t *map = init_map(ASCII);
    add_ascii(map);

    printf("\nwww\n");

    printf("%d", get_value(map, "a"));
    printf("%d", get_value(map, "b")); */
    printf("%s\n", lzw_decode(head));
    return 0;
}
