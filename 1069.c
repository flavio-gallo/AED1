//PROBLEMA 1069 BEECROWD, UTILIZANDO PILHAS - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 1001

int main() {
    int n; //n casos de teste
    char mina[MAX_TAMANHO];
    
    //quantidade de casos de teste
    scanf("%d", &n);
    
    //laço para cada caso
    while (n--) {
        //string que representa a mina
        scanf("%s", mina);
        
        char pilha[MAX_TAMANHO];
        int topo = -1; //pilha vazia
        int diamantes = 0;
        int i;
        
        //percorrendo a string
        for (i = 0; i < strlen(mina); i++) {
            if (mina[i] == '<') {
                // < empilha
                topo++;
                pilha[topo] = '<';
            } else if (mina[i] == '>') {
                // ">" verifica se há um correspondente ">"
                if (topo != -1) {
                    // desempilha o "<" e conta um diamante
                    topo--;
                    diamantes++;
                }
            }
            // '.' são ignorados
        }
        
        //total de diamantes
        printf("%d\n", diamantes);
    }
    
    return 0;
}
