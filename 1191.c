// EXERCÍCIO 1191 DO BEECROWD - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

char pre[1000], in[1000];
int indice;

void posordem(int inicio, int fim) {
    if (inicio > fim) return;

    int i;
    char raiz = pre[indice++];

    for (i = inicio; i <= fim; i++) {
        if (in[i] == raiz) break;
    }

    posordem(inicio, i - 1);
    posordem(i + 1, fim);
    printf("%c", raiz);
}

int main() {
    while (scanf("%s %s", pre, in) != EOF) {
        indice = 0;
        posordem(0, strlen(in) - 1);
        printf("\n");
    }
    return 0;
}
