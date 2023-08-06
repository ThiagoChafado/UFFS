#include <stdio.h>
#include <stdlib.h>
void quadrado(int v[]){
    int i;
    int conta;
    for (i=0;i<5;i++){
        conta=0;
        conta=v[i]*v[i];
        printf("%d ",conta);
    }
}

int main(){
    int vet[5] ={1,2,3,7,5};
    int i;
    printf("VALORES ANTES: ");
    for (i=0;i<5;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
    printf("VALORES DEPOIS: ");
    quadrado(vet);

    return 0;
}