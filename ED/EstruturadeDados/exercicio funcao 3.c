#include <stdio.h>

float funcaocelsius(float a){
    float F;
    F = 9*(a/5)+32;
    return F; 
}
float funcaoF(float a){
    float C;
    C = 5*(a-32)/9;
    return C;
}
int main(){
    float a,resultado;
    int acao;
    printf("Digite a acao(1 de C -> F e 2 de F -> C): ");
    scanf("%d",&acao);
    if (acao ==1){
        printf("Digite o numero a converter: ");
        scanf("%f",&a);
        resultado = funcaocelsius(a);
        printf("Resultado= %.2f",resultado);        
    }else if (acao ==2){
        printf("Digite o numero a converter: ");
        scanf("%f",&a);
        resultado = funcaoF(a);
        printf("Resultado= %.2f",resultado);
    }
    return 0;
}