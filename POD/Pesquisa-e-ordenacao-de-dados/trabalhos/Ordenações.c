/**
 * @file ordenacoes.c
 * @author Thiago Chafado Almeida
 * @version 0.3
 * @date 2023-03-30
 *
 * @copyright Copyright (c) 2023
 *
 *
 * @brief Arquivo template para trabalho de Pesquisa e Ordenação.
 *
 *      Cada estudante deve implementar as funções conforme as assinaturas
 * abaixo e realizar as impressões dos vetores após a ordenação. Desta forma,
 * o(a) estudante deve implementar o trecho de código para impressão dos vetores
 * ordenados dentro da função `main` conforme o exemplo do Bubble Sort abaixo.
 *
 * Se necessário, declare e implemente funções auxiliares para realizar as
 * ordenações.
 *
 * Importante:Não altere as assinaturas dos métodos de ordenação!
 *
 * Caso o vetor não possa ser ordenado por algum método, imprima uma mensagem de
 * aviso e o vetor original.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */
#include <stdio.h>
#include <stdlib.h>
void countingSortRadix(int *A,int size,int pos);
void criaHeap(int *A,int i,int size);
void quick(int *A,int inicio,int fim);
int particiona(int *A,int inicio,int fim);
void merge(int *A, int inicio, int fim);
void intercala(int *A, int inicio, int meio,int fim);
void copia(int *A, int *v, int size);
void bubbleSort(int *A, int size);
void selectionSort(int *A, int size);
void insertionSort(int *A, int size);
void mergeSort(int *A, int size);
void quickSort(int *A, int size);
void heapSort(int *A, int size);
void countingSort(int *A, int size);
void radixSort(int *A, int size);



