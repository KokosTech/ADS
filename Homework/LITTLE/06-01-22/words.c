#include <string.h>

void regex(char *string){
    for(int i = 0; i < strlen(string); ++i){
        if(string[i] == '\n' || string[i] == '\t' || string[i] == '\b'  
        || string[i] == '\r' || string[i] == '\a' || string[i] == '\'' 
        || string[i] == '\"' || string[i] == '\?' || string[i] == '\\' 
        || string[i] == '\f' || string[i] == '\v' || string[i] == '\0' 
        || string[i] == ' ')
    }
}