Item* deletarNodo(Item *raiz,char chave[])
{
     if (raiz == NULL){
          printf("Valor nao encontrado!\n");
          return ;
     }
     else{
          int retorno = strcmp(raiz->produto,chave);
          if (retorno==0){//verifica se são iguais
               printf("entrou iguais\n");
               if(raiz->esquerdo == NULL && raiz->direito == NULL){//nenhum filho
                    printf("entrou nenhum filho");
                    free(raiz);
                    return NULL;
               }
          }else{
               printf("entrou\n");
               if(raiz->esquerdo != NULL && raiz->direito != NULL){//dois filhos
                    printf("entrou dois filhos\n");
                    Item *aux = raiz->esquerdo;
                    while(aux->direito!=NULL){//indo pela esquerda e achando o maior valor dessa subarvore
                         aux = aux->direito;
                    }strcpy(raiz->produto,aux->produto);
                    strcpy(aux->produto,chave);
                    raiz->esquerdo = deletarNodo(raiz->esquerdo,chave);
                    return raiz;

               }else{//um filho
                printf("entrou um filho\n");
                    Item *aux;
                    if(raiz->esquerdo != NULL){
                         aux = raiz->esquerdo;
                    }else{
                         aux = raiz->direito;
                    }free(raiz);
                    return aux;
               }
          }//caminhando pela arvore
               if (retorno>0){
                    raiz->esquerdo = deletarNodo(raiz->esquerdo, chave);
               }else{
                    if(retorno<0){
                         raiz->direito = deletarNodo(raiz->direito,chave);
                    }
               

          
          }return raiz;
     }
     return;
}
