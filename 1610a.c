// EXERCÍCIO 1610 DO BEECROWD UTILIZANDO MATRIZ - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10005
#define MAXM 30005

int head[MAXN];
int to[MAXM];
int proximo[MAXM];
int vis[MAXN];
int arestas_cnt;

void init_grafo(int n) {
    for(int i = 0; i <= n; i++) {
        head[i] = -1;
        vis[i] = 0;
    }
    arestas_cnt = 0;
}

void add_aresta(int u, int v) {
    to[arestas_cnt] = v;
    proximo[arestas_cnt] = head[u];
    head[u] = arestas_cnt++;
}

int dfs(int u) {
    vis[u] = 1; 
    for(int e = head[u]; e != -1; e = proximo[e]) {
        int v = to[e];
        if(vis[v] == 1) return 1; 
        if(vis[v] == 0) {
            if(dfs(v)) return 1;
        }
    }
    vis[u] = 2; 
    return 0;
}

int main() {
    int T;
    if(scanf("%d", &T) != 1) return 0;

    while(T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        init_grafo(N);

        for(int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            add_aresta(A, B); 
        }

        int ciclo = 0;
        for(int i = 1; i <= N; i++) {
            if(vis[i] == 0) {
                if(dfs(i)) {
                    ciclo = 1;
                    break;
                }
            }
        }

        if(ciclo) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}
