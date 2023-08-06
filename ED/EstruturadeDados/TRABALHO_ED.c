
//THIAGO CHAFADO ALMEIDA E JOAO EDUARDO FERRARI
//OBS:ONDE TIVER A FUNCAO FFLUSH(...),E PARA LIMPAR O BUFFER DO TECLADO,POIS ESTAVA DANDO PROBLEMAS NOS SCANS
//EM LINUX PODE TER ALGUM PROBLEMA COM ESSA FUNCAO,POR ISSO VAMOS COLOCAR JUNTO O CODIGO JA COMPILADO
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

// Struct que representa um item de uma lista de compras armazenada em uma arvore binaria de busca
struct item {
	char produto[50];
	int quantidade;
    struct item  *esquerdo; 
	struct item  *direito;
};
typedef struct item Item;

struct lista{//struct da lista
     char produto[50];
     int quantidade;
     struct lista *proximo;
};
typedef struct lista Lista;

// Apresenta o primeiro menu da aplicação e retorna a opção selecionada
int menu1()
{
     int op = 0;
     printf("\nMenu principal\n");
     
     printf("Digite 1 para acessar a lista A\n");
     printf("Digite 2 para acessar a lista B\n");
     printf("Digite 3 realizar a interseccao das arvores A e B\n");
     printf("Digite %d para sair do programa",EXIT);
     printf("\nDigite a opcao: ");
     fflush(stdin);
     scanf("%d",&op);
     fflush(stdin);
     return op;
}

// Apresenta o segundo menu da aplicação e retorna a opção selecionada
int menu2()
{
    int op = 0;
    printf("Submenu - Gerenciar lista de compras\n");
    printf("Digite 1 para inserir um item\n");
    printf("Digite 2 para consultar um item\n");
    printf("Digite 3 para atualizar a quantidade de um item\n");
    printf("Digite 4 para listar os itens\n");
    printf("Digite 5 para deletar um item\n");

    printf("Digite %d para retornar para o menu principal",EXIT);
    printf("\nDigite a opcao: ");
    fflush(stdin);
    scanf("%d",&op); 
    fflush(stdin);
    return op;
}

//função para crirar nodo,é chamada na funcao de inserir
Item *criaNodo(char produto[50], int quantidade){
     Item *novo = malloc(sizeof(Item));

     strcpy(novo->produto,produto);
     novo->quantidade = quantidade;
     novo->esquerdo = NULL;
     novo->direito = NULL;
     return novo;
}

Item *inserirNodo(Item *raiz, char produto[50], int quantidade){ //insere nodo na arvore
     if (raiz == NULL){
          printf("Produto adicionado à lista\n");
          return criaNodo(produto, quantidade);
          

     }else{
          int retorno = strcmp(produto, raiz->produto);//ver segunda comparação
          if(retorno>0){//primeira string é maior(vem depois)
               raiz->direito = inserirNodo(raiz->direito, produto, quantidade);
          }else if (retorno==0){//strings são iguais
               raiz->quantidade = raiz->quantidade + quantidade;
          }else{ //segunda string é maior (vem depois)
               raiz->esquerdo = inserirNodo(raiz->esquerdo, produto, quantidade);
          }
     }//caso exista na arvore,so atualiza a quantidade 
     return raiz;
}

void consultaNodo(Item *raiz, char produto[50]){//ve se ta na arvore
     Item *atual = malloc(sizeof(Item));
     if (raiz == NULL){
          printf("PRODUTO NAO ESTA NA LISTA\n");
          return;
     }
     atual = raiz;
     while (atual != NULL){
          int retorno = strcmp(produto,atual->produto);
               if (retorno == 0){ //strings são iguais //valor encontrado
                    printf("PRODUTO %s ESTA NA LISTA\n", atual->produto);
                    printf("QUANTIDADE: %d\n", atual->quantidade);
                    return;
               }
               else if (retorno > 0){ // a segunda é maior (vem depois)
                    atual = atual->direito;
               }
               else{// retorno > 0 // a primeira é maior (vem depois)
                    atual = atual->esquerdo;
               }  
     }
     printf("PRODUTO NAO ESTA NA LISTA\n");
     return;
     }