int main(){

    int i;
    int vetor[] = {1, 22, 10, 38, 5, 7};
    int tamanhoVetor = (int)sizeof(vetor)/sizeof(int);

    printf("\nVetor original: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", vetor[i]);

    printf("\nVetor tamanho = %d\n", tamanhoVetor);

    // bubble sort
    int bubbleVec[tamanhoVetor];
    copia(vetor, bubbleVec, tamanhoVetor);
    bubbleSort(bubbleVec, tamanhoVetor);
    printf("\nBubble sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", bubbleVec[i]);
    printf("\n");

    // selection sort
    int selectionVec[tamanhoVetor];
    copia(vetor,selectionVec,tamanhoVetor);
    selectionSort(selectionVec,tamanhoVetor);
    printf("\nSelection sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", selectionVec[i]);
    printf("\n");
    //insertion sort
    int insertionVec[tamanhoVetor];
    copia(vetor,insertionVec,tamanhoVetor);
    insertionSort(insertionVec,tamanhoVetor);
    printf("\nInsertion sort: ");
    for (i = 0 ; i < tamanhoVetor ; i++)
        printf("%d ", insertionVec[i]);
    printf("\n");


    // merge sort
    int mergeVec[tamanhoVetor];
    copia(vetor,mergeVec,tamanhoVetor);
    mergeSort(mergeVec,tamanhoVetor);
    printf("\nMerge Sort: ");
    for(i = 0; i < tamanhoVetor; i++)
        printf("%d ",mergeVec[i]);
    printf("\n");

    // quick sort

    int quickVet[tamanhoVetor];
    copia(vetor,quickVet,tamanhoVetor);
    quickSort(quickVet,tamanhoVetor);
    printf("\nQuick Sort: ");
    for(i = 0; i < tamanhoVetor; i++)
        printf("%d ",quickVet[i]);
    printf("\n");

    // heap sort

    int heapVet[tamanhoVetor];
    copia(vetor,heapVet,tamanhoVetor);
    heapSort(heapVet,tamanhoVetor);
    printf("\nHeap Sort: ");
    for(i = 0; i < tamanhoVetor; i++)
        printf("%d ",heapVet[i]);
    printf("\n");

    // counting sort
    int flag=0;
    int countVet[tamanhoVetor];
    copia(vetor,countVet,tamanhoVetor);
    for(int i=0;i<tamanhoVetor;i++){
        if(countVet[i]<0){
            printf("Voce nao pode fazer um counting com numero negativo\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        countingSort(countVet,tamanhoVetor);
        printf("\nCountin Sort: ");
        for(i = 0; i < tamanhoVetor; i++)
            printf("%d ",countVet[i]);
        printf("\n");
    }
    // radix sort
    int radixVet[tamanhoVetor];
    copia(vetor,radixVet,tamanhoVetor);
    for(int i=0;i<tamanhoVetor;i++){
        if(radixVet[i]<0){
            printf("Voce nao pode fazer um radix com numero negativo\n");
            flag=1;
            break;
        }
    }
    if(flag==0){
        radixSort(radixVet,tamanhoVetor);
        printf("\nRadix Sort: ");
        for(i = 0; i < tamanhoVetor; i++)
            printf("%d ",radixVet[i]);
        printf("\n");

        return 0;
    }
}
void copia(int *A, int *V, int size){
    int i;
    for (i = 0 ; i < size ; i++)
        V[i] = A[i];
}
 void bubbleSort(int *A, int size){
    for (int i=size-1;i>=1;i--){
        for (int j =0;j<=i-1;j++){
            if (A[j] > A[j+1]){
                //troca
                int aux;
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            } 
        }
    }
 }
 void selectionSort(int *A,int size){
    for (int i=0;i<=size-2;i++){
        int menor = i;
        for (int j=i+1;j<=size-1;j++){
            if (A[menor] > A[j]){
                menor = j;
            }
        }//troca
        int aux;
        aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
    }
 }
 void insertionSort(int *A,int size){
    int i,j;
    for( i =1;i<=size-1;i++){
        int p = A[i];
        j = i;
        while(j >= 1 && p<A[j-1]){
            A[j] = A[j-1];
            j--;
        }
        A[j] = p;
    }
 }

 void mergeSort(int *A, int size){
    merge(A,0,size-1);
}
 
 void intercala(int *A,int inicio,int meio,int fim){
   int *aux = malloc(sizeof(int)*(fim-inicio+1));
   int i = inicio;
   int j = meio+1;
   int k = 0;
   while(i <= meio && j <=fim){
    if(A[i] <= A[j]){
        aux[k] = A[i];
        i++;
    }else{
        aux[k] = A[j];
        j++;

    }
    k++;
   }
   while(i<=meio){
    aux[k] = A[i];
    k++;
    i++;

   }
    while(j <=fim){
        aux[k] = A[j];
        k++;
        j++;

    }
    for (k = inicio;k<=fim;k++){
        A[k] = aux[k-inicio];
    }
    free(aux);
    


}
 void merge(int *A,int inicio,int fim){

    if(inicio<fim){
        int meio = (inicio+fim)/2;
        merge(A,inicio,meio);
        merge(A,meio+1,fim);
        intercala(A,inicio,meio,fim);
    }
    
 }
 void quickSort(int *A,int size){
    quick(A,0,size);
 }
 int particiona(int *A,int inicio,int fim){
    int posPivo = inicio;
    int i = inicio;
    int j = fim;
    while(i<j)
    {
        while(A[i] <= A[posPivo] && i < fim)
            i++;
        while(A[j] > A[posPivo])
            j--;
        if(i<j)
        {
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    int aux = A[posPivo];
    A[posPivo] = A[j];
    A[j] = aux;
    return j;
 }
 void quick(int *A,int inicio,int fim){
    if(inicio < fim){
        int posPivo = particiona(A,inicio,fim);
        quick(A,inicio,posPivo-1);
        quick(A,posPivo+1,fim);

    }
 }
 void heapSort(int *A,int size){
    for (int k=(size/2)-1;k>=0;k--){
        criaHeap(A,k,size);
    }
    for(int k=size-1;k>=1;k--){
        int aux = A[0];
        A[0] = A[k];
        A[k] = aux;
        criaHeap(A,0,k);
    }
 }
 void criaHeap(int *A,int i,int size){
    int maior = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left < size && A[left]>A[i]){
        maior = left;
    }
    if(right < size && A[right] > A[maior]){
        maior = right;
    }
    if (maior != i){
        int aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        criaHeap(A,maior,size);

    }
 }
 
void countingSort(int *A, int size){
    int maior = 0;
    for(int i = 0;i<size;i++){
            if(A[i]> maior){
                maior = A[i];
            }
        
        
    }int count[maior+1];
    int aux[size];
    for(int i = 0;i<=maior;i++){
        count[i] = 0;
    }
    for(int i = 0;i<size;i++){
        count[A[i]]++;
    }
    for(int i=1;i<=maior;i++){
        count[i] += count[i-1];
    }
    for(int i=size-1;i>=0;i--){
        count[A[i]] = count[A[i]]-1;
        aux[count[A[i]]] = A[i];
    }
    for(int i=0;i<size;i++){
        A[i] = aux[i];
    }

}
void countingSortRadix(int *A,int size,int pos){
    int aux[size];
    int count[10];
    for(int i = 0; i < 10; i++){
        count[i] = 0;
    }
    for(int i=0;i< size;i++){
        int digito = (A[i]/pos) %10;
        count[digito]++;
    }
    for(int i=1;i<10;i++){
        count[i] = count[i] + count[i-1];
    }
    for(int i=size-1;i>=0;i--){
        int digito = (A[i]/pos)%10;
        count[digito]--;
        aux[count[digito]] = A[i];
    }
    for(int i=0;i<size;i++){
        A[i] = aux[i];
    }
}
void radixSort(int *A, int size){
    int maior = 0;
    int flag=0;
    for(int i = 0;i<size;i++){
            if(A[i]> maior){
                maior = A[i];
            }
            
            
    }
        for(int pos=1;maior/pos>0;pos*=10){
            countingSortRadix(A,size,pos);
        }
    }

