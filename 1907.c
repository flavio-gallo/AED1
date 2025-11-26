// EXERCICIO 1907 DO BEECROWD - FLAVIO GALLO CAJAZEIRA
#include <stdio.h>

#define MAX 1030

char grid[MAX][MAX];
int stackX[MAX * MAX];
int stackY[MAX * MAX];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int count = 0;
    int top;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.') {
                count++;
                
                top = 0;
                stackX[top] = i;
                stackY[top] = j;
                top++;
                grid[i][j] = 'o';

                while (top > 0) {
                    top--;
                    int x = stackX[top];
                    int y = stackY[top];

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == '.') {
                            grid[nx][ny] = 'o';
                            stackX[top] = nx;
                            stackY[top] = ny;
                            top++;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
