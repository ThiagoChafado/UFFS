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
