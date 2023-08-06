#include <stdio.h>
#include <string.h>

//NOME DO ALUNO: THIAGO CHAFADO ALMEIDA
//MATRICULA: 2211100023

typedef int Id;

typedef struct elemFila {
    Id id;
    char nome[20];
    struct elemFila *proximo;
} ElemFila;

typedef struct {
    ElemFila *primeiro;
    ElemFila *ultimo;
} Fila;


void insereFila(Fila *fila, Id id,char nome[20]) {//inserindo novo aviao a fila de decolagem
    ElemFila *aux;
    aux = malloc(sizeof(ElemFila));
    aux->id = id;
    strcpy(aux->nome,nome);
    aux->proximo = NULL;
    if (fila->primeiro == NULL) { // Se a fila esta vazia
        fila->primeiro = aux;
        fila->ultimo = aux;
    }
    else { // Se a fila nao esta vazia
        fila->ultimo->proximo = aux;
        fila->ultimo = aux;
    }
    printf("O aviao de id: %d e nome: %s foi inserido\n",aux->id,aux->nome);
}

void removeFila(Fila *fila){
    ElemFila *aux;
    aux = fila->primeiro;
    if (fila->primeiro == fila->ultimo) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    else {
        fila->primeiro = fila->primeiro->proximo;
    }
    printf("O aviao de id: %d e nome: %s decolou!\n",aux->id,aux->nome);
    free(aux);
    
}

void informacoes(Fila *fila){
    if (fila->primeiro == NULL){//fila vazia
        printf("Fila vazia\n");
        return 0;
    }
    printf("Informacoes do primeiro aviao da fila:\n");
    printf("Nome do aviao: %s\n",fila->primeiro->nome);
    printf("Id do aviao: %d\n",fila->primeiro->id);
}

void inicializaFila(Fila *fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int qtdItensFila(Fila *fila){//numero de avioes na fila de decolagem   
    int contador = 0;
    ElemFila *aux;//contador
    if (fila->primeiro == NULL){
        return contador;//fila vazia
    }
    for(aux = fila->primeiro;aux!= NULL;aux = aux->proximo){
        contador = contador +1;
    }
    return contador;
}

void listaraviao(Fila *fila){
    ElemFila *aux;
    printf("Avioes na fila:\n");
    for(aux=fila->primeiro;aux!=NULL;aux = aux->proximo){;
        printf("Nome: %s , Id: %d\n",aux->nome,aux->id);
    }
}
int main() {
    Fila fila;
    Id id;
    int nodos;
    inicializaFila(&fila);//alguns testes

    nodos = qtdItensFila(&fila);
    printf("Quantidade de avioes na fila de decolagem = %d\n",nodos);
    
    insereFila(&fila,20,"Boening");
    insereFila(&fila,19,"Apache");
   
    
    informacoes(&fila);
    removeFila(&fila);
    listaraviao(&fila);
    return 0;
}
