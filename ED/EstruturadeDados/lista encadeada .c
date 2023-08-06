#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct funcionario{
    char nome[31];
    int id;
    float salario;
    struct funcionario *anterior, *proximo;
};
typedef struct funcionario Funcionario;

struct lista{//criando lista com primeiro e ultimo
    Funcionario *primeiro;
    Funcionario *ultimo;
};
typedef struct lista Lista;

//funcao pra inicializar NULL
void inicializaLista(Lista *lista){
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}
void insereInicio(Lista *lista,int id,char nome[],float salario){
    Funcionario *aux;//ponteiro
    aux = malloc(sizeof(Funcionario));
    aux->id = id;
    strcpy(aux->nome,nome);
    aux->salario = salario;
    aux->proximo = NULL;
    aux->anterior = NULL;
    //testar se ta vazio
    if(lista->primeiro == NULL){
        lista->primeiro = aux;//vai ser o primeiro e o ultimo
        lista->ultimo = aux;

    }else{
        aux->proximo = lista->primeiro;
        lista->primeiro->anterior = aux;
        lista->primeiro = aux;
    }
    return lista;
    
}
void imprimeLista(Lista *lista){
    Funcionario *aux;//vai ser contador
    if (lista->primeiro == NULL){
        printf("LISTA VAZIA!\n");
    }else{
    for(aux=lista->primeiro;aux!=NULL;aux=aux->proximo){
        printf("Nome: %s\n Id: %d\n Salario: %f\n",aux->nome,aux->id,aux->salario);
    }
}
}
void insereFim(Lista *lista,int id,char *nome[],float salario){
    Funcionario *aux;
    aux = malloc(sizeof(Funcionario));
    aux->id = id;
    strcpy(aux->nome,nome);
    aux->salario = salario;
    aux->proximo = NULL;
    aux->anterior = NULL;
    aux->anterior = lista->ultimo;
    lista->ultimo->proximo = aux;
    lista->ultimo = aux;
}

int main(){
    Lista lista;
    inicializaLista(&lista);
    insereInicio(&lista,35,"Pedro",2500);
    printf("\n");
    insereInicio(&lista,35,"Jonas",2500);
    imprimeLista(&lista);
    insereFim(&lista,35,'FIM',3000);
    imprimeLista(&lista);
    return 0;
}