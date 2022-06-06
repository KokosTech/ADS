#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DES encryption algorithm

char *DESencrypt(const char *string);
char *DESdecrypt(const char *string);

int main() {
    char *string = "Hello, world!\0";
    char *key ="ASDFGHHJ\0";
    char *encrypted = DESencrypt(string);
    printf("%s\n", encrypted);

    return 0;
}

char *DESencrypt(const char *string) {

}