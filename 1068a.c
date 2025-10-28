// EXERCÍCIO 1068a, BALANÇO DE PARÊNTESES COM PLIHA USANDO VETORES - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <string.h>

#define MAX_EXPR 1001
#define MAX_PILHA 1001

// Estrutura da pilha
typedef struct {
    char dados[MAX_PILHA];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == -1;
}

// Empilha um caractere
void empilhar(Pilha *p, char c) {
    if (p->topo < MAX_PILHA - 1) {
        p->dados[++(p->topo)] = c;
    }
}

// Desempilha um caractere
char desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->dados[(p->topo)--];
    }
    return '\0'; // Retorna caractere nulo se pilha vazia
}

// Função principal que verifica o balanceamento de parênteses
int verificarBalanceamento(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);
    
    int i;
    // Percorre cada caractere da expressão
    for (i = 0; i < strlen(expressao); i++) {
        char c = expressao[i];
        
        // Se encontrar parêntese de abertura, empilha
        if (c == '(') {
            empilhar(&pilha, c);
        }
        // Se encontrar parêntese de fechamento
        else if (c == ')') {
            // Se a pilha estiver vazia, significa que não há parêntese de abertura correspondente
            if (vazia(&pilha)) {
                return 0; // Incorreto
            }
            // Desempilha o parêntese de abertura correspondente
            desempilhar(&pilha);
        }
    }
    
    // Se a pilha estiver vazia no final, todos os parênteses foram balanceados corretamente
    // Se não estiver vazia, significa que há parênteses de abertura sem fechamento
    return vazia(&pilha);
}

int main() {
    char expressao[MAX_EXPR];
    
    // Lê expressões até o final do arquivo (EOF)
    while (fgets(expressao, MAX_EXPR, stdin) != NULL) {
        // Remove o caractere de nova linha se existir
        expressao[strcspn(expressao, "\n")] = '\0';
        
        // Verifica o balanceamento e imprime o resultado
        if (verificarBalanceamento(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
