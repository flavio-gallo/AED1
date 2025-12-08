// EXERCÍCIO 1256 DO BEECROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

void inserir(Node **tabela, int posicao, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prox = NULL;

    if (tabela[posicao] == NULL) {
        tabela[posicao] = novo;
    } else {
        Node *temp = tabela[posicao];
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    int primeiro = 1;

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        if (!primeiro) {
            printf("\n");
        }
        primeiro = 0;

        Node *tabela[M];
        for (int i = 0; i < M; i++) {
            tabela[i] = NULL;
        }

        for (int i = 0; i < C; i++) {
            int val;
            scanf("%d", &val);
            inserir(tabela, val % M, val);
        }

        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            Node *temp = tabela[i];
            while (temp != NULL) {
                printf("%d -> ", temp->valor);
                temp = temp->prox;
            }
            printf("\\\n");
        }
    }

    return 0;
}
