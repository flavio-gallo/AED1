// EXERCICIO 1566 BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore binária
typedef struct Node {
    int height;
    int count;      // Para lidar com alturas repetidas
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int height) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->height = height;
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir na árvore binária de busca
Node* insert(Node* root, int height) {
    if (root == NULL) {
        return createNode(height);
    }
    
    if (height < root->height) {
        root->left = insert(root->left, height);
    } else if (height > root->height) {
        root->right = insert(root->right, height);
    } else {
        // Altura já existe, incrementa o contador
        root->count++;
    }
    
    return root;
}

// Função para percorrer a árvore em ordem (in-order traversal)
void inOrderTraversal(Node* root, int* index, int* result) {
    if (root != NULL) {
        // Percorre a subárvore esquerda
        inOrderTraversal(root->left, index, result);
        
        // Adiciona a altura ao resultado 'count' vezes
        for (int i = 0; i < root->count; i++) {
            result[(*index)++] = root->height;
        }
        
        // Percorre a subárvore direita
        inOrderTraversal(root->right, index, result);
    }
}

// Função para liberar a memória da árvore
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int NC; // Número de casos de teste
    scanf("%d", &NC);
    
    while (NC--) {
        int n; // Número de alturas
        scanf("%d", &n);
        
        int* heights = (int*)malloc(n * sizeof(int));
        Node* root = NULL;
        
        // Lê as alturas e constrói a árvore
        for (int i = 0; i < n; i++) {
            scanf("%d", &heights[i]);
            root = insert(root, heights[i]);
        }
        
        // Array para armazenar o resultado ordenado
        int* sortedHeights = (int*)malloc(n * sizeof(int));
        int index = 0;
        
        // Percorre a árvore em ordem para obter alturas ordenadas
        inOrderTraversal(root, &index, sortedHeights);
        
        // Imprime o resultado
        for (int i = 0; i < n; i++) {
            printf("%d", sortedHeights[i]);
            if (i < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
        
        free(heights);
        free(sortedHeights);
        freeTree(root);
    }
    
    return 0;
}
