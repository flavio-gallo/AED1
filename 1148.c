// EXERCÍCIO 1148 DO BEECROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX 501

int grafo[MAX][MAX];

void inicializar(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grafo[i][j] = INF;
        }
        grafo[i][i] = 0;
    }
}

int dijkstra(int origem, int destino, int n) {
    int dist[MAX], visitado[MAX];
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[origem] = 0;

    for (int cont = 0; cont < n; cont++) {
        int u = -1;
        for (int i = 1; i <= n; i++) {
            if (!visitado[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        if (dist[u] == INF) break;
        visitado[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (grafo[u][v] != INF && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }
    return dist[destino];
}

int main() {
    int N, E, X, Y, H, K, O, D;

    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;

        inicializar(N);

        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &X, &Y, &H);
            if (grafo[Y][X] != INF) {
                grafo[X][Y] = 0;
                grafo[Y][X] = 0;
            } else {
                grafo[X][Y] = H;
            }
        }

        scanf("%d", &K);
        while (K--) {
            scanf("%d %d", &O, &D);
            int resultado = dijkstra(O, D, N);
            if (resultado == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", resultado);
            }
        }
        printf("\n");
    }
    return 0;
}
