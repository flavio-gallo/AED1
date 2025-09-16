#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *X;
    int menor_valor;
    int posicao;

    scanf("%d", &N);

    X = (int *) malloc(N * sizeof(int));

    if (X == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    menor_valor = X[0];
    posicao = 0;

    for (int i = 1; i < N; i++) {
        if (X[i] < menor_valor) {
            menor_valor = X[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    free(X);

    return 0;
}
