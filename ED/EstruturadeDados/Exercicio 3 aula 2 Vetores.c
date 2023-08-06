#include <stdio.h>
int main(){
    

    int i;
    int vetor[8];
    
    for (i=0;i<8;i++){
        scanf("%d",&vetor[i]);
    }
    int max = vetor[0];
    int min = vetor[0];
    for (i=0;i<8;i++){
        if (vetor[i]>max){
            max = vetor[i];
            
        } else if (vetor[i]<min){
            min = vetor[i];

        }
    }
    printf("Maior = %d\n",max);
    printf("Menor = %d",min);
    return 0;

}