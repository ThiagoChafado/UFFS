#include <stdio.h>
#include <string.h>

int main(){
    int i=0;
    int contador=0;
    char string[20];
    
    scanf("%s",string);
    while (string[i] != '\0'){
        i++;
        contador++;
    }
    printf("O tamanho da string e = %d",contador);


    return 0;
}