#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Substitution cipher
// https://pages.mtu.edu/~shene/NSF-4/Tutorial/VIG/Vig-Base.html

char *encrypt(const char *str, const char *key);
char *decrypt(const char *str, const char *key);
char *encryptN(const char *str, const char *key, int n);
char *decryptN(const char *str, const char *key, int n);

int main() {
    char str[] = "BASED";
    printf("%s\n", str);
    char *encrypted = encrypt(str, "AYUSH");
    printf("%s\n", encrypted);
    printf("%s\n", decrypt(encrypted, "AYUSH"));

    char *encryptedN = encryptN(str, "KEY", 7);
    printf("%s\n", encryptedN);
    printf("%s\n", decryptN(encryptedN, "KEY", 7));
    return 0;
}

char *encrypt(const char *str, const char *key) {
    char *cipher = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    char ch;
    size_t alphaLen = 'Z' - 'A' + 1;

    for(size_t i = 0; i < strlen(str); i++) {
        ch = str[i];
        ch = (ch - 'A' + key[i % strlen(key)] - 'A') % alphaLen + 'A';
        cipher[i] = ch;
    }
    cipher[strlen(str)] = '\0';
    return cipher;
}

char *decrypt(const char *str, const char *key) {
    char *plain = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    char ch;
    size_t alphaLen = 'Z' - 'A' + 1;

    for(size_t i = 0; i < strlen(str); i++) {
        ch = str[i];
        ch = (ch - 'A' - (key[i % strlen(key)] -'A') + alphaLen) % alphaLen + 'A';
        plain[i] = ch;
    }
    plain[strlen(str)] = '\0';
    return plain;
}

char *encryptN(const char *str, const char *key, int n) {
    char *cipher = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    short ch;
    size_t alphaLen = 'Z' - 'A' + 1;

    printf("ascii A %d\n", 'A');

    for(size_t i = 0; i < strlen(str); i++) {
        ch = str[i];
        ch = (ch - 'A' + (key[i % strlen(key)] - 'A') * n);
        // printf("first %d %d\n", ch, key[i % strlen(key)] - 'A');
        ch %= alphaLen;
        ch += 'A';
        // printf("final %d\n", ch);
        cipher[i] = ch;
    }
    cipher[strlen(str)] = '\0';
    return cipher;
}

char *decryptN(const char *str, const char *key, int n) {
    char *plain = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    short ch;
    size_t alphaLen = 'Z' - 'A' + 1;

    for(size_t i = 0; i < strlen(str); i++) {
        ch = str[i];
        ch = abs((ch - 'A' - ((key[i % strlen(key)] -'A') * n))) % alphaLen;        
        if(ch) ch = 'Z' - abs(ch)%alphaLen + 1;
        else ch = 'A' + ch%alphaLen;

        plain[i] = ch;
    }
    plain[strlen(str)] = '\0';
    return plain;
}