// Permite a atualização da quantidade de um produto (caso exista) na lista de compras
void atualizaNodo(Item *raiz,char produto[50])
{
     Item *atual = malloc(sizeof(Item));
     if (raiz == NULL){
          printf("PRODUTO NAO ESTA NA LISTA\n");
          return;
     }
     atual = raiz;
     while (atual != NULL){
          int retorno = strcmp(produto,atual->produto);
               if (retorno == 0){ //strings são iguais //valor encontrado
                    printf("PRODUTO %s ESTA NA LISTA\n", atual->produto);
                    int novo;
                    fflush(stdin);//limpando buffer do teclado
                    printf("Digite a nova quantidade do produto");
                    scanf("%d",&novo);
                    fflush(stdin);//limpando buffer do teclado
                    atual->quantidade = novo;
                    printf("PRODUTO ATUALIZADO!\n");
                    return;
               }
               else if (retorno > 0){ // a segunda é maior (vem depois)
                    atual = atual->direito;
               }
               else{// retorno > 0 // a primeira é maior (vem depois)
                    atual = atual->esquerdo;
               }       
     }
     return;
     }

// Listar todos os itens da lista de compras em ordem alfabética;
void listarNodos(Item *raiz)
{
     if (raiz == NULL){
          return;
     }else{
          listarNodos(raiz->esquerdo);
          printf("Nome: %s\nQuantidade %d\n\n",raiz->produto,raiz->quantidade);
          listarNodos(raiz->direito);
     }  
}

// Permite excluir um item de uma lista de compras
Item* deletarNodo(Item *raiz,char chave[]){
     if(raiz == NULL){ //Produto nao cadastrado
          printf("\nValor nao encontrado");
          return NULL;}

     int retorno;
     retorno = strcmp(raiz->produto, chave);
     
     if(retorno == 0){ //encontrou
          if(raiz->esquerdo == NULL && raiz->direito == NULL){//deleta nodo sem filho
               free(raiz);
               printf("PRODUTO DELETADO");
               return NULL;}

          else if(raiz->esquerdo != NULL && raiz->direito != NULL){//deleta nodo com 2 filhos
               
               Item *aux = raiz->esquerdo;
               while(aux->direito != NULL){
                    aux = aux->direito;}  
               raiz->quantidade = aux->quantidade;
               strcpy(raiz->produto, aux->produto);
               strcpy(aux->produto, chave);

               raiz->esquerdo = deletarNodo(raiz->esquerdo, chave);
               return raiz;}
          else{//deleta nodo com 1 filho
               Item *aux; 
               if(raiz->esquerdo != NULL){
                    aux = raiz->esquerdo;} 
               else{
                    aux = raiz->direito;}

               free(raiz);
               printf("PRODUTO DELETADO");
               return aux;
          }}
     
     //recursao
     else if(retorno > 0){
          raiz->esquerdo = deletarNodo(raiz->esquerdo, chave);} 
     else{
          raiz->direito = deletarNodo(raiz->direito, chave);}

     return raiz;
}
Lista* adicionaLista(Item *raiz, Lista *primeiro)//funcao para adicionar as duas arvores em cada lista
{
     Lista *aux;
     if(raiz == NULL){
          return primeiro;
     }else{
          aux = malloc(sizeof(Lista));
          strcpy(aux->produto,raiz->produto);
          aux->quantidade = raiz->quantidade;
          aux->proximo = NULL;
          if(primeiro != NULL){
               aux->proximo = primeiro;
               primeiro = aux;
          }else{
               primeiro = aux;
          }
          primeiro = adicionaLista(raiz->esquerdo,primeiro);
          primeiro = adicionaLista(raiz->direito,primeiro);
     }
}

Lista* intersecao(Lista *primeiro1, Lista *primeiro2, Lista *primeiro3){//adiciona os itens iguais em uma outra lista
     //cada ponteiro primeiro equivale ao primeiro de cada lista
     //primeiro 1 = primeiro lista1
     //primeiro 2 = primeiro lista2
     //primeiro 3 = primeiro lista intersecao
     Lista *aux1;
     Lista *aux2;
     Lista *novo;
     for(aux1=primeiro1;aux1 !=NULL;aux1 = aux1->proximo){//compara cada nodo da arvore A com da B
          for(aux2=primeiro2;aux2 !=NULL;aux2 = aux2->proximo){
               int retorno = strcmp(aux1->produto,aux2->produto);
               if (retorno == 0){//se iguais,adiciona na lista
                    novo = malloc(sizeof(Lista));
                    strcpy(novo->produto,aux1->produto);
                    novo->quantidade = aux1->quantidade;
                    novo->proximo = NULL;
                    if(primeiro3 !=NULL){
                         novo->proximo = primeiro3;
                         primeiro3 = novo;

                    }else{
                         primeiro3 = novo;
                    }
               
               }
          }
     }return primeiro3;
}

