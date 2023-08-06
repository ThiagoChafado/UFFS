//função para inserir
Item *criaNodo(char produto[50], int quantidade){
     Item *novo = malloc(sizeof(Item));

     strcpy(novo->produto,produto);
     novo->quantidade = quantidade;
     novo->esquerdo = NULL;
     novo->direito = NULL;

     return novo;
}

Item *inserirNodo(Item *raizA, char produto[50], int quantidade){ //mudei de void pra int
     if (raizA == NULL){
          return criaNodo(produto, quantidade);

     }else{
          int retorno = strcmp(produto, raizA->produto);//ver segunda comparação
          if(retorno>0){//primeira string é maior(vem depois)
               raizA->direito = inserirNodo(raizA->direito, produto, quantidade);
          }else if (retorno==0){//strings são iguais
               raizA->quantidade = raizA->quantidade + quantidade;
          }else{ //segunda string é maior (vem depois)
               raizA->esquerdo = inserirNodo(raizA->esquerdo, produto, quantidade);
          }
     }
     return raizA;
}
