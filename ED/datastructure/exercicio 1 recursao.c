#include <stdio.h>

int potencia(int x,int y){
    if (x==0){
        return 1;
    }return y* potencia(x-1);
}

int main(){
    int x,y;
    int resultado;
    scanf("%d",&x);
    scanf("%d",&y);
    resultado = potencia(x,y);
    printf("resultado = %d",resultado);


    return 0;
}