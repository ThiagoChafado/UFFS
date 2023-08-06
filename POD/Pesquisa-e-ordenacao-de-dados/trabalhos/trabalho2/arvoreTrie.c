#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_ALFABETO 26

typedef struct NoTrie {
    struct NoTrie* filhos[TAMANHO_ALFABETO];
    int fimDaPalavra;
} NoTrie;

NoTrie* criarNo() {
    NoTrie* no = (NoTrie*)malloc(sizeof(NoTrie));
    no->fimDaPalavra = 0;
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        no->filhos[i] = NULL;
    }
    return no;
}

void inserir(NoTrie* raiz, const char* chave) {
    NoTrie* noAtual = raiz;
    int tamanho = strlen(chave);
    for (int nivel = 0; nivel < tamanho; nivel++) {
        int indice = chave[nivel] - 'a';
        if (noAtual->filhos[indice] == NULL) {
            noAtual->filhos[indice] = criarNo();
        }
        noAtual = noAtual->filhos[indice];
    }
    noAtual->fimDaPalavra = 1;
}

int buscar(NoTrie* raiz, const char* chave) {
    NoTrie* noAtual = raiz;
    int tamanho = strlen(chave);
    for (int nivel = 0; nivel < tamanho; nivel++) {
        int indice = chave[nivel] - 'a';
        if (noAtual->filhos[indice] == NULL) {
            return 0; // Chave não encontrada
        }
        noAtual = noAtual->filhos[indice];
    }
    return noAtual != NULL && noAtual->fimDaPalavra;
}

void buscarPrefixoUtil(NoTrie* no, char* prefixo, int nivel, void (*callback)(const char*)) {
    if (no->fimDaPalavra) {
        prefixo[nivel] = '\0';
        callback(prefixo);
    }
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL) {
            prefixo[nivel] = i + 'a';
            buscarPrefixoUtil(no->filhos[i], prefixo, nivel + 1, callback);
        }
    }
}

void buscarPrefixo(NoTrie* raiz, const char* prefixo, void (*callback)(const char*)) {
    NoTrie* noAtual = raiz;
    int tamanho = strlen(prefixo);
    char* prefixoTemp = (char*)malloc((tamanho + 1) * sizeof(char));
    for (int nivel = 0; nivel < tamanho; nivel++) {
        int indice = prefixo[nivel] - 'a';
        if (noAtual->filhos[indice] == NULL) {
            return; // Prefixo não encontrado
        }
        noAtual = noAtual->filhos[indice];
        prefixoTemp[nivel] = prefixo[nivel];
    }
    prefixoTemp[tamanho] = '\0';
    buscarPrefixoUtil(noAtual, prefixoTemp, tamanho, callback);
    free(prefixoTemp);
}

NoTrie* removerChave(NoTrie* raiz, const char* chave, int nivel) {
    if (raiz == NULL) {
        return NULL;
    }
    if (chave[nivel] == '\0') {
        if (raiz->fimDaPalavra) {
            raiz->fimDaPalavra = 0;
        }
        if (isEmpty(raiz)) {
            free(raiz);
            raiz = NULL;
        }
        return raiz;
    }
    int indice = chave[nivel] - 'a';
    raiz->filhos[indice] = removerChave(raiz->filhos[indice], chave, nivel + 1);
    if (isEmpty(raiz) && !raiz->fimDaPalavra) {
        free(raiz);
        raiz = NULL;
    }
    return raiz;
}

int isEmpty(NoTrie* no) {
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL) {
            return 0; // Tem pelo menos um filho
        }
    }
    return 1; // Não tem filhos
}

void imprimirPalavra(const char* palavra) {
    printf("%s\n", palavra);
}

void imprimirTrie(NoTrie* raiz, char* prefixo, int nivel) {
    if (raiz->fimDaPalavra) {
        prefixo[nivel] = '\0';
        imprimirPalavra(prefixo);
    }
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (raiz->filhos[i] != NULL) {
            prefixo[nivel] = i + 'a';
            imprimirTrie(raiz->filhos[i], prefixo, nivel + 1);
        }
    }
}

void liberarTrie(NoTrie* raiz) {
    if (raiz == NULL) {
        return;
    }
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        liberarTrie(raiz->filhos[i]);
    }
    free(raiz);
}

int main() {
    NoTrie* raiz = criarNo();

    // Inserir palavras na Trie
    inserir(raiz, "amy");
    inserir(raiz, "ann");
    inserir(raiz, "emma");
    inserir(raiz, "rob");
    inserir(raiz, "roger");
    inserir(raiz, "robert");
    inserir(raiz, "bob");
    inserir(raiz, "emmily");

    // Buscar palavras completas na Trie
    printf("Buscando palavras completas:\n");
    printf("'amy': %s\n", buscar(raiz, "amy") ? "Encontrada" : "Não encontrada");
    printf("'robert': %s\n", buscar(raiz, "robert") ? "Encontrada" : "Não encontrada");
    printf("'pedro': %s\n", buscar(raiz, "pedro") ? "Encontrada" : "Não encontrada");

    // Buscar palavras por prefixo
    printf("\nBuscando palavras por prefixo 'rob':\n");
    buscarPrefixo(raiz, "rob", imprimirPalavra);

    // Remover uma palavra da Trie
    raiz = removerChave(raiz, "ammy", 0);

    // Imprimir todas as palavras da Trie
    printf("\nImprimindo todas as palavras da Trie:\n");
    char prefixo[100];
    imprimirTrie(raiz, prefixo, 0);

    // Liberar a memória alocada pela Trie
    liberarTrie(raiz);

    return 0;
}