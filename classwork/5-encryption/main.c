#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher(char *str) {
    char ch;

    for(size_t i = 0; i < strlen(str); i++) {
        ch = str[i];
        
        if(ch == 'z') ch = 'a';
        else ch += 1;
        str[i] = ch;
    }
}

void cipherN(char *str, unsigned short n) {
    char ch;
    size_t alphaLen = 'z' - 'a' + 1;

    for(size_t i = 0; i < strlen(str); i++) {
        ch = str[i];
        ch = (ch - 'a' + n) % alphaLen + 'a';
        str[i] = ch;
    }
}

void decipherN(char *str, unsigned short n) {
    char ch;
    size_t alphaLen = 'z' - 'a' + 1;

    for(size_t i = 0; i < strlen(str); i++) {
        ch = str[i];
        ch = (ch - 'a' - n) % alphaLen + 'a';
        str[i] = ch;
    }
}

int main() {
    char str[] = "10A za shumni";
    printf("%s\n", str);
    cipherN(str, 4);
    printf("%s\n", str);
    decipherN(str, 4);
    printf("%s\n", str);
    

    return 0;
}