// EXERCÍCIO 1931 DO BEEDROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>

#define MAXC 10010
#define MAXV 100010
#define INF 1000000000
#define HEAP_SIZE 500000

typedef struct {
    int v, w, next;
} Edge;

Edge edges[MAXV];
int head[MAXC];
int edge_count = 0;

void add_edge(int u, int v, int w) {
    edges[edge_count].v = v;
    edges[edge_count].w = w;
    edges[edge_count].next = head[u];
    head[u] = edge_count++;
}

typedef struct {
    int u, cost, parity;
} Node;

Node heap[HEAP_SIZE];
int heap_size = 0;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(int u, int cost, int parity) {
    heap[heap_size].u = u;
    heap[heap_size].cost = cost;
    heap[heap_size].parity = parity;
    int i = heap_size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].cost <= heap[i].cost) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

Node pop() {
    Node ret = heap[0];
    heap[0] = heap[--heap_size];
    int i = 0;
    while (i * 2 + 1 < heap_size) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int smallest = i;
        if (left < heap_size && heap[left].cost < heap[smallest].cost) smallest = left;
        if (right < heap_size && heap[right].cost < heap[smallest].cost) smallest = right;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return ret;
}

int dist[MAXC][2];

int main() {
    int C, V;
    if (scanf("%d %d", &C, &V) != 2) return 0;

    for (int i = 0; i <= C; i++) head[i] = -1;

    for (int i = 0; i < V; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    for (int i = 0; i <= C; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[1][0] = 0;
    push(1, 0, 0);

    while (heap_size > 0) {
        Node current = pop();
        int u = current.u;
        int cost = current.cost;
        int parity = current.parity;

        if (cost > dist[u][parity]) continue;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].v;
            int w = edges[i].w;
            int new_cost = cost + w;
            int new_parity = 1 - parity;

            if (new_cost < dist[v][new_parity]) {
                dist[v][new_parity] = new_cost;
                push(v, new_cost, new_parity);
            }
        }
    }

    if (dist[C][0] == INF) printf("-1\n");
    else printf("%d\n", dist[C][0]);

    return 0;
}
