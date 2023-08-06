#include <stdio.h>

int main(){
    int matriz [4][4];
    int linha=0;
    int coluna=0;
    for (linha=0;linha<4;linha++){
        for (coluna=0;coluna<4;coluna++){
            printf("Digite posicao %d %d=",linha,coluna);
            scanf("%d",&matriz[linha][coluna]);

        }
    }

    for (linha=0;linha<4;linha++){
        for (coluna=0;coluna<4;coluna++){
            if (linha == coluna){
                printf("%d",matriz[linha][coluna]);
            } else {
                printf("  ");

            } 
            
        }printf("\n");
    }
   // printf("%d",matriz[0][0]);



    return 0;
}