// EXERCICIO 1062 DO BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>
#include <stdlib.h>

#define MAX 1005

int main() {
    int N;
    int target[MAX];
    int stack[MAX];
    
    while (scanf("%d", &N) && N != 0) {
        
        while (1) {
            scanf("%d", &target[0]);
            if (target[0] == 0) {
                printf("\n");
                break;
            }
            
            for (int i = 1; i < N; i++) {
                scanf("%d", &target[i]);
            }
            
            int top = 0;        
            int incoming = 1;
            int target_idx = 0; 
            
            while (target_idx < N) {
                
                if (top > 0 && stack[top - 1] == target[target_idx]) {
                    top--;
                    target_idx++;
                }
                else if (incoming <= N) {
                    stack[top] = incoming;
                    top++;
                    incoming++;
                }
                else {
                    break; 
                }
            }
            
            if (target_idx == N) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    
    return 0;
}
