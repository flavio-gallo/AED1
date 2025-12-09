// EXERCÍCIO 1194 DO BEECROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

void solve(char *pre, char *in, int len) {
    if (len <= 0) return;

    char root = pre[0];
    int p = 0;

    while (p < len && in[p] != root) {
        p++;
    }

    solve(pre + 1, in, p);
    solve(pre + 1 + p, in + p + 1, len - p - 1);
    printf("%c", root);
}

int main() {
    int c, n;
    char s1[100], s2[100];

    scanf("%d", &c);

    while (c--) {
        scanf("%d %s %s", &n, s1, s2);
        solve(s1, s2, n);
        printf("\n");
    }

    return 0;
}
