#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definicoes:

#define SIZE 13

typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct {
    Elemento *tab[SIZE];
} TabelaHash;

// funcoes:

int calculaHash(int valor){
    return valor % SIZE;
}

void inicializaTabelaHash(TabelaHash *th) {
    for(int i = 0; i < SIZE; i++){
        th->tab[i] = NULL;
    }
}

void insereTabelaHash(TabelaHash *th, int valor) {
    Elemento *novo;
    Elemento *aux;
    novo = malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->proximo = NULL;
    int indice = (calculaHash(valor));
    if (th->tab[indice] == NULL){
        th->tab[indice] = novo;
    }
    else {
        aux = th->tab[indice];
        while(aux->proximo != NULL){//percorre lista
          aux = aux->proximo;
        }aux->proximo = novo;
    }

    
}

void busca(TabelaHash *th, int chave){
    Elemento *aux;
    int indice = calculaHash(chave);
    if (th->tab[indice] == NULL){
        printf("%d NAO ESTA NA TABELA\n",chave);
    }else{
        for(aux = th->tab[indice];aux!=NULL;aux = aux->proximo){
            if (aux->valor == chave){
                printf("%d ESTA NA TABELA\n",chave);
                return ;
            }


        }
    printf("%d NAO ESTA NA TABELA\n",chave);
}
}
void removeElemento(TabelaHash *th, int chave){
    Elemento *aux;
    Elemento *anterior;
    int indice = calculaHash(chave);
    if (th->tab[indice] == NULL){
        printf("%d NAO ESTA NA TABELA\n",chave);}
    else{
        for (aux = th->tab[indice];aux!=NULL;aux = aux->proximo){
            if (aux->valor == chave){
                if(th->tab[indice] == aux){
                    th->tab[indice] = aux->proximo;
                }else{
                    anterior->proximo = aux->proximo; 
                }
                free(aux);
                break;
                }
            anterior = aux;
        }
            
        }
        
}
void printa(TabelaHash *th){
    Elemento *aux;
   for (int i = 0;i<11;i++){
        if (th->tab[i] == NULL){
            printf("Indice %d esta VAZIO\n",i);
        }else{
            for(aux = th->tab[i];aux!=NULL;aux = aux->proximo){
                printf("Valores no indice %d : %d\n",i,aux->valor);
            }
        }
    }
}

int main(){
    TabelaHash th;
    inicializaTabelaHash(&th);
    printf("\n\nTabela vazia: \n");
    printa(&th);

    insereTabelaHash(&th, 7);
    insereTabelaHash(&th, 17);
    insereTabelaHash(&th, 36);
    insereTabelaHash(&th, 100);
    insereTabelaHash(&th, 106);
    insereTabelaHash(&th, 205);
    printf("\n\nTabela apos insercoes: \n");
    printa(&th);
    
    printf("\n\nBuscando elementos: \n");
    busca(&th, 14);
    busca(&th, 205);

    removeElemento(&th, 205);
    removeElemento(&th, 7);
    removeElemento(&th, 106);
    printf("\n\nTabela apos remocoes: \n");
    printa(&th);

    return 0;
}