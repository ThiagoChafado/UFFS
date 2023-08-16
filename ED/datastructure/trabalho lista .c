#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario{
  int id;
  char nome[31];
  double salario;
  struct funcionario *proximo;
}; 

typedef struct funcionario Funcionario;

Funcionario* insereNodoInicio(Funcionario *primeiro, int id, char nome[], double salario){
  Funcionario *aux;
    aux = malloc(sizeof(Funcionario));
    aux->id = id;
    strcpy(aux->nome,nome);
    aux->salario = salario;
    aux->proximo = NULL;
    if (primeiro != NULL){
        aux->proximo=primeiro;
        primeiro = aux;
    }
    return primeiro;
}

Funcionario* insereNodoFim(Funcionario *primeiro, int id, char nome[], double salario){
    Funcionario *aux,*novo;
    aux = malloc(sizeof(Funcionario));
    novo = malloc(sizeof(Funcionario));
    novo->id = id;
    strcpy(novo->nome,nome);
    novo->salario = salario;
    novo->proximo = NULL;
    if (primeiro->proximo == NULL){//verifica se é o primeiro
        primeiro->proximo = novo;
        return primeiro;
    }else{
      aux = primeiro;
        while(aux->proximo){//percorre lista
          aux = aux->proximo;
        }aux->proximo = novo;
        return primeiro; 
             
        }
    
}

Funcionario* deletaNodo(Funcionario *primeiro, int idDelete){
  Funcionario *aux, *anterior;  
  for (aux = primeiro; aux != NULL; aux = aux->proximo){
    if (aux->id == idDelete){
        if (aux == primeiro) {
       primeiro = primeiro->proximo; 
     } else {
       anterior->proximo = aux->proximo; 
     }
     free(aux); 
     break;
   }
   anterior = aux; 
 }
    return primeiro;
}

void imprimeLista(Funcionario *primeiro){
    Funcionario *aux;
    for (aux = primeiro;aux != NULL;aux=aux->proximo){
      printf("ID = %d,Nome = %s,Salario = %f\n",aux->id,aux->nome,aux->salario);

    }
}

void imprimeAoContrario(Funcionario *aux){
      if (aux!=NULL){
        imprimeAoContrario(aux->proximo);
        printf("ID = %d,Nome = %s,Salario = %f\n",aux->id,aux->nome,aux->salario);
        
      }
}

int contaNodos(Funcionario *primeiro){
  Funcionario *aux;
  int contador=0;
    for (aux = primeiro;aux != NULL;aux=aux->proximo){
      contador++;
    }return contador;
}

Funcionario* destroiLista(Funcionario *primeiro){
    Funcionario *aux;
    while (primeiro !=NULL){

      aux = primeiro;
      primeiro = primeiro->proximo;//incremento
      free(aux);//?????
      
    }return NULL;
}

int main(){
  Funcionario *primeiro = NULL;
  primeiro = malloc(sizeof(Funcionario));
  primeiro->id = 1;
  strcpy(primeiro->nome,"TESTE");
  primeiro->salario = 3000;
  primeiro->proximo =NULL;
  primeiro = insereNodoInicio(primeiro, 59, "Bill", 1500);
  primeiro = insereNodoInicio(primeiro, 60, "ROGER", 3000);
  primeiro = insereNodoFim(primeiro,5,"Fim",2500);
  primeiro = deletaNodo(primeiro, 1);
  imprimeLista(primeiro);
  printf("%d\n",contaNodos(primeiro));
  imprimeAoContrario(primeiro);
  
  primeiro = destroiLista(primeiro);
  imprimeLista(primeiro);
primeiro = insereNodoInicio(primeiro, 60, "ROGER", 3000);//testando novamente
  primeiro = insereNodoInicio(primeiro, 59, "Bill", 1500);
   primeiro = insereNodoFim(primeiro,5,"Fim",2500);
   imprimeLista(primeiro);
  return 0;
}



