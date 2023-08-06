#include <stdio.h>
#include <string.h>
int somatorio(int v[],int tam){
    if (tam ==0){
        return 0;
    }else{
    return v[tam-1]+somatorio(v,tam-1);}
}

int main(){
    int vet[5] = {0,5,6,52,12};
    printf("%d",somatorio(vet,5));
    return 0;
}