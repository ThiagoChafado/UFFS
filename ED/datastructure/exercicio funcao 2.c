#include <stdio.h>
int funcaoMaior(int a,int b){
    int max = a;
    if (b>max){
        max = b;
    }   
    return max;
}
int maiormaior(int a,int b,int c){
    int max;
    max =funcaoMaior(a,b);
    if (c>max ){
        max = c;
        
    }
    return max;
}
int main(){
    int a,b,c,resultado;
    printf("Digite o primeiro valor: ");
    scanf("%d",&a);
    printf("Digite o segundo valor: ");
    scanf("%d",&b);
    printf("Digite o terceiro valor: ");
    scanf("%d",&c);
    resultado = maiormaior(a,b,c);
    printf("O maior valor e: %d",resultado);



    return 0;
}