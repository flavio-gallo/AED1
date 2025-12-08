// EXERCÍCIO 1123 DO BEECROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

#define MAX 255
#define INF 0x3f3f3f3f

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];

int main() {
    int N, M, C, K;
    int u, v, p, i, j;

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        memset(adj, 0x3f, sizeof(adj));
        memset(dist, 0x3f, sizeof(dist));
        memset(visited, 0, sizeof(visited));

        for (i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &p);
            if (p < adj[u][v]) {
                adj[u][v] = p;
                adj[v][u] = p;
            }
        }

        dist[K] = 0;

        for (i = 0; i < N; i++) {
            int current = -1;
            int minVal = INF;

            for (j = 0; j < N; j++) {
                if (!visited[j] && dist[j] < minVal) {
                    minVal = dist[j];
                    current = j;
                }
            }

            if (current == -1 || current == C - 1) break;

            visited[current] = 1;

            if (current < C - 1) {
                if (adj[current][current + 1] != INF && dist[current] + adj[current][current + 1] < dist[current + 1]) {
                    dist[current + 1] = dist[current] + adj[current][current + 1];
                }
            } else {
                for (v = 0; v < N; v++) {
                    if (adj[current][v] != INF && dist[current] + adj[current][v] < dist[v]) {
                        dist[v] = dist[current] + adj[current][v];
                    }
                }
            }
        }

        printf("%d\n", dist[C - 1]);
    }

    return 0;
}
