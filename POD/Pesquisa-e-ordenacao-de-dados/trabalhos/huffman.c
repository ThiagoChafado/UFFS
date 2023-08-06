#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file huffman.c
 * @author Thiago Chafado Almeida,Joao Victor da Silva,Joao Eduardo Ferrari
 * @version 0.1
 * @date 03-07-2023
 *
 * @copyright Copyright (c) 2023
 *
 *
 * @brief Arquivo arvore de huffman
 *
 */

//FIZ SEGUINDO ESSES PASSOS A RISCA
/*Passos:
– Contar a frequência de todos os caracteres no caractero de entrada;
– Montar um floresta (várias árvores), onde cada árvore é unitária e
contém, além do caractere em si, seu número de ocorrências no caractero;
– Ordenar a lista de árvores em ordem crescente de frequência;
– Unir todas as árvores até formar um única árvore:
● Selecionar as duas árvores que possuem as menores frequências
● Cria uma nova árvore combinando as duas árvores obtidas anteriormente
– A frequência desta árvore será a soma das frequências das árvores que foram unidas
● Realocar esta árvore no conjunto de árvores, mantendo a ordenação*/

// Estruturado do Nó da árvore
struct Node {
    char data;
    unsigned int frequencia;
    struct Node* left;
    struct Node* right;
};

// novo nó
struct Node* criaNó(char data, unsigned int frequencia) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->frequencia = frequencia;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// trocando a posicao dos nos
void swapNó(struct Node** a, struct Node** b) {
    struct Node* aux = *a;
    *a = *b;
    *b = aux;
}

// ordenando a floresta com bubble sort
void ordenaFloresta(struct Node** floresta, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (floresta[j]->frequencia > floresta[j + 1]->frequencia || (floresta[j]->frequencia == floresta[j+1]->frequencia && floresta[j]->data > floresta[j+1]->data)) {
                swapNó(&floresta[j], &floresta[j + 1]);
            }
        }
    }
}
// merge das arvores
struct Node* mergeArvores(struct Node* left, struct Node* right) {
    struct Node* novo = criaNó('\0', left->frequencia + right->frequencia);
    novo->left = left;
    novo->right = right;
    return novo;
}

/// funcao principal de criacao da arvore
struct Node* criacaoArvore(char* caracter) {
    int frequencies[256] = {0}; // Array para armazenar as frequências de cada caractere
    int i;
    // Contar a frequência de cada caractere no caracter
    for (i = 0; caracter[i] != '\0'; i++) {
        
        
        frequencies[(int)caracter[i]]++;
        
    }

    // Montar a floresta inicial com árvores unitárias
    struct Node** floresta = (struct Node**)malloc(256 * sizeof(struct Node*));
    int tamanhoFloresta = 0;
    for (i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            floresta[tamanhoFloresta++] = criaNó((char)i, frequencies[i]);
        }
    }

    
    

    // unindo arvore
    while (tamanhoFloresta > 1) {
        ordenaFloresta(floresta, tamanhoFloresta);
        
        struct Node* menor1 = floresta[0];
        struct Node* menor2 = floresta[1];

        
        struct Node* arvoreMergeada = mergeArvores(menor1, menor2);
    
        // recolocar a arvore 
        floresta[0] = arvoreMergeada;
        for (int i =1; i< tamanhoFloresta-1; i++){
            floresta[i] = floresta[i+1];
        }
        floresta[tamanhoFloresta-1] = NULL;
        tamanhoFloresta--;

        
    }

    
    struct Node* arvore = floresta[0];

    
    free(floresta);

    return arvore;
}

// impressao in order
void imprimirHuffman(struct Node* raiz, int* codigo, int profundidade) {
    if (raiz->left == NULL && raiz->right == NULL) {
        int i;
        if (raiz->data == ' ') {
            printf(" : ");
            for (i = 0; i < profundidade; i++) {
                printf("%d", codigo[i]);
            }
        } else {
            printf("%c: ", raiz->data);
            for (i = 0; i < profundidade; i++) {
                printf("%d", codigo[i]);
            }
        }
        printf("\n");
    } else {
        codigo[profundidade] = 0;
        imprimirHuffman(raiz->left, codigo, profundidade + 1);

        codigo[profundidade] = 1;
        imprimirHuffman(raiz->right, codigo, profundidade + 1);

        codigo[profundidade] = 0; 
    }
}



int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove o caractere de nova linha
    struct Node* arvore = criacaoArvore(input);

    int codigo[256] = {0};
    int profundidade = 0;

    
    imprimirHuffman(arvore, codigo, profundidade);
    

    return 0;
}
