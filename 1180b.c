

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

    for (int *p = X; p < X + N; p++) {
        scanf("%d", p);
    }

    menor_valor = *X;
    posicao = 0;

    for (int *p = X + 1; p < X + N; p++) {
        if (*p < menor_valor) {
            menor_valor = *p;
            posicao = p - X;
        }
    }

    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    free(X);

    return 0;
}
