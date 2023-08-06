#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    unsigned int frequency;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data, unsigned int frequency) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void swapNodes(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void sortForest(struct Node** forest, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (forest[j]->frequency > forest[j + 1]->frequency) {
                swapNodes(&forest[j], &forest[j + 1]);
            }
        }
    }
}

struct Node* mergeTrees(struct Node* left, struct Node* right) {
    struct Node* merged = createNode('\0', left->frequency + right->frequency);
    merged->left = left;
    merged->right = right;
    return merged;
}

struct Node* buildHuffmanTree(char* text) {
    int frequencies[256] = {0};
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        frequencies[(int)text[i]]++;
    }

    struct Node** forest = (struct Node**)malloc(256 * sizeof(struct Node*));
    int forestSize = 0;
    for (i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            forest[forestSize++] = createNode((char)i, frequencies[i]);
        }
    }

    sortForest(forest, forestSize);

    while (forestSize > 1) {
        struct Node* smallest1 = forest[0];
        struct Node* smallest2 = forest[1];
        struct Node* merged = mergeTrees(smallest1, smallest2);

        forest[0] = merged;
        forest[1] = forest[forestSize - 1];
        forestSize--;

        sortForest(forest, forestSize);
    }

    struct Node* huffmanTree = forest[0];
    free(forest);

    return huffmanTree;
}

void printHuffmanCodes(struct Node* root, int* code, int depth) {
    if (root->left == NULL && root->right == NULL) {
        int i;
        printf("%c: ", root->data);
        for (i = 0; i < depth; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    } else {
        code[depth] = 0;
        printHuffmanCodes(root->left, code, depth + 1);

        code[depth] = 1;
        printHuffmanCodes(root->right, code, depth + 1);
    }
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    struct Node* huffmanTree = buildHuffmanTree(input);

    int code[256] = {0};
    int depth = 0;

    printHuffmanCodes(huffmanTree, code, depth);

    return 0;
}
