#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "map.h"
#include "queue.h"

#define ASCII 256

node_t *lzw_encode(char *string);
char *lzw_decode(node_t *head);
 void add_ascii(map_t *map);