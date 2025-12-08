// EXERCÍCIO 1128 DO BEECROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

char adj[2005][2005];
char adjT[2005][2005];
int vis[2005];
int N;

void dfs(int u) {
    vis[u] = 1;
    for (int v = 1; v <= N; v++) {
        if (adj[u][v] && !vis[v]) dfs(v);
    }
}

void dfsT(int u) {
    vis[u] = 1;
    for (int v = 1; v <= N; v++) {
        if (adjT[u][v] && !vis[v]) dfsT(v);
    }
}

int main() {
    int M, v, w, p, i;
    while (scanf("%d %d", &N, &M) && (N || M)) {
        memset(adj, 0, sizeof(adj));
        memset(adjT, 0, sizeof(adjT));
        
        for (i = 0; i < M; i++) {
            scanf("%d %d %d", &v, &w, &p);
            adj[v][w] = 1;
            adjT[w][v] = 1;
            if (p == 2) {
                adj[w][v] = 1;
                adjT[v][w] = 1;
            }
        }

        int possible = 1;
        
        memset(vis, 0, sizeof(vis));
        dfs(1);
        for (i = 1; i <= N; i++) {
            if (!vis[i]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            memset(vis, 0, sizeof(vis));
            dfsT(1);
            for (i = 1; i <= N; i++) {
                if (!vis[i]) {
                    possible = 0;
                    break;
                }
            }
        }

        printf("%d\n", possible);
    }
    return 0;
}
