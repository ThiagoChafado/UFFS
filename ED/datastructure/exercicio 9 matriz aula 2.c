#include <stdio.h>

int main (){
    int matriz[5][5];
    int i;
    int j;

    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            matriz[i][j] = i*j;

        }
      
    }
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf(" %d",matriz[i][j]);
        }
        printf("\n"); 
    }  
    return 0;

}