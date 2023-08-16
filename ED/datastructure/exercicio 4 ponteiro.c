#include <stdio.h>
#include <stdlib.h>
int main(){
    int *a=malloc(sizeof(int));
    float *b=malloc(sizeof(float));
    char *c=malloc(sizeof(char));
    if (a == NULL || b==NULL || c ==NULL){
        printf("MEMORIA INSUFICIENTE");
        exit(1);
    }
    a=2;
    b=3.5;
    c='I';
    int *p;
    float *p2;
    char *p3;
    p = &a;
    p2 = &b;
    p3 = &c;
    printf("Esses sao os valores de p antes: %d, %.2f, %c\n",*p,*p2,*p3);
    *p = 6;
    *p2 = 7.5;
    *p3 = 'J';
    printf("Os novos valores sao: %d, %.2f, %c",*p,*p2,*p3);
    
    return 0;


}