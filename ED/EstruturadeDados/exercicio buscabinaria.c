#include <stdio.h>

int buscaBinaria(int *vet,int inicio, int fim, int chave){
    int meio;
    if (inicio > fim){
        return -1;
    }
    meio = (inicio+fim)/2;

    if (vet[meio] == chave){
        return meio;
    }
    if (chave > vet[meio]){
        return buscaBinaria(vet, meio+1,fim,chave);
    } else{
        return buscaBinaria(vet,inicio,meio-1,chave);
    }
}

int main(){
    int vet[9] = {0,1,4,5,7,9,10,12,14,16};
    int achou = buscaBinaria(vet,0,9,5);
    if (achou != -1){
        printf("Encontrou");
    }else{
        printf("Nao encontrou");
    }

}