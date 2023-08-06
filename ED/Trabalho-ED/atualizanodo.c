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
