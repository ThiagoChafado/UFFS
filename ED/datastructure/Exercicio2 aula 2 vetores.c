#include <stdio.h>
int main(){
    int i;
    int vetor[8];
    for (i=0;i<8;i++){
        scanf("%d",&vetor[i]);
    }
    
    for (i=0;i<8;i++){
        vetor[i] = vetor[i]*vetor[i];
        printf("%d\n",vetor[i]);
    }
    return 0;

}