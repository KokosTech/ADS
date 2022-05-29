#include <stdio.h>
#include <string.h>
#include <ctype.h>

char charCipherN(char c, unsigned short n) {
	size_t alphaLen = 'z' - 'a' + 1;
	
	return isalpha(c) ? (c - 'a' + n) % alphaLen + 'a' : c;	
}

char charDecipherN(char c, unsigned short n) {
	size_t alphaLen = 'z' - 'a' + 1;
	
	return isalpha(c) ? (c - 'a' - n + alphaLen) % alphaLen + 'a' : c;	
}

void cipherN(char *str, unsigned short n) {
	size_t len = strlen(str);
	for (size_t i = 0; i < len; ++i) {
		str[i] = charCipherN(str[i], n);
	}
}

void cipher(char *str) {
	cipherN(str, 1);
}

void decipherN(char *str, unsigned short n) {
	size_t len = strlen(str);
	size_t alphaLen = 'z' - 'a' + 1;
	for (size_t i = 0; i < len; ++i) {
		str[i] = charDecipherN(str[i], n);
	}
}

size_t stringSum(char *str) {
    size_t len = strlen(str);
    size_t sum = 0;
    for (size_t i = 0; i < len; ++i) {
        sum += str[i];
    }
    return sum;
}

void CBC(char *str, char *key, char **vector) {
    size_t len = strlen(str);
    size_t vectorLen = strlen(vector);

    for(size_t i = 0; i < len; ++i) {
        str[i] ^= *vector[i % vectorLen];
    }

    cipherN(str, stringSum(key));
    free(vector);
    vector = NULL;
    vector = strdup(str);
}

int main() {

	char str[] = "deseti a sa shumni";
	printf("%s\n", str);	
       	cipherN(str, 4);
	printf("%s\n", str);	
       	decipherN(str, 4);
	printf("%s\n", str);
	printf("%d", -3 % 26);	
	return 0;
}

