#include <stdio.h>
int funcaoMaior(int a,int b){
    int max = a;
    if (b>max){
        max = b;

    }   
    return max;
}

int main(){
    int a,b,resultado;
    printf("Digite o primeiro valor: ");
    scanf("%d",&a);
    printf("Digite o segundo valor: ");
    scanf("%d",&b);
    resultado = funcaoMaior(a,b);
    printf("O maior valor e: %d",resultado);



    return 0;
}