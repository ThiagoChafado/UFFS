#include <stdio.h>
void binario(int x){
    if (x/2 ==0){
        printf("%d",x%2);
    } else {
        binario(x/2);
        printf("%d",x%2);
    }
}
int main(){
    int x;

    scanf("%d",&x);
    binario(x);
    return 0;
}