void imprimeLista(Lista *primeiro){//funcao de imprimir lista simples
     Lista *aux;
     for (aux = primeiro;aux != NULL;aux=aux->proximo){
                   printf("Produto = %s\n",aux->produto);
                    }
}

Lista* destroiLista(Lista *primeiro){
    Lista *aux;
    while (primeiro !=NULL){

      aux = primeiro;
      primeiro = primeiro->proximo;//incremento
      free(aux);
      
    }return NULL;
}

// Programa principal
int main()
{
     Lista *primeiro1 = NULL;
     Lista *primeiro2 = NULL;
     Lista *primeiro3 = NULL;
    int opcao1 = 0, opcao2 = 0;
    Item *raizA = NULL;
    Item *raizB = NULL;
    Item *aux;
    Item *aux2;
    Lista *aux3;
    char chave[50];
    char produto[50];
    int quantidade;
    while (opcao1 != EXIT)
    {
          opcao1 = menu1();
          switch(opcao1)
          {
               case 1 : // gerenciar lista de compras A
                    opcao2=0;
                    while(opcao2 != EXIT){
                         printf("\n\n** Lista de Compras A **\n\n");
                         opcao2 = menu2();
                         switch(opcao2){ // operacoes sobre a arvore A
                              case 1 : 
                                   fflush(stdin);//limpando buffer do teclado
                                   printf("Digite o nome do produto:");
                                   fgets(produto,50,stdin);
                                   printf("Digite a quantidade: ");
                                   scanf("%d",&quantidade);
                                   fflush(stdin);
                                   raizA = inserirNodo(raizA,produto,quantidade);
                                   break;
                              case 2 : 
                                   fflush(stdin);
                                   printf("Digite o nome do produto que deseja buscar: ");
                                   fgets(produto,50,stdin);
                                   consultaNodo(raizA,produto);
                                   break;
                              case 3 : 
                                   printf("Digite o nome do produto:");
                                   fgets(produto,50,stdin);
                                   atualizaNodo(raizA,produto);
                                   break;
                              case 4 : 
                                   printf("Listando todos os nodos: \n");
                                   listarNodos(raizA);
                                   break;
                              case 5 : 
                              printf("Digite o nome do produto que deseja excluir: \n");
                              fflush(stdin);
                              fgets(chave,50,stdin);
                              raizA = deletarNodo(raizA,chave);
                              break;
                         }    
                    }
                    break;
                    
               case 2 : // gerenciar lista de compras B
                    opcao2=0;
                while(opcao2 != EXIT){
                    
                         printf("\n\n** Lista de Compras B **\n\n");
                         opcao2 = menu2();
                         switch(opcao2){ // operacoes sobre a arvore B
                              case 1 : 
                                   fflush(stdin);//limpando buffer do teclado
                                   printf("Digite o nome do produto:");
                                   fgets(produto,50,stdin);
                                   printf("Digite a quantidade: ");
                                   scanf("%d",&quantidade);
                                   fflush(stdin);
                                   
                                   raizB = inserirNodo(raizB,produto,quantidade);
                                   break;
                              case 2 : 
                                   fflush(stdin);
                                   printf("Digite o nome do produto que deseja buscar: ");
                                   fgets(produto,50,stdin);
                                   fflush(stdin);
                                   consultaNodo(raizB,produto);
                                   break;
                              case 3 : 
                                   printf("Digite o nome do produto:");
                                   fgets(produto,50,stdin);
                                   atualizaNodo(raizB,produto);
                                   break;
                              case 4 : 
                                   printf("Listando todos os nodos: \n");
                                   listarNodos(raizB);
                                   break;
                              case 5 : 
                              printf("Digite o nome do produto que deseja excluir: \n");
                              fflush(stdin);
                              fgets(chave,50,stdin);
                              deletarNodo(raizB,chave);
                              break;
                         }  
                    }
                    break;

               case 3 : // Visualizar itens duplicados
               opcao2=0;
               printf("Itens duplicados: \n");
               primeiro1 = adicionaLista(raizA,primeiro1);
               primeiro2 = adicionaLista(raizB,primeiro2);
               primeiro3 = intersecao(primeiro1,primeiro2,primeiro3);
               imprimeLista(primeiro3);
               primeiro1 = destroiLista(primeiro1);
               primeiro2 = destroiLista(primeiro2);
               primeiro3 = destroiLista(primeiro3);
          }
    }
    return 0;
}
