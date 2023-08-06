#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura do nodo (item de uma lista de compras)
struct item {
  char nome[31];
  int quantidade;
  struct item *anterior, *proximo;
}; 
typedef struct item Item;

//estrutura da lista
struct lista {
  Item *primeiro;
  Item *ultimo;
};
typedef struct lista Lista;
  
void inicializaLista(Lista *lista){
  // inicializa a cabeca e cauda da lista como NULL  
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}

Item* encontraPosicao(Lista *lista, char *nomeNovo){
    for (Item *aux = lista->primeiro;aux!=NULL;aux = aux->proximo){
        if (strcmp(nomeNovo,aux->nome)<=0)//encontrou posicao de insercao
        return aux;
    }return NULL;
}

void insereNodo(Lista *lista, char *nome, int quantidade){
    //preparar novo nodo
    Item *novo = malloc(sizeof(Item));
    novo->quantidade = quantidade;
    strcpy(novo->nome,nome);
    novo->proximo = NULL;
    novo->anterior = NULL;
    if (lista->primeiro == NULL){//lista vazia
        lista->primeiro = novo;
        lista->ultimo = novo;
    }
    else{//lista nao vazia
        //encontrar local de insercao
        Item *elemento = encontraPosicao(lista,nome);
        if (elemento != NULL){
            if (elemento == lista->primeiro){//insere no inicio
                novo->proximo = elemento;
                lista->primeiro->anterior = novo;
                lista->primeiro = novo;

            }else{//insere no meio
                novo->proximo = elemento;
                novo->anterior = elemento->anterior;
                elemento->anterior->proximo = novo;
                elemento->anterior = novo;
            }
        }else{//retornou NULL,insere no final
            novo->anterior = lista->ultimo;
            lista->ultimo->proximo = novo;
            lista->ultimo = novo;
        }
    }

}

void imprimeCrescente(Lista *lista){
  if(lista->primeiro == NULL)
    printf("\n\nLista vazia\n");
  else{
    printf("\n\nLista de compras (ordem crescente):\n");
    for (Item *aux = lista->primeiro; aux != NULL; aux = aux->proximo){
      printf("%s - Quantidade: %d\n", aux->nome, aux->quantidade);
    }
  }
}

void imprimeDecrescente(Lista *lista){
  if(lista->primeiro == NULL)
    printf("\n\nLista vazia\n");
  else{
    printf("\n\nLista de compras (ordem decrescente):\n");
    for (Item *aux = lista->ultimo; aux != NULL; aux = aux->anterior){
      printf("%s - Quantidade: %d\n", aux->nome, aux->quantidade);
    }
  }
}

void destroiLista(Lista *lista){
  Item *aux; 
  while (lista->primeiro != NULL){
    aux = lista->primeiro;
    lista->primeiro = lista->primeiro->proximo;
    free(aux);
  }
}


int main(){
  Lista lista;
  inicializaLista(&lista);
  insereNodo(&lista, "Detergente", 2);
  insereNodo(&lista, "Laranja", 10);
  insereNodo(&lista, "Arroz", 1);
  insereNodo(&lista, "Pao", 5);
  insereNodo(&lista, "Manteiga", 1);
  insereNodo(&lista, "Abacaxi", 3);
  insereNodo(&lista, "Shampoo", 1);
  insereNodo(&lista, "Xarope de milho", 2);
  insereNodo(&lista, "Amendoim torrado", 2);
  imprimeCrescente(&lista);
  imprimeDecrescente(&lista);
  destroiLista(&lista);
  return 0;
}