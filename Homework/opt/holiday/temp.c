#include <stdio.h>
#define get_name(var)  #var
  
int main(){
    int myVar;
    printf("%s\n", get_name(myVar));
    return 0;
} 