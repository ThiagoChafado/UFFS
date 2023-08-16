#include <stdio.h>
#include <stdlib.h>

struct elempilha{
    char caracter;
    struct elemPilha *proximo;
};
typedef struct elempilha elemPilha;

struct pilha{
    elemPilha *topo;
};
typedef struct pilha Pilha;

void insere(Pilha *pilha, char caracter){
    elemPilha *aux;
    aux = malloc(sizeof(elemPilha));
    aux->caracter = caracter;
    aux->proximo = pilha->topo;
    pilha->topo = aux;

}

int vazia(Pilha *pilha){
    return (pilha->topo == NULL);
}

void removePilha(Pilha *pilha,char *caracter){
    elemPilha *aux;
    *caracter = pilha->topo->caracter;
    aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(aux);
}

void inicializaPilha(Pilha *pilha){
    pilha->topo = NULL;
}

int main(){
    Pilha pilha;
    int verifica;
    inicializaPilha(&pilha);
    char caracter[20];
    printf("Digite os caracteres(Maximo 10): ");
    scanf("%s",caracter);
    for (int i=0;i<(sizeof(caracter));i++){
        if (caracter[i] == '(' || caracter[i] == '[' || caracter[i] == '{'){
            insere(&pilha, caracter[i]);
        }else{
            if (caracter[i] == ')' || caracter[i] == ']' || caracter[i] == '}'){
                removePilha(&pilha,carac);
                
            }
        }
    }
    
    verifica = vazia(&pilha);
    if (verifica == 1){
        printf("CORRETO");
    }else{
        printf("INCORRETO");
    }

    return 0;
}