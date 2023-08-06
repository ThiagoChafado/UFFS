#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} No;

No *constroiArvBin(int indRaiz, int dado[], int filhoEsq[], int filhoDir[]){
    if(indRaiz == -1){//caso base
        return NULL;
    }else{//chamadas recursivas
        No *novo = malloc(sizeof(No));
        novo->valor = dado[indRaiz];
        novo->esquerda = constroiArvBin(filhoEsq[indRaiz],dado,filhoEsq,filhoDir);
        novo->direita = constroiArvBin(filhoDir[indRaiz],dado,filhoEsq,filhoDir);
        return novo;
    }


}

void exibeValores(No *atual){
    if (atual == NULL){
        return;
    }
    else{
        
        exibeValores(atual->esquerda);
        printf("\nValor: %d", atual->valor);
        exibeValores(atual->direita);
    }
    



}
int main(){

    No *raiz;
    int dado[]={12,4,10,2,18,7,21,5};
    int fesq[]={5,7,3,-1,0,-1,-1,-1};
    int fdir[]={1,-1,6,-1,2,-1,-1,-1};

    raiz = constroiArvBin(4,dado, fesq, fdir);
    exibeValores(raiz);
    return 0;
}