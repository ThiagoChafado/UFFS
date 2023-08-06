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
          }
    }
    return 0;
}
