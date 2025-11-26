// EXERCICIO 1200 DO BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char dado;
    struct Node *esquerda;
    struct Node *direita;
} Node;

void inserir(Node **raiz, char valor) {
    if (*raiz == NULL) {
        *raiz = (Node *)malloc(sizeof(Node));
        (*raiz)->dado = valor;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else {
        if (valor < (*raiz)->dado) {
            inserir(&(*raiz)->esquerda, valor);
        } else if (valor > (*raiz)->dado) {
            inserir(&(*raiz)->direita, valor);
        }
    }
}

int pesquisar(Node *raiz, char valor) {
    if (raiz == NULL) return 0;
    if (raiz->dado == valor) return 1;
    
    if (valor < raiz->dado)
        return pesquisar(raiz->esquerda, valor);
    else
        return pesquisar(raiz->direita, valor);
}

void infixa(Node *raiz, int *primeiro) {
    if (raiz == NULL) return;
    
    infixa(raiz->esquerda, primeiro);
    
    if (!*primeiro) printf(" ");
    printf("%c", raiz->dado);
    *primeiro = 0;
    
    infixa(raiz->direita, primeiro);
}


void prefixa(Node *raiz, int *primeiro) {
    if (raiz == NULL) return;
    
    if (!*primeiro) printf(" ");
    printf("%c", raiz->dado);
    *primeiro = 0;
    
    prefixa(raiz->esquerda, primeiro);
    prefixa(raiz->direita, primeiro);
}


void posfixa(Node *raiz, int *primeiro) {
    if (raiz == NULL) return;
    
    posfixa(raiz->esquerda, primeiro);
    posfixa(raiz->direita, primeiro);
    
    if (!*primeiro) printf(" ");
    printf("%c", raiz->dado);
    *primeiro = 0;
}

int main() {
    Node *raiz = NULL;
    char comando[20];
    char valor;
    
    while (scanf("%s", comando) != EOF) {
        
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor);
            inserir(&raiz, valor);
        } 
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);
            if (pesquisar(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }
        } 
        else {
            int flag_primeiro = 1;
            
            if (strcmp(comando, "INFIXA") == 0) {
                infixa(raiz, &flag_primeiro);
                printf("\n");
            } 
            else if (strcmp(comando, "PREFIXA") == 0) {
                prefixa(raiz, &flag_primeiro);
                printf("\n");
            } 
            else if (strcmp(comando, "POSFIXA") == 0) {
                posfixa(raiz, &flag_primeiro);
                printf("\n");
            }
        }
    }
    
    return 0;
}
