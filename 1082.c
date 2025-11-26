// EXERCICIO 1082 DO BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[30][30];
int visited[30];
int lista[30];
int count_nodes;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void dfs(int u, int V) {
    visited[u] = 1;
    lista[count_nodes++] = u;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v, V);
        }
    }
}

int main() {
    int N, case_num = 1;
    int V, E;
    char u, v;

    scanf("%d", &N);

    while (N--) {
        scanf("%d %d", &V, &E);

        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < E; i++) {
            scanf(" %c %c", &u, &v);
            adj[u - 'a'][v - 'a'] = 1;
            adj[v - 'a'][u - 'a'] = 1;
        }

        printf("Case #%d:\n", case_num++);

        int connected = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                connected++;
                count_nodes = 0;
                dfs(i, V);
                
                qsort(lista, count_nodes, sizeof(int), compare);
                
                for (int j = 0; j < count_nodes; j++) {
                    printf("%c,", lista[j] + 'a');
                }
                printf("\n");
            }
        }
        printf("%d connected components\n\n", connected);
    }

    return 0;
}
