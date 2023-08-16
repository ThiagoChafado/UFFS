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
        
    
    int max=matriz[0][0];
    int posicaolinha=0;
    int posicaocoluna=0;
    
    
    for (linha=0;linha<4;linha++){
        for (coluna=0;coluna<4;coluna++){
            if (matriz[linha][coluna] > max){
                max = matriz[linha][coluna];
                posicaolinha = linha;
                posicaocoluna = coluna;

            }
        }
            
    }
    printf("Maior numero=%d\n",max);
    printf("Linha=%d\n",posicaolinha);
    printf("coluna=%d\n",posicaocoluna);
   


    return 0;

}