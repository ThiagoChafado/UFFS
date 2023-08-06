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
