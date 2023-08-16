#include <stdio.h>

int potencia(int x,int y){
    if (x==0){
        return 1;
    }return y* potencia(x-1,y);
}

int main(){
    int x,y;
    int resultado;
    printf("Digite a base: ");
    scanf("%d",&y);
    printf("Digite o expoente: ");
    scanf("%d",&x);
    resultado = potencia(x,y);
    printf("resultado = %d",resultado);


    return 0;
}