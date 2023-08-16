#include <stdio.h>

struct produto{
    double preco;
    char nome[20];

};
int main(){
    struct produto item;
    struct produto *p=&item;
    printf("Digite o preco do produto: ");
    scanf("%lf",&p->preco);

    printf("Digite o nome do produto: ");
    fgets(p->nome);

    printf("Produto = %s ,preco =R$%.2f",p->nome,p->preco);
    return 0;
}