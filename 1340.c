// EXERCÍCIO BEECROWD 1340 - FLÁVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdbool.h> // para usar true/false

#define MAX_SIZE 1005

int main() {
    int n;

    // continua lendo enquanto houver casos de teste (scanf retorna o número de itens lidos).
    while (scanf("%d", &n) == 1) {

        // estruturas para simulação
        // pilha (stack)
        int stack[MAX_SIZE];
        int stack_top = -1; // topo da pilha

        // fila (queue)
        int queue[MAX_SIZE];
        int queue_head = 0; // início da fila
        int queue_tail = 0; // final da fila

        // fila de prioridade (priority queue) - simulada com um vetor
        int pq[MAX_SIZE];
        int pq_size = 0; // elementos na fila de prioridade

        bool is_stack = true;
        bool is_queue = true;
        bool is_pq = true;

        // loop para os n comandos
        for (int i = 0; i < n; i++) {
            int command, value;
            scanf("%d %d", &command, &value);

            if (command == 1) {
                // adiciona o elemento em todas as estruturas simuladas
                stack[++stack_top] = value;
                queue[queue_tail++] = value;
                pq[pq_size++] = value;
            } else {
                // o valor esperado após a remoção é 'value'

                // verifica a pilha
                if (is_stack) {
                    // se a pilha está vazia ou o topo não é o valor esperado
                    if (stack_top < 0 || stack[stack_top] != value) {
                        is_stack = false;
                    } else {
                        stack_top--; // remove da pilha
                    }
                }

                // verifica a fila
                if (is_queue) {
                    // se a fila está vazia ou o primeiro elemento não é o valor esperado
                    if (queue_head >= queue_tail || queue[queue_head] != value) {
                        is_queue = false;
                    } else {
                        queue_head++; // remove da fila
                    }
                }

                // verifica a fila de prioridade
                if (is_pq) {
                    if (pq_size <= 0) {
                        is_pq = false;
                    } else {
                        // encontra o maior elemento na PQ simulada
                        int max_val = -1;
                        int max_idx = -1;
                        for (int j = 0; j < pq_size; j++) {
                            if (pq[j] > max_val) {
                                max_val = pq[j];
                                max_idx = j;
                            }
                        }

                        // se o maior elemento não for o valor esperado
                        if (max_val != value) {
                            is_pq = false;
                        } else {
                            // remove o elemento encontrado (trocando com o último e diminuindo o tamanho)
                            pq[max_idx] = pq[pq_size - 1];
                            pq_size--;
                        }
                    }
                }
            }
        }

        // resultado final
        int possible_count = is_stack + is_queue + is_pq;

        if (possible_count == 0) {
            printf("impossible\n");
        } else if (possible_count > 1) {
            printf("not sure\n");
        } else {
            if (is_stack) {
                printf("stack\n");
            } else if (is_queue) {
                printf("queue\n");
            } else { // if (is_pq)
                printf("priority queue\n");
            }
        }
    }

    return 0;
}
