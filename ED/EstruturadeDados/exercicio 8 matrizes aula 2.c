#include <stdio.h>

int main(){

int matriz[5][5] ={{0,1,2,3,4},
            {5,6,7,8,9},
            {9,10,11,12,13},
            {14,15,16,17,18},
            {19,20,21,22,23}};
int i;
int j;
for (i=0;i<5;i++){
    for (j=0;j<5;j++){
        if (i == j){
            matriz[i][j] = 1;
        
        }else{
            matriz[i][j] = 0;

        }
    }
}    
for (i=0;i<5;i++){
    for (j=0;j<=5;j++){
        if (j <5){
            printf("%d",matriz[i][j]);
        } else{
            printf("\n");
        }
    }
}
    
    return 0;
}