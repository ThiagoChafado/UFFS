#include <stdio.h> 
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    int altura;
    struct Nodo *esq, *dir;
} Nodo;

Nodo* criaNodo(int valor){
    Nodo *aux = (Nodo *) malloc(sizeof(Nodo));
    aux->valor = valor;
    aux->altura = 1;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
}

int alturaDoNo(Nodo *no){
    if(no)
        return no->altura;
    else    
        return 0;    
}

int fatorDeBalanceamento(Nodo *no){
    if(no)
        return (alturaDoNo(no->esq) - alturaDoNo(no->dir));
    else
        return 0;
}

int maior(int a, int b){
    return (a > b) ? a : b;
}

Nodo* rotacaoEsquerda(Nodo *pai){
    Nodo *filhoD, *netoE;
    filhoD = pai->dir;
    netoE = filhoD->esq;
    // rotacao:
    filhoD->esq = pai;
    pai->dir = netoE;
    // recalcula a altura dos nodos que foram movimentados
    pai->altura = maior(alturaDoNo(pai->esq), alturaDoNo(pai->dir)) + 1;
    filhoD->altura = maior(alturaDoNo(filhoD->esq), alturaDoNo(filhoD->dir)) + 1;
    return filhoD;
}

Nodo* rotacaoDireita(Nodo *pai){
    Nodo *filhoE, *netoD;
    filhoE = pai->esq;
    netoD = filhoE->dir;
    //rotacao:
    filhoE->dir = pai;
    pai->esq = netoD;
    // recalcula a altura:
    pai->altura = maior(alturaDoNo(pai->esq), alturaDoNo(pai->dir)) + 1;
    filhoE->altura = maior(alturaDoNo(filhoE->esq), alturaDoNo(filhoE->dir)) + 1;
    return filhoE;
}

Nodo* rotacaoEsquerdaDireita(Nodo *pai){
    pai->esq = rotacaoEsquerda(pai->esq);
    return rotacaoDireita(pai);
}

Nodo* rotacaoDireitaEsquerda(Nodo *pai){
    pai->dir = rotacaoDireita(pai->dir);
    return rotacaoEsquerda(pai);
}

Nodo* balancear(Nodo *raiz){
    int fb = fatorDeBalanceamento(raiz);

    // rotacao a esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->dir) <= 0)
        raiz = rotacaoEsquerda(raiz);

    // rotacao a direita
    else if(fb > 1 && fatorDeBalanceamento(raiz->esq) >=0)
        raiz = rotacaoDireita(raiz);

    //rotacao dupla a esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->esq) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);

    //rotacao dupla a direita
    else if (fb < -1 && fatorDeBalanceamento(raiz->dir) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);

    return raiz;               
}

Nodo* adicionarNodo(Nodo *raiz, int valor) {
    if (raiz == NULL) {
        return criaNodo(valor);
    }

    if (raiz->valor >= valor) {
        raiz->esq = adicionarNodo(raiz->esq, valor);    
    }
    else {
        raiz->dir =  adicionarNodo(raiz->dir, valor);
    }
    //recalculando a altura:
    raiz->altura = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
   raiz = balancear(raiz);
    return raiz;
}

void preOrder(Nodo *raiz) {
    if (raiz != NULL) {  
        printf(" %d |", raiz->valor);
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }  
}

// Programa principal
int main() {
     Nodo *arv = NULL;
     arv = adicionarNodo(arv, 43);
     arv = adicionarNodo(arv, 82);
     arv = adicionarNodo(arv, 99); 
     arv = adicionarNodo(arv, 14);
     arv = adicionarNodo(arv, 21);
     arv = adicionarNodo(arv, 30);   
     arv = adicionarNodo(arv, 3);
     arv = adicionarNodo(arv, 51);
     arv = adicionarNodo(arv, 9);
     arv = adicionarNodo(arv, 27); 
    
     preOrder(arv);

     return 0;
}
