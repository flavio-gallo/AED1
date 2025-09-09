//PROBLEMA 1180 BEECROWD - FLAVIO GALLO

#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int x[1000];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    int menor_valor = x[0];
    int posicao = 0;

    for (int i = 1; i < n; i++) {
        if (x[i] < menor_valor) {
            menor_valor = x[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
