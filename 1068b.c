// EXERCÍCIO BEECROWD 1068b, COM PILHA USANDO LISTA ENCADEADA - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR 1001

// Estrutura do nó da lista encadeada
typedef struct No {
    char dado;
    struct No *proximo;
} No;

// Estrutura da pilha
typedef struct {
    No *topo;
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = NULL;
}

// Verifica se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == NULL;
}

// Empilha um caractere
void empilhar(Pilha *p, char c) {
    // Aloca memória para o novo nó
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    // Configura o novo nó
    novoNo->dado = c;
    novoNo->proximo = p->topo;  // O novo nó aponta para o antigo topo
    p->topo = novoNo;          // Topo agora aponta para o novo nó
}

// Desempilha um caractere
char desempilhar(Pilha *p) {
    if (vazia(p)) {
        return '\0'; // Retorna caractere nulo se pilha vazia
    }
    
    // Remove o nó do topo
    No *noRemovido = p->topo;
    char dado = noRemovido->dado;
    p->topo = noRemovido->proximo;  // Topo aponta para o próximo nó
    
    // Libera a memória do nó removido
    free(noRemovido);
    
    return dado;
}

// Libera toda a memória alocada para a pilha
void liberarPilha(Pilha *p) {
    while (!vazia(p)) {
        desempilhar(p);
    }
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
                liberarPilha(&pilha); // Libera memória antes de retornar
                return 0; // Incorreto
            }
            // Desempilha o parêntese de abertura correspondente
            desempilhar(&pilha);
        }
    }
    
    // Verifica se a pilha está vazia no final
    int resultado = vazia(&pilha);
    
    // Libera a memória da pilha
    liberarPilha(&pilha);
    
    return resultado;
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
