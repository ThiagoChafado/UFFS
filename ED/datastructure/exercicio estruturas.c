#include <stdio.h>
#include <string.h>
#define N 5
struct aluno{
        int matricula;
        char nome[25];
        float n1;
        float n2;
        float n3;
        float media;
};


int main(){
    int i;
    struct aluno turma[N];
    float max=0;
    float maxmedia = 0;
    char alunomaiormedia[25];
    char alunomenormedia[25];
    float minmedia = 0;
    char alunomaiornota[25];
    for (i=0;i<N;i++){
        printf("Digite a matricula do aluno: ");
        scanf("%d",&turma[i].matricula);
        printf("Digite o nome do aluno:");
        scanf("%s",&turma[i].nome);
        printf("Digite a nota da primeira prova: ");
        scanf("%f",&turma[i].n1);
        printf("Digite a nota da segunda prova: ");
        scanf("%f",&turma[i].n2);
        printf("Digite a nota da terceira prova: ");
        scanf("%f",&turma[i].n3);
        if (turma[i].n1 > max){//maior nota
            max = turma[i].n1;
            strcpy(alunomaiornota,turma[i].nome);
        }
        //media
        turma[i].media = (turma[i].n1 + turma[i].n2 + turma[i].n3) /3;
        if (turma[i].media > maxmedia){
            maxmedia = turma[i].media;
            strcpy(alunomaiormedia,turma[i].nome);
        }else if (turma[i].media > minmedia){
            minmedia = turma[i].media;
            strcpy(alunomenormedia,turma[i].nome);
        }
        if (turma[i].media >=6){
            printf("APROVADO\n");
        }else {
            printf("REPROVADO\n");
        }
    }
    printf("A maior nota da primeira prova foi do aluno %s,que tirou %.2f\n",alunomaiornota,max);
    printf("A maior media geral foi do aluno %s,que tirou %.2f\n",alunomaiormedia,maxmedia);
    printf("A menor media geral foi do aluno %s,que tirou %.2f\n",alunomenormedia,minmedia);

      


    return 0;
}