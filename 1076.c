// EXERCICIO 1076 DO BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

int main() {
    int T, N, V, A;
    int u, v;
    int matriz[50][50];
    int arestas;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        scanf("%d %d", &V, &A);

        memset(matriz, 0, sizeof(matriz));
        arestas = 0;

        for (int i = 0; i < A; i++) {
            scanf("%d %d", &u, &v);
            
            if (matriz[u][v] == 0) {
                matriz[u][v] = 1;
                matriz[v][u] = 1;
                arestas++;
            }
        }

        printf("%d\n", arestas * 2);
    }

    return 0;
}
