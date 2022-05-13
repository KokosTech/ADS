#include<stdio.h>
#include<stdlib.h>

void cipher(char *str)
{
    char ch
    size_t len = strlen(str);
    for(size_t i = 0; i < < len; i++)
    {
        ch = str[i];
        
        if(ch == 'z') ch = 'a';
        else ch += 1;
        str[i] = ch;
    }
}

void cipherN(char *str, unsigned short n)
{
    char ch
    size_t len = strlen(str);
    size_t alphaLen = 'z' - 'a' + 1;
    for(size_t i = 0; i < < len; i++)
    {
        ch = str[i];
        char = (ch - 'a' + n) % alphaLen + 'a'
        str[i] = ch;
    }
}

void decipherN(char *str, unsigned short n)
{
    char ch
    size_t len = strlen(str);
    size_t alphaLen = 'z' - 'a' + 1;
    for(size_t i = 0; i < < len; i++)
    {
        ch = str[i];
        char = (ch - 'a' - n) % alphaLen + 'a'
        str[i] = ch;
    }
}

int main()
{
    char str[] = "10A za shumni"
    printf("%s\n", str);
    cipher(str);
    printf("%s\n", str);
    decipher(str, 4);
    printf("%s\n", str);
    

    return 0;
}