void consultaNodo(Item *raizA, char produto[50]){
     Item *atual = malloc(sizeof(Item));
     if (raizA == NULL){
          printf("PRODUTO NAO ESTA NA LISTA\n");
          return;
     }
     atual = raizA;
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
     printf("PRODUTO NAO ESTA NA LISTA\n", produto);
     return;
     }
