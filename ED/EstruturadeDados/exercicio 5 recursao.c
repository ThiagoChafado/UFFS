#include <stdio.h>
#include <string.h>
void inverte(char p[],int e,int d){
    char aux;
    if (e>=d)
    return ;
    else{
        aux = p[e];
        p[e] = p[d];
        p[d] = aux;
        inverte(p,e+1,d-1);
    }

}

int main(){
    char palavra[0] = "computacao";
    inverte(palavra,0,strlen(palavra)-1);
    printf("%s",palavra);
    return 0;
}