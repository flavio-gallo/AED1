// EXERCICIO 1110 DO BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>

int main() {
    int n;
    // O vetor precisa ser maior que 50 porque adicionamos cartas ao final.
    // Um tamanho de 200 é mais que suficiente para N=50.
    int fila[200]; 

    // Lê N enquanto N for diferente de 0
    while (scanf("%d", &n) && n != 0) {
        
        // Inicializa a fila com cartas de 1 a n
        for (int i = 0; i < n; i++) {
            fila[i] = i + 1;
        }

        int inicio = 0;
        int fim = n; // O fim aponta para a posição livre após o último elemento

        printf("Discarded cards:");

        int primeiro_descarte = 1; // Flag para controlar a vírgula

        // Enquanto houver 2 ou mais cartas (tamanho da fila >= 2)
        while (fim - inicio >= 2) {
            if (!primeiro_descarte) {
                printf(",");
            }
            
            // Joga fora a carta do topo
            printf(" %d", fila[inicio]);
            inicio++;
            
            primeiro_descarte = 0;

            // Move a próxima carta para a base da pilha
            fila[fim] = fila[inicio];
            fim++;     // Aumenta o tamanho da fila no final
            inicio++;  // Remove a carta que foi movida do início
        }

        printf("\nRemaining card: %d\n", fila[inicio]);
    }

    return 0;
}
