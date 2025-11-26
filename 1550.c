// EXERCICIO 1550 DO BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

#define MAX 100005

int dist[MAX];
int queue[MAX];

int inverter(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int bfs(int a, int b) {
    memset(dist, -1, sizeof(dist));
    int head = 0, tail = 0;

    queue[tail++] = a;
    dist[a] = 0;

    while (head < tail) {
        int u = queue[head++];

        if (u == b) return dist[u];

        int v1 = u + 1;
        if (v1 < MAX && dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            queue[tail++] = v1;
        }

        int v2 = inverter(u);
        if (v2 < MAX && dist[v2] == -1) {
            dist[v2] = dist[u] + 1;
            queue[tail++] = v2;
        }
    }
    return -1;
}

int main() {
    int T, A, B;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }

    return 0;
}
