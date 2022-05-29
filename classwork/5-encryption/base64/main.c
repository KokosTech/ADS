#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZERO '='

static const char base64_table[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
  'w', 'x', 'y', 'z', '0', '1', '2', '3',
  '4', '5', '6', '7', '8', '9', '+', '/'
};

size_t get_base64_size(char *string) {
    return strlen(string) * 4 / 3 + 4; // ==, \n, ????
}

char *base64_encode(const char *string) {
    size_t len = strlen(string);
    size_t base64_len = get_base64_size(string);
    char *base64 = (char *)malloc(base64_len * sizeof(char));

    for(size_t i = 0; i < len / 3; ++i) {
        base64[i] = string[i] << 3;
    }

    return base64;
}

int main() {


    return 0;
}