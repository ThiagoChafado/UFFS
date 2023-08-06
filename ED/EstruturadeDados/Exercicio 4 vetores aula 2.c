#include <stdio.h>
#include <string.h>
int main(){
    int i;
    char string[50];
   
    gets(string);
    int tam = strlen(string);
    for (i=tam;i>=0;i--){
        printf("%c",string[i]);
        
    }
    return 0;
}