// EXERCICIO 1548 DO BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, M;
    int original[1005];
    int ordenado[1005];

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &M);

        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i];
        }

        qsort(ordenado, M, sizeof(int), compare);

        int nao_mudaram = 0;
        for (int i = 0; i < M; i++) {
            if (original[i] == ordenado[i]) {
                nao_mudaram++;
            }
        }

        printf("%d\n", nao_mudaram);
    }

    return 0;
}
