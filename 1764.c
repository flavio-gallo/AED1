// EXERCÍCIO 1764 DO BEEDROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[40005];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void union_sets(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        Edge edges[50005];

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        qsort(edges, n, sizeof(Edge), compare);

        int total_weight = 0;

        for (int i = 0; i < n; i++) {
            if (find(edges[i].u) != find(edges[i].v)) {
                union_sets(edges[i].u, edges[i].v);
                total_weight += edges[i].w;
            }
        }

        printf("%d\n", total_weight);
    }

    return 0;
}
