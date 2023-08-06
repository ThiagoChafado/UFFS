
/**
 * @file external.c
 * @author Thiago Chafado Almeida e João Victor da Silva
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Questão 02 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma ordenação externa utilizando a restrição de que somente 5
 *  elementos podem ser armazenados em memória (vetores de teste no template). A
 *  definição deste limite está na variável MAX_IN_MEMORY abaixo.
 *
 *      Utilize os vetores comentados no código para realizar seus testes.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */

/*Instrucoes adicionais
Compilar o arquivo usando -lm como parametro para importar as bibliotecas math.h*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IN_MEMORY 5

#if defined(_WIN32)
#define PLATFORM "windows"
#elif defined(__unix__)
#define PLATFORM "linux"
#endif

void sort(int *arr);
int lowest(int *arr);
int hasNumber(int *arr);

int main()
{
    int vec[] = {3, 98, 61, 62,  1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46,
        69, 48, 82, 52,  4, 87, 38, 44, 42, 72,  2, 95, 84, 34, 40, 23, 11, 75,
        37, 62, 96, 12, 22, 56, 20, 64,  2, 30, 48,  6, 19, 34, 31};
    int vecLen = sizeof(vec) / sizeof(int);

    FILE *inputFiles[MAX_IN_MEMORY];
    FILE *outputFiles[MAX_IN_MEMORY];

    
    for (int i = 0; i < MAX_IN_MEMORY; i++)
    {
        char inputDirectory[30];
        char outputDirectory[30];

        if (strcmp(PLATFORM, "windows") == 0)
        {
            sprintf(inputDirectory, ".\\bin\\inputs\\input%d.txt", i);
            sprintf(outputDirectory, ".\\bin\\outputs\\output%d.txt", i);
        }
        else
        {
            sprintf(inputDirectory, "./bin/inputs/input%d.txt", i);
            sprintf(outputDirectory, "./bin/outputs/output%d.txt", i);
        }

        inputFiles[i] = fopen(inputDirectory, "w+");
        outputFiles[i] = fopen(outputDirectory, "w+");
    }

    
    int vecIndex = 0;

    while (vecIndex < vecLen)
    {
        
        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            int arr[MAX_IN_MEMORY] = {0};
            int arrActualLen = 0;
            for (int j = 0; j < MAX_IN_MEMORY; j++)
            {
                if (vecIndex < vecLen)
                {
                    arr[j] = vec[(vecIndex)++];
                    arrActualLen++;
                }
                else
                    arr[j] = __INT32_MAX__;
            }

            
            sort(arr);

            
            for (int j = 0; j < arrActualLen; j++)
            {
                if (arr[j] == __INT32_MAX__)
                    break;

                if (j == arrActualLen - 1)
                {
                    fprintf(inputFiles[i], ",%d, ", arr[j]);
                    continue;
                }
                else
                    fprintf(inputFiles[i], ",%d", arr[j]);
            }
        }
    }

    
    int outputCount = ((int)ceil(sqrt(vecLen)) % 5) + 1;

    for (int k = 0; k < outputCount; k++)
    {
        int arr[MAX_IN_MEMORY];
        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            if (k == 0)
                fseek(inputFiles[i], 1, SEEK_SET);

            fscanf(inputFiles[i], "%d,", &arr[i]);
        }
        while (hasNumber(arr) == 1)
        {
            int lowestIndex = lowest(arr);
            fprintf(outputFiles[k], ",%d", arr[lowestIndex]);
            int n;
            arr[lowestIndex] = (fscanf(inputFiles[lowestIndex], "%d,", &n) == 1) ? n : __INT32_MAX__;
        }

        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            fseek(inputFiles[i], 1, SEEK_CUR);
        }
    }

    for (int i = 0; i < outputCount; i++)
    {
        fprintf(outputFiles[i], ",");
    }

    outputCount--;

    for (int i = 0; i < MAX_IN_MEMORY; i++)
    {
        rewind(inputFiles[i]);
        rewind(outputFiles[i]);
    }

    for (int k = 0; k < outputCount; k++)
    {
        int arr[MAX_IN_MEMORY];
        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            arr[i] = __INT32_MAX__;
        }
        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            fseek(outputFiles[i], 1, SEEK_SET);
            fscanf(outputFiles[i], "%d,", &arr[i]);
        }
        while (hasNumber(arr) == 1)
        {
            int lowestIndex = lowest(arr);
            fprintf(inputFiles[k], ",%d", arr[lowestIndex]);
            int n;
            arr[lowestIndex] = (fscanf(outputFiles[lowestIndex], "%d,", &n) == 1) ? n : __INT32_MAX__;
        }

        for (int i = 0; i < MAX_IN_MEMORY; i++)
        {
            fseek(outputFiles[i], 1, SEEK_CUR);
        }
    }

    for (int i = 0; i < outputCount; i++)
    {
        fprintf(inputFiles[i], ",");
    }

    
    int farr[vecLen];
    int farrActualLen = 0;

    fseek(inputFiles[0], 1, SEEK_SET);

    while(farrActualLen < vecLen)
    {
        fscanf(inputFiles[0], "%d,", &farr[farrActualLen++]);
    }

    printf("Initial array:\n");
    for(int i = 0; i < vecLen; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\nSorted array:\n");
    for(int i = 0; i < vecLen; i++)
    {
        printf("%d ", farr[i]);
    }
    printf("\n");

    return 0;
}

void sort(int *arr)
{
    int lower;
    for (int i = 0; i < MAX_IN_MEMORY - 1; i++)
    {
        lower = i;
        for (int j = i + 1; j < MAX_IN_MEMORY; j++)
        {
            if (arr[lower] > arr[j])
                lower = j;
        }
        int c = arr[i];
        arr[i] = arr[lower];
        arr[lower] = c;
    }
}

int lowest(int *arr)
{
    int lower = 0;
    for (int i = 1; i < MAX_IN_MEMORY; i++)
    {
        if (arr[i] < arr[lower])
            lower = i;
    }

    return lower;
}

int hasNumber(int *arr)
{
    int flag = 0;
    for (int i = 0; i < MAX_IN_MEMORY; i++)
    {
        if (arr[i] != __INT32_MAX__)
            return 1;
    }
    return flag;
}