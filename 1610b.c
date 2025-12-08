// EXERCÍCIO 1610 DO BEECROWD UTILIZANDO LISTAS - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* adj[10005];
int vis[10005];

void add_edge(int u, int v) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->dest = v;
    new_node->next = adj[u];
    adj[u] = new_node;
}

int dfs(int u) {
    vis[u] = 1;
    Node* ptr = adj[u];
    while (ptr != NULL) {
        int v = ptr->dest;
        if (vis[v] == 1) return 1;
        if (vis[v] == 0) {
            if (dfs(v)) return 1;
        }
        ptr = ptr->next;
    }
    vis[u] = 2;
    return 0;
}

void free_list(int n) {
    for (int i = 1; i <= n; ++i) {
        Node* ptr = adj[i];
        while (ptr != NULL) {
            Node* temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    
    while (T--) {
        int N, M;
        if (scanf("%d %d", &N, &M) != 2) break;
        
        for (int i = 1; i <= N; ++i) {
            adj[i] = NULL;
            vis[i] = 0;
        }
        
        for (int i = 0; i < M; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u, v);
        }
        
        int cycle = 0;
        for (int i = 1; i <= N; ++i) {
            if (vis[i] == 0) {
                if (dfs(i)) {
                    cycle = 1;
                    break;
                }
            }
        }
        
        printf("%s\n", cycle ? "SIM" : "NAO");
        
        free_list(N);
    }
    return 0;
}
